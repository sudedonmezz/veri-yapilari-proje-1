#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
#include "Basamak.hpp"


/**
* @file Sayi.cpp
* @description Basamak adlı dugum sınıfının baglı listesi
* @course A şubesi
* @assignment 1
* @date Kodu 11.11.2023
* @author 
*/

using namespace std;

Sayi::Sayi() {
	liste=nullptr;
	}

void Sayi::rakamEkle(int rakam) {
    Basamak* yeniBasamak = new Basamak(rakam);
    yeniBasamak->sonraki = liste;
    liste = yeniBasamak;
}

void Sayi::sayiyiIsle(int deger) {
    while (deger > 0) {
    int rakam = deger % 10;
    rakamEkle(rakam);
    deger /= 10;
    }
}
	void Sayi::listeYazdir() {
    Basamak* gec = liste;
   while (gec != nullptr) {
  
        cout<<endl << hex << reinterpret_cast<uintptr_t>(gec) % 1000 << dec <<"-----"<< gec->veri << endl;
        gec = gec->sonraki;
					
    }
}

void Sayi::tekleriBasaTasi() {
     if (liste == nullptr || liste->sonraki == nullptr) {
        return;
    }

    Basamak* simdiki = liste;
    Basamak* onceki = nullptr;
    Basamak* teklerBas = nullptr;
    Basamak* teklerSon = nullptr;

    while (simdiki != nullptr) {
        if (simdiki->veri % 2 == 1) {
            if (onceki == nullptr) {
                liste = simdiki->sonraki;
            } else {
                onceki->sonraki = simdiki->sonraki;
            }

            if (teklerBas == nullptr) {
                teklerBas = teklerSon = simdiki;
                simdiki->sonraki = nullptr;
            } else {
                teklerSon->sonraki = simdiki;
                teklerSon = simdiki;
                simdiki->sonraki = nullptr;
            }

            simdiki = onceki == nullptr ? liste : onceki->sonraki;
        } else {
            onceki = simdiki;
            simdiki = simdiki->sonraki;
        }
    }

    if (teklerBas != nullptr) {
        teklerSon->sonraki = liste;
        liste = teklerBas;
    }
}

void Sayi::basamaklariTersCevir() {
    Basamak* simdiki = liste;
    Basamak* onceki = nullptr;
    Basamak* sonraki = nullptr;

    while (simdiki != nullptr) {
        sonraki = simdiki->sonraki;
        simdiki->sonraki = onceki;
        onceki = simdiki;
        simdiki = sonraki;
    }

    liste = onceki;
}

ostream& operator<<(std::ostream& os, const Sayi& sayi) {
    Basamak* gec = sayi.liste;
    while (gec != nullptr) {
        os << gec->veri << " ";
        gec = gec->sonraki;
    }
    return os;

}

//karsilastirma operatorlerini tanımladım.

bool Sayi::operator>(const Sayi& digerSayi) const {
    
    int toplamBasamak1 = 0;
    int toplamBasamak2 = 0;

    Basamak* gec1 = liste;
    while (gec1 != nullptr) {
        toplamBasamak1++;
        gec1 = gec1->sonraki;
    }

    Basamak* gec2 = digerSayi.liste;
    while (gec2 != nullptr) {
        toplamBasamak2++;
        gec2 = gec2->sonraki;
    }

    return toplamBasamak1 > toplamBasamak2;
}

bool Sayi::operator<(const Sayi& digerSayi) const {
    
    int toplamBasamak1 = 0;
    int toplamBasamak2 = 0;

    Basamak* gec1 = liste;
    while (gec1 != nullptr) {
        toplamBasamak1++;
        gec1 = gec1->sonraki;
    }

    Basamak* gec2 = digerSayi.liste;
    while (gec2 != nullptr) {
        toplamBasamak2++;
        gec2 = gec2->sonraki;
    }

    return toplamBasamak1 < toplamBasamak2;
}

bool Sayi::operator==(const Sayi& digerSayi) const {
   
    int toplamBasamak1 = 0;
    int toplamBasamak2 = 0;

    Basamak* gec1 = liste;
    while (gec1 != nullptr) {
        toplamBasamak1++;
        gec1 = gec1->sonraki;
    }

    Basamak* gec2 = digerSayi.liste;
    while (gec2 != nullptr) {
        toplamBasamak2++;
        gec2 = gec2->sonraki;
    }

    return toplamBasamak1 == toplamBasamak2;
}
