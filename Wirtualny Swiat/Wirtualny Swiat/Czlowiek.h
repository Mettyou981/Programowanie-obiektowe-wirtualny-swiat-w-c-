#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
    enum Kierunek { BRAK, GORA, DOL, LEWO, PRAWO };

private:
    Kierunek kierunek;
    bool umiejetnoscAktywna;
    int czasUmiejetnosci;
    int czasOdnawiania;

public:
    Czlowiek(int x, int y, Swiat* swiat);
    ~Czlowiek() = default;

    void akcja() override;
    void kolizja(Organizm* inny) override;
    std::string getNazwa() const override;
    char getZnak() const override;
    Organizm* stworzKopie(int x, int y) const override;

    // Sterowanie
    void setKierunek(Kierunek kierunek);  // Zmieniono z ustawKierunek
    void aktywujUmiejetnosc();
    bool getUmiejetnoscAktywna() const;  // Zmieniono z czyUmiejetnoscAktywna
    int getCzasUmiejetnosci() const;
    int getCzasOdnawiania() const;
};