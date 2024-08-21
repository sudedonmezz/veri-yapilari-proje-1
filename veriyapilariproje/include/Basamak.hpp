#ifndef BASAMAK_HPP
#define BASAMAK_HPP
#include <iostream>

/**
* @file Basamak.hpp
* @description sayıların basamaklarını tutan düğüm sınıfı
* @course A şubesi
* @assignment 1
* @date Kodu 9.11.2023
* @author 
*/
using namespace std;

class Basamak {
public:
    int veri;
    Basamak* sonraki;
    Basamak(int deger);
    friend ostream& operator<<(ostream& os, const Basamak& basamak);
    ~Basamak();
};

#endif