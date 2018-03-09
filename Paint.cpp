#include <iostream>
using namespace std;
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "ConsoleLib.h"

void WriteMenu()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;

	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "  Start game                  ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "  Life                [3]     ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, Vert);
	WriteStr(26, 12, "             Created          ");
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, Vert);
	WriteStr(26, 13, "               by             ");
	WriteChar(56, 13, Vert);

	WriteChar(25, 14, Vert);
	WriteStr(26, 14, "              Alex            ");
	WriteChar(56, 14, Vert);

	WriteChar(25, 15, Vert);
	WriteChars(26, 15, ' ', 30);
	WriteChar(56, 15, Vert);

	WriteChar(25, 16, LeftBottom);
	WriteChars(26, 16, Horz, 30);
	WriteChar(56, 16, RightBottom);
	SetColor(LightGray, Black);
}

void PaintGame()
{
	SetColor(White, Cyan);
	for (int i = 0; i <= 24; i++)
	{
		WriteChars(0, i, ' ', 10);
		WriteChars(35, i, ' ', 10);
	}
	SetColor(Cyan, Black);
	WriteStr(58, 0, "Statistics:");
	WriteStr(51, 8, "Cout of correct letters:");
	WriteChar(63, 10, '0');
	WriteStr(51, 14, "Cout of missed letters:");
	WriteChar(63, 16, '0');
	WriteStr(60, 19, "Lives: 3");
	WriteStr(54, 24, "Press Space to pause");
}