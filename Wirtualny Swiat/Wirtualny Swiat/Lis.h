#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis(int x, int y, Swiat* swiat);
    ~Lis() = default;

    void akcja() override;
    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;
};