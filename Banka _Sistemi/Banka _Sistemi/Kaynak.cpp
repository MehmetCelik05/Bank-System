#include<iostream>
#include"BankaBilgileri.h"
#include<list>
#include<cstdlib>
#include<ctime>
using namespace std;



//Kart ekleme ve listelemede problem var

list<BankaBilgileri> *HesapList;
list<Kartlar>* KartList;
unsigned int HesapNo;
string isim;
int KartSayisi = 0;
float Bakiye = 0.0;

void menu();
void HesapBilgileri(list<BankaBilgileri>* lst);
void ParaCekme(list<BankaBilgileri>* lst);
void paraYatirma(list<BankaBilgileri>* lst);
void YeniHesap(list<BankaBilgileri>* lst);
void ListeGoruntuleme(list<BankaBilgileri>* lst);
void ParaTransfer(list<BankaBilgileri>* lst);

int main() {
	HesapList = new list<BankaBilgileri>;
	KartList = new list<Kartlar>;
	menu();
	delete HesapList;
	delete KartList;
}

void menu() {
	int islem=0;
	string soru;
	cout << "Hosgeldiniz;" << endl;
		cout << "Yapmak istediginiz islemi seciniz:" << endl;
		cout << "1)Yeni Hesap Ekleme  2)Para Yatirma  3)Para Cekme  4)Hesap Bilgilerini Gosterme  5)Hesap Listesini Goruntuleme" << endl;
		cout << "6)Para transferi" << endl;
		cout << "Cikis yapmak icin 0 yaziniz" << endl;
		cin >> islem;
		if (islem == 1)
			YeniHesap(HesapList);
		else if (islem == 2)
			paraYatirma(HesapList);
		else if (islem == 3)
			ParaCekme(HesapList);
		else if (islem == 4)
			HesapBilgileri(HesapList);
		else if (islem == 5)
			ListeGoruntuleme(HesapList);
		else if (islem == 6)
			ParaTransfer(HesapList);
		else
			cout << "Hoscakalin..." << endl;
}


void HesapBilgileri(list<BankaBilgileri> *lst) {
	list<BankaBilgileri>::iterator it;
	cout<<"Hesap numaranizi giriniz:"<<endl;
	cin >> HesapNo;
	bool HesapBul=false;
	for (it = lst->begin(); it != lst->end(); ++it) {
		if (HesapNo == it->getHesapNo()) {
			HesapBul = true;
			break;
		}
	}
	if (HesapBul) {
		cout << endl << endl << "Hesap bilgileriniz; " << endl;
		it->BilgileriGoster();
	}
	else
		cout << "hesap bulunamadi." << endl;
	menu();
}

void ParaCekme(list<BankaBilgileri>* lst) {
	int numara;
	int CMiktar;
	cout << "hesabinizin numarasini giriniz: ";
	cin >> numara;
	list<BankaBilgileri>::iterator it;
	for (it = lst->begin(); it != lst->end(); ++it) {
		if (numara == it->getHesapNo()) {
			break;
		}
	}
	if (it != lst->end()) {
		cout << "Cekilecek miktari yaziniz." << endl;
		cin >> CMiktar;
		if (CMiktar <= it->getBakiye()) {
			it->setBakiye(it->getBakiye() - CMiktar);
			cout << "Para cekimi basariyla gerceklesmistir" << endl;
			cout << "Yeni Bakiyeniz: " << it->getBakiye() << endl;
			cout << endl << endl;
		}
		else
			cout << "Hesabinizdaki para miktari cekim icin yetersizdir." << endl;
	}
	else
		cout << "Hesap bulunamadi..." << endl;
	menu();
}

void paraYatirma(list<BankaBilgileri>* lst) {
	int numara;
	unsigned int YMiktar;
	cout << "Hesabinizin numarasini giriniz: ";
	cin >> numara;
	list<BankaBilgileri>::iterator it;
	for (it = lst->begin(); it != lst->end(); ++it) {
		if (numara == it->getHesapNo()) {
			break;
		}
	}
	if (it != lst->end()) {
		cout << "Yatirilacak miktari giriniz:" << endl;
		cin >> YMiktar;
		it->setBakiye(it->getBakiye() + YMiktar);
		cout << "Yeni Bakiyeniz: " << it->getBakiye();
		cout << endl << endl;
	}
		else {
			cout << "Hesap bulunamadi" << endl;
		}
	menu();
}

void YeniHesap(list<BankaBilgileri>* lst) {
	srand(time(NULL));
	HesapNo = rand() % 100 + 1;
	string ad, soyad;
	cout << "Kullanici adi giriniz: " << endl;
	cin >> ad>>soyad;
	isim = ad + " " + soyad;
	if (!isim.empty()) {
		cout << "Hesap numaraniz: " << HesapNo << endl;
		cout << "Bakiyeniz: 0" << endl;
		cout << endl << endl;
	}
	else
		cout << "Hesap ismi girmediniz." << endl;
	BankaBilgileri hesap1(isim, HesapNo,Bakiye);
	lst->push_back(hesap1);
	menu();
} 

void ListeGoruntuleme(list<BankaBilgileri> *lst) {
	list<BankaBilgileri>::iterator it;
	int i = 0;
	for (it = lst->begin(); it != lst->end(); it++) {
		++i;
		cout << i << ")  ";
		it->BilgileriGoster();
	}
	cout << endl << endl;
	menu();
}

void ParaTransfer(list<BankaBilgileri>* lst) {
	unsigned int THesapNo;
	cout << "Para transfer edecek hesabin numarasini giriniz: ";
	cin >> HesapNo;
	bool HesapBul = false;
	list<BankaBilgileri>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (HesapNo == it->getHesapNo()) {
			HesapBul = true;
			break;
		}
	}
	int TMiktar = 0;
	if (HesapBul) {
		cout << "transfer edilecek miktari giriniz: ";
		cin >> TMiktar;
		if (TMiktar <= it->getBakiye()) {
			it->setBakiye(it->getBakiye() - TMiktar);
			it->BilgileriGoster();
			list<BankaBilgileri>::iterator tit;
			cout << "Transfer edilecek hesabin numarasini giriniz: ";
			cin >> THesapNo;
			HesapBul = false;
			for (tit = lst->begin(); tit != lst->end(); tit++) {
				if (THesapNo == tit->getHesapNo()) {
					HesapBul = true;
					break;
				}
			}
			tit->setBakiye(tit->getBakiye() + TMiktar);
			cout << endl << endl;
			tit->BilgileriGoster();
			menu();
		}
		else
			cout << "transfer için yeterli miktarda para yoktur" << endl;
		cout << "Transfer gerceklestirilememistir" << endl;
	}
}