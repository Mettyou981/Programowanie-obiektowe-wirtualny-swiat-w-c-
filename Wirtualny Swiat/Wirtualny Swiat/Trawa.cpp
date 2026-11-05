#include "Trawa.h"
#include <iostream>

Trawa::Trawa(int x, int y, Swiat* swiat)
    : Roslina(0, x, y, swiat, 0.2) {
} // 20% szans na rozsianie

char Trawa::getZnak() const {
    return 't'; // Ma³a litera zgodnie z konwencj¹
}

void Trawa::rysowanie() const {
    std::cout << getZnak(); // Spójne wyœwietlanie
}

std::string Trawa::getNazwa() const {
    return "Trawa";
}

Organizm* Trawa::stworzKopie(int x, int y) const {
    return new Trawa(x, y, getSwiat());
}