/******************************************************************
**					    SAKARYA ÜNİVERSİTESİ
**			   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				   BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				    PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI.......:		1 odev 1inci kısım
**				ÖĞRENCİ ADI.........:			omar alkadri
**				ÖĞRENCİ NUMARASI....:			G171210554
**				DERS GRUBU..........:	  Birinci Öğretim B Grubu
*******************************************************************/
#include <iostream>
using namespace std;

int main()
{
	int satirSayisi = 0, sutunSayirsi = 0;

	for (satirSayisi = 1; satirSayisi <= 11; satirSayisi++)//sarırlar için satirSayisi=1 ve satirSayisi<=11 ve 1 artar 
	{

		for (sutunSayirsi = 1; sutunSayirsi <= 11; sutunSayirsi++)//sütunlar için sutunSayirsi=1 ve sutunSayirsi<= ve 1 artar  
		{

			if ((satirSayisi == 1 || satirSayisi == 11) && (sutunSayirsi== 6) //eğer satirSayisi=1 le 11 ve sutunSayirsi= 6 bu işlemi yap ve devam et değyer işlemler bunun gibi
				|| (satirSayisi == 2 || satirSayisi == 10) &&(sutunSayirsi>= 5 && sutunSayirsi <= 7) 
				|| (satirSayisi == 3 || satirSayisi == 9) && (sutunSayirsi>= 4 && sutunSayirsi <= 8)
				|| (satirSayisi == 4 || satirSayisi == 8) && (sutunSayirsi>= 3 && sutunSayirsi <= 9)
				|| (satirSayisi == 5 || satirSayisi == 7) && (sutunSayirsi>= 2 && sutunSayirsi <= 10)
				|| (satirSayisi == 6) && (sutunSayirsi >= 1 && sutunSayirsi <= 11)
				)
			{
				cout << "   ";
			}
			else
				cout << "*  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}