#include <iostream>
#include "SayilarListesi.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "Basamak.hpp"
#include <fstream> 

/**
* @file main.cpp
* @description main dosya 
* @course A şubesi
* @assignment 1
* @date Kodu 24.11.2023
* @author 
*/



using namespace std;



int main() {
    const char* dosyaAdi = "src/basamakliste.txt";
    ifstream dosya(dosyaAdi);

    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
        return 1;
    }

    int toplamSayi = 0;
    int geciciSayi;
    while (dosya >> geciciSayi) {
        toplamSayi++;
    }

    dosya.clear();
    dosya.seekg(0, std::ios::beg);

    //------------------------------------------------------------------------

    SayilarListesi sayilarListesi;

    for (int i = 0; i < toplamSayi; ++i) {
        dosya >> geciciSayi;

        Sayi yeniSayi;
        yeniSayi.sayiyiIsle(geciciSayi);

        sayilarListesi.anaListeyeElemanEkle(yeniSayi);
    }

    dosya.close();


int secim;

 do {
     sayilarListesi.SayilariYazdir();
        cout<<endl;
        cout << "1. tek basamaklari basa al"<<endl;
        cout << "2.basamaklari tersle"<<endl;
        cout << "3.En Buyuk cikar"<<endl;
        cout << "4. Cikis"<<endl;
        cout << "Seciminizi yapin (1-4): ";
        cin >> secim;
       

        
        switch (secim) {
            case 1:
                sayilarListesi.tekleriBasaTasi();
                break;
            case 2:
                sayilarListesi.basamaklariTersCevir();
                break;
            case 3:
                sayilarListesi.enBuyuguCikar();
                break;
            case 4: 
               cout << "Cikis gerceklestirildi...";
                break;
            default:
                cout << "Gecersiz secim....Lutfen (1-4) araliginda sayi giriniz...:";
        }

    } while (secim != 4); 
return 0;
}
