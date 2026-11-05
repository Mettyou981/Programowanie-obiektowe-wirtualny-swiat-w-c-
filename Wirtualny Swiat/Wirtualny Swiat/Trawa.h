#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
public:
    Trawa(int x, int y, Swiat* swiat);
    ~Trawa() = default;

    // Implementacja wymaganych metod wirtualnych
    char getZnak() const override;
    void rysowanie() const override;
    std::string getNazwa() const override;
    Organizm* stworzKopie(int x, int y) const override;
};