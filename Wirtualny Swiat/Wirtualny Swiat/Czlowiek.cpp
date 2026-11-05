#include "Czlowiek.h"
#include <random>
#include <vector>
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y, Swiat* swiat)
    : Zwierze(5, 4, x, y, swiat),
    kierunek(BRAK),
    umiejetnoscAktywna(false),
    czasUmiejetnosci(0),
    czasOdnawiania(0) {
}

void Czlowiek::akcja() {
    if (kierunek == BRAK) return;

    int dx = 0, dy = 0;
    switch (kierunek) {
    case GORA: dy = -1; break;
    case DOL:  dy = 1;  break;
    case LEWO: dx = -1; break;
    case PRAWO:dx = 1;  break;
    }

    if (umiejetnoscAktywna && czasUmiejetnosci > 2) {
        dx *= 2;
        dy *= 2;
    }

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

    kierunek = BRAK;

    if (umiejetnoscAktywna) {
        czasUmiejetnosci--;
        if (czasUmiejetnosci <= 0) {
            umiejetnoscAktywna = false;
            czasOdnawiania = 5;
        }
    }
    else if (czasOdnawiania > 0) {
        czasOdnawiania--;
    }
}

void Czlowiek::kolizja(Organizm* inny) {
    if (umiejetnoscAktywna && czasUmiejetnosci <= 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        if (std::uniform_int_distribution<>(0, 1)(gen)) {
            const int directions[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
            for (int i = 0; i < 4; ++i) {
                int newX = getPozycja().first + directions[i][0];
                int newY = getPozycja().second + directions[i][1];
                if (getSwiat()->czyWGranicach(newX, newY) && !getSwiat()->znajdzOrganizm(newX, newY)) {
                    setPozycja(newX, newY);
                    return;
                }
            }
        }
    }
    Zwierze::kolizja(inny);
}

void Czlowiek::setKierunek(Kierunek kierunek) {
    this->kierunek = kierunek;
}

void Czlowiek::aktywujUmiejetnosc() {
    if (!umiejetnoscAktywna && czasOdnawiania == 0) {
        umiejetnoscAktywna = true;
        czasUmiejetnosci = 5;
    }
}

bool Czlowiek::getUmiejetnoscAktywna() const {
    return umiejetnoscAktywna;
}

int Czlowiek::getCzasUmiejetnosci() const {
    return czasUmiejetnosci;
}

int Czlowiek::getCzasOdnawiania() const {
    return czasOdnawiania;
}

std::string Czlowiek::getNazwa() const {
    return "Czlowiek";
}

char Czlowiek::getZnak() const {
    return 'H';
}

Organizm* Czlowiek::stworzKopie(int x, int y) const {
    return new Czlowiek(x, y, getSwiat());
}