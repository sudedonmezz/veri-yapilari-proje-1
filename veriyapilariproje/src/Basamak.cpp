#include "Basamak.hpp"
#include <iostream>

/**
* @file Basamak.cpp
* @description sayıların basamaklarını tutan düğüm sınıfı
* @course A şubesi
* @assignment 1
* @date Kodu 9.11.2023
* @author 
*/



using namespace std;

Basamak::Basamak(int deger) {
	this->veri=deger;
	this->sonraki=nullptr;
}
ostream& operator<<(ostream& os, const Basamak& basamak) {
    os << basamak.veri;
    return os;
}

Basamak::~Basamak() {
    delete sonraki;
}