#include <iostream>
using namespace std;
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "ConsoleLib.h"
#include "Paint.h"

void Start()
{
	PaintGame();
	const int Esc = 27;
	const int Space = 32;

	int misLett = 0;
	ShowCursor(false);
	int key;
	int time = 400;
	extern int life;
	int templife = life;
	GotoXY(67, 19);
	cout << life;
	int Check = 0;
	char choise;

	WriteStr(12, 3, "Press any key to play");
	_getch();
	WriteChars(12, 3, ' ', 23);

	do
	{
			SetColor(Cyan, Black);
			GotoXY(63, 10);
			cout << Check;
			GotoXY(63, 16);
			cout << misLett;
			GotoXY(67, 19);
			cout << templife;
			char Letter = rand() % 26 + 65;
			int x = rand() % 24 + 11;
			int y = 0;
			int TempColor = rand() % 15 + 1;
			ConsoleColor colour;
			colour = (ConsoleColor)TempColor;
			SetColor(colour, Black);
			WriteChar(x, y, Letter);
			while (!_kbhit())
			{
				cout << "\b" << " ";
				y += 1;
				WriteChar(x, y, Letter);
				Sleep(time);
				if (y > 23)
				{
					templife -= 1;
					cout << "\b" << " ";
					misLett += 1;
					break;
				}
			}

			if (y <= 23)
			{

				key = _getch();

				cout << "\b" << " ";

				if (key == Letter || key == tolower(Letter))
				{
					Check += 1;
				}
				else if (key == Space)
				{
					SetColor(LightGray, Black);
					WriteStr(20, 12, "Pause");
					WriteStr(11, 14, "Press any key...");
					_getch();
					WriteChars(20, 12, ' ', 5);
					WriteChars(11, 14, ' ', 24);
				}
				else
				{
					templife -= 1;
					misLett += 1;
				}

				if (Check % 5 == 0)
				{
					time -= 30;
				}
			}
			else
				key = 1;
			if (templife == 0)
			{
				SetColor(Cyan, Black);
				ShowCursor(true);
				WriteStr(18, 12, "You lose!");
				WriteStr(12, 13, "Play again? Y/N => ");
				choise = _getch();
				cout << choise;
				_getch();
				if (choise == 'Y' || choise == 'y')
					{
						WriteChars(18, 12, ' ', 9);
						WriteChars(12, 13, ' ', 20);
						Start();
						break;
					}
				break;
			}	
	} while (key != Esc || key == 1);

	SetColor(LightGray, Black);
	ShowCursor(true);
	system("CLS");
}