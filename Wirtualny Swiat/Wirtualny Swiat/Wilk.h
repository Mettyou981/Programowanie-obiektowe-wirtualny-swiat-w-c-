#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(int x, int y, Swiat* swiat);
    ~Wilk() = default;

    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;  // Wymagane przez klasê Zwierze
};