#include "Zwierze.h"
#include <random>
#include <utility>
#include <iostream>
#include <typeinfo>
#include "Swiat.h"

Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, Swiat* swiat)
    : Organizm(sila, inicjatywa, x, y, swiat) {
}
bool Zwierze::czyUcieka(Organizm* atakujacy) {
    return false;
}
void Zwierze::akcja() {
    poprzedniaPozycja = pozycja;
    const int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    int dx = directions[dis(gen)][0];
    int dy = directions[dis(gen)][1];
    ruch(dx, dy);
}

void Zwierze::kolizja(Organizm* inny) {
    // 1. SprawdŸ czy to ten sam gatunek (rozmna¿anie)
    if (typeid(*this) == typeid(*inny)) {
        if (this->wiek >= 15 && inny->getWiek() >= 15) {
            rozmnazanie(inny);
        }
        return;
    }

    // 2. SprawdŸ specjalne mechaniki obronne
    if (inny->czyOdbilAtak(this)) {
        cofnijRuch();
        return;
    }

    if (czyUcieka(inny)) {
        return;
    }

    // 3. Standardowa walka
    if (sila >= inny->getSila()) {
        swiat->usunOrganizm(inny);
    }
    else {
        swiat->usunOrganizm(this);
    }
}

bool Zwierze::czyMozliweRozmnozenie(int x, int y) const {
    const int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    for (int i = 0; i < 4; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (swiat->czyWGranicach(newX, newY)) {
            if (swiat->znajdzOrganizm(newX, newY) == nullptr) {
                return true;
            }
        }
    }
    return false;
}

void Zwierze::rozmnazanie(Organizm* partner) {
    if (!czyMozliweRozmnozenie(pozycja.first, pozycja.second)) return;

    const int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
    std::vector<std::pair<int, int>> wolnePola;

    for (int i = 0; i < 4; ++i) {
        int newX = pozycja.first + directions[i][0];
        int newY = pozycja.second + directions[i][1];

        if (swiat->czyWGranicach(newX, newY)) {
            if (swiat->znajdzOrganizm(newX, newY) == nullptr) {
                wolnePola.push_back(std::make_pair(newX, newY));
            }
        }
    }

    if (!wolnePola.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, wolnePola.size() - 1);
        int wybrany = dis(gen);
        int x = wolnePola[wybrany].first;
        int y = wolnePola[wybrany].second;
        swiat->dodajOrganizm(stworzKopie(x, y));
    }
}

void Zwierze::rysowanie() const {
    std::cout << getZnak();
}

void Zwierze::ruch(int dx, int dy) {
    int newX = pozycja.first + dx;
    int newY = pozycja.second + dy;

    if (swiat->czyWGranicach(newX, newY)) {
        Organizm* org = swiat->znajdzOrganizm(newX, newY);
        if (org == nullptr) {
            pozycja.first = newX;
            pozycja.second = newY;
        }
        else {
            org->kolizja(this);
        }
    }
}