#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(int x, int y, Swiat* swiat);
    ~Owca() = default;

    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override; // Wymagane przez klasê Zwierze
};