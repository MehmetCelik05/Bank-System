#pragma once
#include<iostream>
#include"Kartlar.h"
#include<list>
using namespace std;

class BankaBilgileri {
private:
	string HesapAdi;
	int HesapNo;
	float Bakiye;

public:
	BankaBilgileri(string _HesapAdi, int _HesapNo,float _Bakiye);
	void BilgileriGoster();

	void setHesapNo(int _HesapNo);
	int getHesapNo();

	void setHesapAdi(string _HesapAdi);
	string getHesapAdi();

	void setBakiye(float _Bakiye);
	float getBakiye();
};