#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(int sila, int inicjatywa, int x, int y, Swiat* swiat)
    : sila(sila), inicjatywa(inicjatywa), pozycja(x, y), wiek(0), swiat(swiat) {
    if (swiat == nullptr) {
        throw std::invalid_argument("Swiat nie moze byc nullptr");
    }
}

int Organizm::getSila() const {
    return sila;
}
int Organizm::getInicjatywa() const {
    return inicjatywa;
}

int Organizm::getWiek() const {
    return wiek;
}

std::pair<int, int> Organizm::getPozycja() const {
    return pozycja;
}

Swiat* Organizm::getSwiat() const {
    return swiat;
}

void Organizm::setPozycja(int x, int y) {
    if (x < 0 || y < 0) {
        throw std::invalid_argument("Pozycja nie moze byc ujemna");
    }
    pozycja = { x, y };
}

void Organizm::setSila(int sila) {
    if (sila < 0) {
        throw std::invalid_argument("Sila nie moze byc ujemna");
    }
    this->sila = sila;
}
void Organizm::cofnijRuch() {
    pozycja = poprzedniaPozycja; // Przywracamy poprzedni¹ pozycjê
}
void Organizm::postarz() {
    wiek++;
}

bool Organizm::czyOdbilAtak(Organizm* atakujacy) const {
    return false;
}

bool Organizm::czyUciekl() const {
    return false;
}

bool Organizm::czyZasieg() const {
    return false;
}

bool Organizm::czyUmnoroz() const {
    return true;
}