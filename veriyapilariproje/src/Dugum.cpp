#include "Dugum.hpp"

/**
* @file Dugum.cpp
* @description Sayı bağlı listesini tutan düğüm sınıfı
* @course A şubesi
* @assignment 1
* @date Kodu 11.11.2023
* @author 
*/


Dugum::Dugum() {
	sonrakiDugum=nullptr;
	}
	
Dugum::~Dugum() {
    delete sonrakiDugum;
	}