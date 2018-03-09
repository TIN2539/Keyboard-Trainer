#include <iostream>
using namespace std;

#include <conio.h>
#include "ConsoleLib.h"
#include "Start.h"
#include "Paint.h"

void Menu()
{
	const int Esc = 27;
	const int Enter = 13;

	int x = 40, y = 12;
	int key;
	extern int life;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenu();

	const int itemCount = 5;
	int curItem = 1;

	do
	{
		ChangeTextAttr(26, 9 + curItem, White, Black, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:
				system("CLS");
				SetColor(LightGray, Black);
				Start();
				Menu();
				break;
			case 2:
				ShowCursor(true);
				GotoXY(50, 11);
				cout << "\b";
				cin >> life;
				ShowCursor(false);
				break;
			case 3:
				Beep(1000, 100);
				break;
			case 4:
				Beep(1000, 500);
				break;
			case 5:
				Beep(1000, 1000);
				break;
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (key != Esc);

	SetColor(LightGray, Black);
	ShowCursor(true);
	exit(0);
}