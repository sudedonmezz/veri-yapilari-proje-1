#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"
/**
* @file Sayi.hpp
* @description Basamak adlı dugum sınıfının baglı listesi
* @course A şubesi
* @assignment 1
* @date Kodu 11.11.2023
* @author 
*/

using namespace std;
class Sayi
{
	public:
	Basamak* liste;
	Sayi();
	void rakamEkle(int rakam);
    void sayiyiIsle(int deger);
    void listeYazdir();
    void tekleriBasaTasi();
    void basamaklariTersCevir();
    friend ostream& operator<<(ostream& os, const Sayi& sayi);
    bool operator>(const Sayi& digerSayi) const;
    bool operator<(const Sayi& digerSayi) const;
    bool operator==(const Sayi& digerSayi) const;
};


#endif