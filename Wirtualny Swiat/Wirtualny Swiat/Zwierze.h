#pragma once
#include "Organizm.h"
class Swiat;

class Zwierze : public Organizm {
protected:
    virtual void rozmnazanie(Organizm* partner);
    virtual bool czyMozliweRozmnozenie(int x, int y) const;
    virtual Organizm* stworzKopie(int x, int y) const = 0;
    virtual bool czyUcieka(Organizm* atakujacy);// Dodana metoda wirtualna
    virtual bool odbijAtak(Organizm* atakujacy) const { return false; }

public:
    Zwierze(int sila, int inicjatywa, int x, int y, Swiat* swiat);
    virtual ~Zwierze() = default;

    void akcja() override;
    void kolizja(Organizm* inny) override;
    void rysowanie() const override;

protected:
    void ruch(int dx, int dy);
};