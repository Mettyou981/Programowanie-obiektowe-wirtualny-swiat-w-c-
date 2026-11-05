#include "Antylopa.h"
#include <random>
#include <vector>
#include "Swiat.h"
#include "Zwierze.h"
Antylopa::Antylopa(int x, int y, Swiat* swiat)
    : Zwierze(4, 4, x, y, swiat) {
}

void Antylopa::akcja() {
    const std::vector<std::pair<int, int>> mozliweRuchy = {
        {0, -2}, {0, 2}, {-2, 0}, {2, 0},
        {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, mozliweRuchy.size() - 1);

    int dx = mozliweRuchy[dis(gen)].first;
    int dy = mozliweRuchy[dis(gen)].second;

    int newX = getPozycja().first + dx;
    int newY = getPozycja().second + dy;

    if (getSwiat()->czyWGranicach(newX, newY)) {
        if (Organizm* org = getSwiat()->znajdzOrganizm(newX, newY)) {
            org->kolizja(this);
        }
        else {
            setPozycja(newX, newY);
        }
    }
}

bool Antylopa::czyUcieka(Organizm* atakujacy) {
    std::random_device rd;
    std::mt19937 gen(rd());
    if (std::uniform_int_distribution<>(0, 1)(gen)) {
        const std::vector<std::pair<int, int>> sasiedzi = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        };

        for (const auto& ruch : sasiedzi) {
            int x = getPozycja().first + ruch.first;
            int y = getPozycja().second + ruch.second;

            if (getSwiat()->czyWGranicach(x, y) && !getSwiat()->znajdzOrganizm(x, y)) {
                setPozycja(x, y);
                return true;
            }
        }
    }
    return false;
}

std::string Antylopa::getNazwa() const {
    return "Antylopa";
}

char Antylopa::getZnak() const {
    return 'A';
}

Organizm* Antylopa::stworzKopie(int x, int y) const {
    return new Antylopa(x, y, getSwiat());
}