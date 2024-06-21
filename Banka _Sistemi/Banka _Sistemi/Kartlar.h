#pragma once
#include<iostream>
using namespace std;

class Kartlar
{
private:
	string isim;
	int KBakiye;
	int KartNo;
	int Sifre;
public:
	Kartlar(string _isim,int _KBakiye,int _KartNo,int _Sifre);
	void KBilgileriGoster();

	void setIsim(string _isim);
	string getIsim();

	void setKartNo(int _KartNo);
	int getKartNo();

	void setBakiye(int _KBakiye);
	int getBakiye();

	void setSifre(int _sifre);
	int getSifre();
};