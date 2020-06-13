/******************************************************************
**					    SAKARYA ÜNİVERSİTESİ
**			   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				   BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				    PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI.......:		1 odev 2inci kısım
**				ÖĞRENCİ ADI.........:			omar alkadri
**				ÖĞRENCİ NUMARASI....:			G171210554
**				DERS GRUBU..........:	  Birinci Öğretim B Grubu
*******************************************************************/

#include<iostream>
#include<string> // string kütüphanesi
#include <iomanip> // switch kütüphanesi
using namespace std;

int main()
{
	string yazi;
	char harifSayisi= '0';
	int counta = 0, counte = 0, counti = 0, counto = 0, countu = 0 ;

	cout << "yazi yaziniz" << endl;
	getline(cin, yazi);// boşluk tan sonrası yazı alması için "getlin" ifadesini kulandık 
	for (int i = 0; i < yazi.size(); i++)//size yazi kadar okuması 
	{
		harifSayisi = tolower(yazi[i]);// kuçuk ve büyuk harifler alması ıçin "tolwer" ifadesini kulandık
		switch (harifSayisi)//eğer "a,e,o,u" hrfi pastisak ekrana kaç kere pasıldına yaz
		{
		case 'a': counta++; break;
		case 'e': counte++; break;
		case 'i': counti++; break;
		case 'o': counto++; break;
		case 'u': countu++; break;
		default: break;
		}
	}
	cout << " hariflar" << setw(16) << " H.S " << "\n";
	cout << "  a is:" << setw(16) << counta << "\n";
	cout << "  e is:" << setw(16) << counte << "\n";
	cout << "  i is:" << setw(16) << counti << "\n";
	cout << "  o is:" << setw(16) << counto << "\n";
	cout << "  u is:" << setw(16) << countu << "\n";

	int maxCount = counta;// burada counta değeri maxCount'a ekle

	if (maxCount < counte)//eğer maxcount counute den küçuk ise counte ye maxcounut ekle 
	{
		maxCount = counte;
	}

	if (maxCount < counti)//eğer maxcount counuti den küçuk ise counti ye maxcounut ekle 
	{
		maxCount = counti;
	}

	if (maxCount < counto)//eğer maxcount counuto den küçuk ise counto ye maxcounut ekle 
	{
		maxCount = counto;
	}

	if (maxCount < countu)//eğer maxcount counutu den küçuk ise countu ye maxcounut ekle 
	{
		maxCount = countu;
	}

	for (int i = 0; i < maxCount; i++)//"i" değişkenlik tanımladık ve eğer i küçuktur maxcount i bir ekle ve pasılan kumut kaç defa yazıldını ekrana çıkart
	{
		cout << i + 1 << " : ";

		if (counta >= i + 1)//eğer "a" büyük eşit i ye i ye kadan "a" sembolu ekrana yaz 
		{
			cout << "a" << " ";
		}
		if (counte >= i + 1)//eğer "e" büyük eşit i ye i ye kadan "e" sembolu ekrana yaz 
		{
			cout << "e" << " ";
		}

		if (counti >= i + 1)//eğer "i" büyük eşit i ye i ye kadan "i" sembolu ekrana yaz 
		{
			cout << "i" << " ";
		}

		if (counto >= i + 1)//eğer "o" büyük eşit i ye i ye kadan "o" sembolu ekrana yaz
		{
			cout << "o" << " ";
		}

		if  (countu >= i + 1)//eğer "u" büyük eşit i ye i ye kadan "u" sembolu ekrana yaz 
		{
			cout << "u" << " ";
		}
		
			cout << endl;

	}
	system("pause");
	return 0;
}