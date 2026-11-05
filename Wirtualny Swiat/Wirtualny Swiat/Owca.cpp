#include "Owca.h"

Owca::Owca(int x, int y, Swiat* swiat)
    : Zwierze(4, 4, x, y, swiat) {
}  // Si³a = 4, inicjatywa = 4

std::string Owca::getNazwa() const {
    return "Owca";
}

char Owca::getZnak() const {
    return 'O';
}

Organizm* Owca::stworzKopie(int x, int y) const {
    return new Owca(x, y, swiat);  // Tworzy now¹ owcê na pozycji (x, y)
}