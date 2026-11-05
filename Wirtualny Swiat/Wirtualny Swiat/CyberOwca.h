#pragma once
#include "Zwierze.h"

class CyberOwca : public Zwierze {
public:
    CyberOwca(int x, int y, Swiat* swiat);
    ~CyberOwca() = default;

    void akcja() override;
    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;
};