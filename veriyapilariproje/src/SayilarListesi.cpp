#include "SayilarListesi.hpp"
#include <iostream>
#include <iomanip>
#include "Sayi.hpp"
#include "Basamak.hpp"

/**
* @file SayilarListesi.cpp
* @description Dugum adlı dugum sınıfının baglı listesi
* @course A şubesi
* @assignment 1
* @date Kodu 21.11.2023
* @author 
*/



using namespace std;

SayilarListesi::SayilarListesi() {
 bas=nullptr;
 }

SayilarListesi::~SayilarListesi() {
    delete bas;
}

void SayilarListesi::anaListeyeElemanEkle(Sayi& yeniSayi) {
    Dugum* yeniDugum = new Dugum();
    yeniDugum->sayi = yeniSayi;

    if (bas == nullptr) {
        bas = yeniDugum;
    } else {
        Dugum* simdikiDugum = bas;
        while (simdikiDugum->sonrakiDugum != nullptr) {
            simdikiDugum = simdikiDugum->sonrakiDugum;
        }
        simdikiDugum->sonrakiDugum = yeniDugum;
    }
}

void SayilarListesi::anaListeyiYazdir() {
     Dugum* simdikiDugum = bas;
    while (simdikiDugum != nullptr) {
        simdikiDugum->sayi.listeYazdir();
        simdikiDugum = simdikiDugum->sonrakiDugum;
    }
}

void SayilarListesi::SayilariYazdir()
{
    Dugum* simdikiDugum =bas;
 
    int indeks = 1;
    while (simdikiDugum != nullptr) {
        
        cout<<endl<<"##########"<<endl<<endl;
       
        cout <<simdikiDugum<<endl<<"--------";
        cout<<endl<<simdikiDugum->sayi<<endl<<"##########";
        simdikiDugum->sayi.listeYazdir();  
        simdikiDugum = simdikiDugum->sonrakiDugum;
        indeks++;
    }

  
	
}
void SayilarListesi::tekleriBasaTasi()
{
    Dugum* simdikiDugum = bas;

    while (simdikiDugum != nullptr) {
        simdikiDugum->sayi.tekleriBasaTasi();  
        simdikiDugum = simdikiDugum->sonrakiDugum;
    }
}

void SayilarListesi::basamaklariTersCevir() {
    Dugum* simdikiDugum = bas;

    while (simdikiDugum != nullptr) {
        simdikiDugum->sayi.basamaklariTersCevir();
        simdikiDugum = simdikiDugum->sonrakiDugum;
    }
}

void SayilarListesi::enBuyuguCikar() {
    if (bas == nullptr) {
        cerr << "Liste bos. En buyuk eleman cikartilamaz." << endl;
        return;
    }

    Dugum* simdikiDugum = bas;
    Dugum* oncekiDugum = nullptr;
    Dugum* enBuyukDugum = bas;
    Dugum* oncekiEnBuyukDugum = nullptr;

    while (simdikiDugum != nullptr) {
        if (simdikiDugum->sayi > enBuyukDugum->sayi) {
            enBuyukDugum = simdikiDugum;
            oncekiEnBuyukDugum = oncekiDugum;
        }

        oncekiDugum = simdikiDugum;
        simdikiDugum = simdikiDugum->sonrakiDugum;
    }

    if (oncekiEnBuyukDugum == nullptr) {
       
        bas = enBuyukDugum->sonrakiDugum;
    } else {
        
        oncekiEnBuyukDugum->sonrakiDugum = enBuyukDugum->sonrakiDugum;
    }

    delete enBuyukDugum;
}