/******************************************************************
**					    SAKARYA ÜNİVERSİTESİ
**			   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				   BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				    PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI.......:		   	  3.odev
**				ÖĞRENCİ ADI.........:			omar alkadri
**				ÖĞRENCİ NUMARASI....:			G171210554
**				DERS GRUBU..........:	  Birinci Öğretim B Grubu
*******************************************************************/
#include<iostream>
#include<stdlib.h>

using namespace std;

const int buyut = 5;

struct islem
{
	int giris[buyut][buyut] = { 3,2,5,1,4,
								6,2,1,0,7,
								3,0,0,2,0,
								1,1,3,2,2,
								0,3,1,0,0 };
};

int cekirdekelemanlari(int i, int j) {

	int cekirdekElemanlari;
	cout << "cekirdek[" << i << "][" << j << "]:";
	cin >> cekirdekElemanlari;
	cout << "\n" << endl;
	return cekirdekElemanlari;

};

int cikisBuyutHisapi(int, int);

int main()
{
	islem yap;
	int cekirdek[5][5];
	int cikis[buyut][buyut];
	int cekirdekBuyutu, kaymaMiktari;
	cout << "cekirdek buyutu giriniz:";
	cin >> cekirdekBuyutu;
	cout << "kayma miktari giriniz:";
	cin >> kaymaMiktari;
	cout << endl;
	int cikisBuyutu = cikisBuyutHisapi(cekirdekBuyutu, kaymaMiktari);

	if ((cekirdekBuyutu <= kaymaMiktari) || (cekirdekBuyutu > buyut) || ((buyut != cekirdekBuyutu) && (kaymaMiktari != 1)))
	{
		cout << "bu islem yapilmaz..." << endl;
	}
	else {
		for (int i = 0; i < cekirdekBuyutu; i++)
		{
			for (int j = 0; j < cekirdekBuyutu; j++)
			{
				cekirdek[i][j] = cekirdekelemanlari(i, j);
			}
		}
/*		for (int i = 0; i < buyut; i++)
		{
			for (int j = 0; j < buyut; j++)
			{
				yap.giris[i][j] = rand() % 10;
				cout << yap.giris[i][j] << "\t";

			}cout << endl;
		}*/	
		for (int i = 0; i < cikisBuyutu; i++)
		{
			for (int j = 0; j < cikisBuyutu; j++)
			{
				int gecici = j;
				int sonuc = 0;
				int satir = i;

				for (int i2 = 0; i2 < cekirdekBuyutu; i2++)
				{
					for (int j2 = 0; j2 < cekirdekBuyutu; j2++)
					{
						sonuc += cekirdek[i2][j2] * (yap.giris[(satir)][(gecici++)]);
					}
					satir += kaymaMiktari;
					gecici = j;
				}
				cout << sonuc << "\t";
			}
			cout << "\n";
		}
	}


	system("pause");
	return 0;
}

int cikisBuyutHisapi(int cekirdekSatvesut, int kaymaMiktar)
{
	if (kaymaMiktar != 0)
	{
		int 	cikisBuyutu = ((buyut - cekirdekSatvesut) / kaymaMiktar) + 1;
		return cikisBuyutu;
	}
	else
		return 1;
}