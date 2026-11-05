#include "Wilk.h"

Wilk::Wilk(int x, int y, Swiat* swiat)
    : Zwierze(9, 5, x, y, swiat) {
}

std::string Wilk::getNazwa() const {
    return "Wilk";
}

char Wilk::getZnak() const {
    return 'W';
}

Organizm* Wilk::stworzKopie(int x, int y) const {
    return new Wilk(x, y, swiat);  // Tworzy nowego wilka na pozycji (x, y)
}