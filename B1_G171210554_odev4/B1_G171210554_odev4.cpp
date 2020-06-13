/****************************************************************************
**
**						SAKARYA ÜNİVERSİTESİ
**			    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				     PROGRAMLAMAYA GİRİŞİ DERSİ
**
**					  ÖDEV NUMARASI...:Proje
**				 	  ÖĞRENCİ ADI.....:Omar Alkadrı
**					  ÖĞRENCİ NUMARASI:G171210554
**					  DERS GRUBU......:1B
**
****************************************************************************/
#include<iostream>
#include<string>

using namespace std;

class Sifre
{
public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char *sifrele(char*);
	char *sifrecoz(char*);
	void    sifreKelimesiAta(char*);

private:
	char *alfabe;
	char *sifreKelimesi;
};

Sifre::Sifre() {
	alfabe == "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

Sifre::Sifre(char *alfabe, char *sifre_Kelimesi)
{
	alfabe = alfabe;
	sifreKelimesi = sifre_Kelimesi;

}

char *Sifre::sifrele(char* metin)
{
	string a = alfabe;
	int alfabesayi = size(a);
	string b = metin;
	int metinElemanSayi = size(b);
	string c = sifreKelimesi;
	int sifreElemanSayi = size(c);

	char sifra[50][50];
	char sifrele[50] = { 'NULL' };

	for (int i = 0; i < alfabesayi + 1; i++)
	{
		for (int j = 0; j < alfabesayi + 1; j++)
		{
			int a = i + j;
			if (a <= alfabesayi) {
				sifra[i][j] = { ' ' };
			}
			else if (i == 0 && j == 0) {
				sifra[i][j] = alfabe[a - 1];
			}
			else if (a > alfabesayi) {
				a = a - alfabesayi - 1;
				sifra[i][j] = alfabe[a];
			}
		}
	}
	for (int i = 0; i < metinElemanSayi; i++) {
		int f = i;
		if (i >= sifreElemanSayi)
			f = f - ((i / sifreElemanSayi)*(sifreElemanSayi));
		for (int x = 0; x < alfabesayi; x++) {
			if (metin[i] == sifra[0][x]) {
				for (int y = 0; y < alfabesayi; y++) {
					if (sifreKelimesi[f] == sifra[y][0]) {
						sifrele[i] = sifra[y][x];
					}
				}
			}
		}
	}

	return sifrele;
}

char*   Sifre::sifrecoz(char* yenisifre) {


	string a = alfabe;
	int alfabesayi = size(a);
	string b = yenisifre;
	int yenisifreElemanSayi = size(b);
	string c = sifreKelimesi;
	int sifreElemanSayi = size(c);

	char sifra[50][50];
	char sifrecoz[50] = { 'NULL' };


	for (int i = 0; i < alfabesayi + 1; i++)
	{
		for (int j = 0; j < alfabesayi + 1; j++)
		{
			int a = i + j;
			if (i == 0 && j == 0) {
				sifra[i][j] = { ' ' };
			}
			else if (a <= alfabesayi) {
				sifra[i][j] = alfabe[a - 1];
			}
			else if (a > alfabesayi) {
				a = a - alfabesayi - 1;
				sifra[i][j] = alfabe[a];
			}
		}
	}

	for (int i = 0; i < yenisifreElemanSayi; i++) {
		int f = i;
		if (i >= sifreElemanSayi)
			f = f - ((i / sifreElemanSayi)*(sifreElemanSayi));
		for (int x = 0; x < alfabesayi; x++) {
			if (sifreKelimesi[f] == sifra[x][0]) {
				for (int y = 0; y < alfabesayi; y++) {
					if (yenisifre[i] == sifra[y][x]) {
						sifrecoz[i] = sifra[y][0];
					}
				}
			}
		}
	}
	return sifrecoz;
}

void Sifre::sifreKelimesiAta(char *)
{
}
void goster() {
	char alfabe1[50];
	char sifre[50], sifreKelimesi[50], metin[50];
	cout << "ALFABE        :";
	cin >> alfabe1;
	cout << "SIFRE         :";
	cin >> sifre;
	cout << "METIN         :";
	cin >> metin;
	Sifre sifre1(alfabe1, sifre);
	char *yeniSifre = sifre1.sifrele(metin);
	cout << "SIFRELENMIS   :" << yeniSifre << endl;

	string a = sifre1.sifrele(metin);
	char aa[50] = { 'NULL' };
	for (int i = 0; i < size(a); i++) {
		aa[i] = a[i];
	}

	cout << "DESIFREMETIN  :" << sifre1.sifrecoz(aa) << endl;
}
int main()
{
	goster();

	system("pause");
	return 0;
}

