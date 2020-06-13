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

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;


const int  genislik = 80, yukseklik = 20, dusmanOrani = 10, dusmanleAtesMax = 1000;
int atesNo = 0, dusmanNo = 0, ucakVeAtesYeri = 8;
bool kur = true;
char sahne[genislik][yukseklik], ucakVeSaha = 219, dusmanVeAtes = 254;
struct DusmanleAtes
{
	int x, y, kuvvet, xa = genislik - 2, ya = ucakVeAtesYeri + 4;

};
DusmanleAtes dusmanleAtes[dusmanleAtesMax];

void gotoxy(int x, int y)
{
	COORD crd;
	crd.X = x;
	crd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}
void konsulSakla()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void sahneSil() {
	for (int i = 0; i < genislik; i++)
	{
		for (int j = 0; j < yukseklik; j++)
		{
			sahne[i][j] = ' ';
		}
	}
}
void sahneCiz() {
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{	
			cout << sahne[x][y];
			if (GetAsyncKeyState('I'))
			{
				sahne[x][y] = SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 * 16 + 12);

			}
		}
		cout << endl;
	}
}
void sinirlarCiz() {
	for (int i = 0; i < genislik; i++)
	{
		sahne[i][0] = ucakVeSaha;
		sahne[genislik - (i + 1)][yukseklik - 1] = ucakVeSaha;
	}
	for (int j = 0; j < yukseklik; j++)
	{
		sahne[genislik - 1][j] = ucakVeSaha;
		sahne[0][yukseklik - (j + 1)] = ucakVeSaha;
	}
}

void usakHareketEttir() {
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (ucakVeAtesYeri > 1)
		{
			ucakVeAtesYeri--;
		}

	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (ucakVeAtesYeri < yukseklik - 6)
		{
			ucakVeAtesYeri++;
		}
	}
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (x == y || (y == 3 && x == 1) || (y == 4 && x == 0))
			{
				sahne[x + 1][y + ucakVeAtesYeri] = ucakVeSaha;
			}
		}
	}

}
void atesCiz()
{
	if (GetAsyncKeyState(VK_SPACE) )
	{
		dusmanleAtes[atesNo].xa = 4;
		dusmanleAtes[atesNo].ya = ucakVeAtesYeri + 2;
	

		sahne[dusmanleAtes[atesNo].xa][dusmanleAtes[atesNo].ya] = dusmanVeAtes;
		;
		atesNo++;

	}
}

void atesHaraketEttir() {
	for (int i = 0; i < dusmanleAtesMax; i++)
	{
		if (dusmanleAtes[i].xa < genislik - 2)
		{
			dusmanleAtes[i].xa++;
			sahne[dusmanleAtes[i].xa][dusmanleAtes[i].ya] = dusmanVeAtes;

		}
	}
}
void dusmanNesli()
{
	srand(time(NULL));

	if ((dusmanNo + dusmanOrani) % dusmanOrani == 0)
	{
		int atesNesli = rand() % (yukseklik - 4) + 1;
		dusmanleAtes[dusmanNo].x = genislik - 2;
		dusmanleAtes[dusmanNo].y = atesNesli;
		dusmanleAtes[dusmanNo].kuvvet = 0;
		for (int i = 0; i < 3; i++)
		{
			sahne[dusmanleAtes[dusmanNo].x][dusmanleAtes[dusmanNo].y + i] = dusmanVeAtes;
		}

		dusmanleAtes[dusmanNo].kuvvet++;
	}
	dusmanNo++;

}
void dusmanHareketEttir() {

	for (int i = 0; i < dusmanleAtesMax; i++)
	{
		if (dusmanleAtes[i].x > 1)
		{
			if (dusmanleAtes[i].kuvvet == 1)
			{
				dusmanleAtes[i].x--;
				for (int k = 0; k < 3; k++)
				{
					for (int j = 0; j < 2; j++)
					{
						if (j == 1 && k == 1)
						{
							sahne[dusmanleAtes[i].x + j][dusmanleAtes[i].y + k] = ' ';
						}
						else
						{
							sahne[dusmanleAtes[i].x + j][dusmanleAtes[i].y + k] = dusmanVeAtes;
						}
					}
				}
				dusmanleAtes[i].kuvvet++;
			}
			else if (2 <= dusmanleAtes[i].kuvvet)
			{
				dusmanleAtes[i].x--;
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 4; b++)
					{
						if (a == 1 && b == 1)
						{
							sahne[dusmanleAtes[i].x + b][dusmanleAtes[i].y + a] = ' ';

						}
						else
						{
							sahne[dusmanleAtes[i].x + b][dusmanleAtes[i].y + a] = dusmanVeAtes;
						}
					}
				}
			}
		} 
	}
}
void dusmanOldur() {

	for (int dusman = 0; dusman < dusmanleAtesMax; dusman++)
	{
		for (int ates = 0; ates < dusmanleAtesMax; ates++)
		{
			if ((dusmanleAtes[dusman].x == dusmanleAtes[ates].xa) && ((dusmanleAtes[dusman].y == dusmanleAtes[ates].ya) ||
				(dusmanleAtes[dusman].y + 1 == dusmanleAtes[ates].ya) || (dusmanleAtes[dusman].y + 2 == dusmanleAtes[ates].ya)))
			{
				dusmanleAtes[ates].xa = genislik - 1;
				dusmanleAtes[dusman].x = 1;
			}
		}
		if (((dusmanleAtes[dusman].x == 3))
			&& ((dusmanleAtes[dusman].y == ucakVeAtesYeri)
				|| (dusmanleAtes[dusman].y - 1 == ucakVeAtesYeri)
				|| (dusmanleAtes[dusman].y - 2 == ucakVeAtesYeri)))
		{
			kur = false;
			system("cls");
		}

	}
}
void kilavyeGoster() {
		gotoxy(81, 7);

		cout << "S yada hisse yukarı basildinda :Yukai\n";
		gotoxy(81, 8);

		cout << "A yada hisse Asa basildinda :Asa\n";
		gotoxy(81, 9);
		cout << "SPACE basildinda :Ates\n";
		gotoxy(81, 10);
		cout << "I basildinda: renki degisecek\n";
}

int main() {

	konsulSakla();
	char tekrar = 'e';
	do {
		do
		{
			gotoxy(0, 0);
			sahneSil();
			sinirlarCiz();
			usakHareketEttir();
			atesCiz();
			atesHaraketEttir();
			dusmanOldur();
			dusmanNesli();
			dusmanHareketEttir();
			dusmanOldur();
			sahneCiz();
			kilavyeGoster();
			Sleep(10);
		} while (kur);
		tolower(tekrar);
		kur = true;
		system("cls");
		cout << "TEKRAR OYNAMAK ISTERSINIZ 'E' BASINIZ ISTEMAsSINIZ 'H' BASINIZ";
		cin >> tekrar;

	} while (tekrar = 'e');


	return 0;
}