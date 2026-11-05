#include "Zolw.h"
#include <random>

Zolw::Zolw(int x, int y, Swiat* swiat)
    : Zwierze(2, 1, x, y, swiat) {
}

void Zolw::akcja() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    if (dis(gen) == 0) { // 25% szans na ruch
        Zwierze::akcja();
    }
}

bool Zolw::odbijAtak(Organizm* atakujacy) const {
    if (atakujacy->getSila() < 5) {
        // Atakuj¹cy musi zapisaæ swoj¹ pozycjê PRZED atakiem
        // (to powinno byæ zrobione w jego metodzie akcja())
        atakujacy->cofnijRuch(); // Teraz cofamy atakuj¹cego
        return true;
    }
    return false;
}

std::string Zolw::getNazwa() const {
    return "Zolw";
}

char Zolw::getZnak() const {
    return 'Z';
}

Organizm* Zolw::stworzKopie(int x, int y) const {
    return new Zolw(x, y, getSwiat());
}