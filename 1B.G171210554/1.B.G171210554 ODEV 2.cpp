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
#include <time.h>

using namespace std;
int i, j;
void rasgele(char matris[5][10])
{
	srand(time(NULL));//rasgele olmasi icin kulanilir

	for (i = 0; i < 5; i++)
	{
		cout << endl;
		for (j = 0; j < 10; j++)
		{
			char rasgeleHarf;
			bool benzersiz; //tekrar yapilmamak icin kulandik
			do
			{
				benzersiz = true;
				rasgeleHarf = (rand() % ('Z' - 'A') + 'A');//rasgele harf yapilmak icin
				if ((i <= 4) && (j % 2 != 0))
				{
					rasgeleHarf = towlower(rasgeleHarf);//buyuk harf kucu degistirmek
				}
				for (int i2 = 0; i2 < 5; i2++)
				{
					for (int j2 = 0; j2 < 10; j2++)
					{
						if (rasgeleHarf == matris[i2][j2])// ikisinde esit ise degistir
						{
							benzersiz = false;
						}
					}
				}
			} while (!benzersiz);
			matris[i][j] = rasgeleHarf;
			cout << matris[i][j] << "   ";
		}
	}
}

int main()
{
	cout << "\nTekrarsiz ve Resgele Dizi : \n";
	char matris[5][10];
	rasgele(matris);

	cout << "\nSiralanmis Dizi : " << endl;

	char vektor[50];//siralamasi icin matrisi bir buyut yaptik

	int x = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 10; j++)
		{
			vektor[x] = matris[i][j];
			x++;
		}
	}

	int n = sizeof(vektor);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (vektor[j] > vektor[j + 1])//bir sonrakine bak buyukse degistir
			{
				char temp = vektor[j];
				vektor[j] = vektor[j + 1];
				vektor[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 50; i++)
	{
		cout << vektor[i] << "   ";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}

	system("pause");
	return 0;
}