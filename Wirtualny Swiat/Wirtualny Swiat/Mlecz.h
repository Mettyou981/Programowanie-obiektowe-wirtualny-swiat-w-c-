#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(int x, int y, Swiat* swiat);

    // Wymagane metody
    char getZnak() const override; // Dodajemy brakuj¹c¹ metodê
    void rysowanie() const override;
    std::string getNazwa() const override;
    Organizm* stworzKopie(int x, int y) const override;

    void akcja() override;
};