#include "BankaBilgileri.h"

	BankaBilgileri::BankaBilgileri(string _HesapAdi, int _HesapNo,float _Bakiye) {
		HesapAdi= _HesapAdi;
		HesapNo = _HesapNo;
		Bakiye = _Bakiye;
	}

	void BankaBilgileri::BilgileriGoster() {
		cout << "Kullanici adi: " << HesapAdi<<endl;
		cout << "Hesap Numarasi: " << HesapNo << endl;
		cout << "Hesap Bakiyesi: " << Bakiye << endl;
		cout << endl << endl;
	}

	void BankaBilgileri::setHesapNo(int _HesapNo) {
		HesapNo = _HesapNo;
	}
	int BankaBilgileri::getHesapNo() {
		return HesapNo;
	}

	void BankaBilgileri::setHesapAdi(string _HesapAdi) {
		_HesapAdi = HesapAdi;
	}
	string BankaBilgileri::getHesapAdi() {
		return HesapAdi;
	}

	void BankaBilgileri::setBakiye(float _Bakiye) {
		Bakiye = _Bakiye;
	}
	float BankaBilgileri::getBakiye() {
		return Bakiye;
	}
