#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

/**
* @file Dugum.hpp
* @description Sayı bağlı listesini tutan düğüm sınıfı
* @course A şubesi
* @assignment 1
* @date Kodu 11.11.2023
* @author 
*/

class Dugum {
public:
    Sayi sayi;
    Dugum* sonrakiDugum;
    Dugum();
   ~Dugum();
   
};

#endif