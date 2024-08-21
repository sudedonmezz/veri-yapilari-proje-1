#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"

/**
* @file SayilarListesi.hpp
* @description Dugum adlı dugum sınıfının baglı listesi
* @course A şubesi
* @assignment 1
* @date Kodu 21.11.2023
* @author 
*/

class SayilarListesi {
public:
    Dugum* bas;
    SayilarListesi();
	~SayilarListesi();
    void anaListeyeElemanEkle(Sayi& yeniSayi);
    void anaListeyiYazdir();
    void SayilariYazdir();
   void tekleriBasaTasi();
   void basamaklariTersCevir();
   void enBuyuguCikar();
};

#endif