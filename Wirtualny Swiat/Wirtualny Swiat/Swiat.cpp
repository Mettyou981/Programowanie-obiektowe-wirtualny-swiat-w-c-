#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "CyberOwca.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <conio.h>
#include <cstdlib>

Swiat::Swiat(int szerokosc, int wysokosc)
    : szerokosc(szerokosc), wysokosc(wysokosc), tura(0), czlowiek(nullptr) {
}

Swiat::~Swiat() {
    for (auto org : organizmy) {
        delete org;
    }
}

void Swiat::sortujOrganizmy() {
    std::sort(organizmy.begin(), organizmy.end(), [](Organizm* a, Organizm* b) {
        if (a->getInicjatywa() == b->getInicjatywa()) {
            return a->getWiek() > b->getWiek();
        }
        return a->getInicjatywa() > b->getInicjatywa();
        });
}

void Swiat::losujPozycje(int& x, int& y) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distX(0, szerokosc - 1);
    std::uniform_int_distribution<> distY(0, wysokosc - 1);

    do {
        x = distX(gen);
        y = distY(gen);
    } while (!czyWolnePole(x, y));
}

void Swiat::wykonajTure() {
    sortujOrganizmy();
    std::vector<Organizm*> kopiaOrganizmow = organizmy;

    // 1) Najpierw wykonaj akcje tylko dla żywych organizmów
    for (Organizm* org : kopiaOrganizmow) {
        auto it = std::find(organizmy.begin(), organizmy.end(), org);
        if (it != organizmy.end()) {
            org->akcja();
        }
    }

    // 2) Potem postarzenie tylko tych, którzy wciąż są w wektorze
    for (Organizm* org : kopiaOrganizmow) {
        auto it = std::find(organizmy.begin(), organizmy.end(), org);
        if (it != organizmy.end()) {
            org->postarz();
        }
    }

    tura++;
}

void Swiat::rysujSwiat() const {
    system("cls");
    std::cout << "Wirtualny Swiat - Autor: [Mateusz Pabich,s203802]\n";
    std::cout << "Tura: " << tura << "\n";

    if (czlowiek) {
        std::cout << "Specjalna umiejetnosc: "
            << (czlowiek->getUmiejetnoscAktywna() ? "AKTYWNA" : "NIEAKTYWNA")
            << "\n\n";
    }

    for (int y = 0; y < wysokosc; y++) {
        for (int x = 0; x < szerokosc; x++) {
            if (Organizm* org = znajdzOrganizm(x, y)) {
                org->rysowanie();
            }
            else {
                std::cout << '.';
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void Swiat::wyczyscZdarzenia() {
    zdarzenia.clear();
}

void Swiat::inicjalizujSwiat() {
    int x, y;

    // Człowiek zawsze w środku
    czlowiek = new Czlowiek(szerokosc / 2, wysokosc / 2, this);
    dodajOrganizm(czlowiek);

    // Losowe pozycje dla organizmów — brak kolizji
    losujPozycje(x, y); dodajOrganizm(new Wilk(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Owca(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Lis(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Zolw(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Antylopa(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new CyberOwca(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Trawa(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Mlecz(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new Guarana(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new WilczeJagody(x, y, this));
    losujPozycje(x, y); dodajOrganizm(new BarszczSosnowskiego(x, y, this));
}

void Swiat::dodajOrganizm(Organizm* organizm) {
    if (!organizm) return;

    auto pos = organizm->getPozycja();
    if (!czyWGranicach(pos.first, pos.second)) {
        delete organizm;
        return;
    }

    if (Organizm* existing = znajdzOrganizm(pos.first, pos.second)) {
        existing->kolizja(organizm);
        // jeśli po kolizji pozycja się nie zmieniła — obiekt „zginął”
        if (organizm->getPozycja() == pos) {
            delete organizm;
            return;    // ← ważne: kończymy, nie korzystamy już z organizm
        }
        // inaczej: organizm przeżył i możemy go dodać
    }

    organizmy.push_back(organizm);

    if (auto c = dynamic_cast<Czlowiek*>(organizm)) {
        czlowiek = c;
    }
}
void Swiat::usunOrganizm(Organizm* organizm) {
    auto it = std::find(organizmy.begin(), organizmy.end(), organizm);
    if (it != organizmy.end()) {
        if (*it == czlowiek) {
            czlowiek = nullptr;
        }
        delete* it;
        organizmy.erase(it);
    }
}

Organizm* Swiat::znajdzOrganizm(int x, int y) const {
    for (auto org : organizmy) {
        auto pos = org->getPozycja();
        if (pos.first == x && pos.second == y) {
            return org;
        }
    }
    return nullptr;
}

bool Swiat::czyWGranicach(int x, int y) const {
    return x >= 0 && x < szerokosc && y >= 0 && y < wysokosc;
}

bool Swiat::czyWolnePole(int x, int y) const {
    return czyWGranicach(x, y) && !znajdzOrganizm(x, y);
}

void Swiat::dodajZdarzenie(const std::string& zdarzenie) {
    zdarzenia.push_back(zdarzenie);
}