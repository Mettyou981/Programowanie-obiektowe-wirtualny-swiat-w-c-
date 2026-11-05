#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(int x, int y, Swiat* swiat);

    // Wymagane metody wirtualne
    void kolizja(Organizm* inny) override;
    char getZnak() const override;
    void rysowanie() const override;
    std::string getNazwa() const override;
    Organizm* stworzKopie(int x, int y) const override;
};