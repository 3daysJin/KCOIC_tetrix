#include "Tetrix.h"
#include "Block.h"
#include <Windows.h> //gotoxy
#include <conio.h> //_kbhit()
#include <stdio.h> //puts, gets
Tetrix::Tetrix()
{
}

Tetrix::~Tetrix()
{
}

void Tetrix::init()
{
	//table �ʱ�ȭ
	for (int i = 0; i < 22; i++) {//Y��ǥ
		for (int j = 0; j < 12; j++) {//X��ǥ
			if( i==0 || i==21 || j==0 || j==11 ) table[i][j] = 1;
			else table[i][j] = 0;
		}
	}

	//Block �ʱ�ȭ
	Block.setBtype(0);
	Block.setBrotstat(0);
	Block.setBlocX(3);
	Block.setBlocY(21);
}

void Tetrix::Play_tetrix()
{
	CursorView(0);
	//������ �ʱ�ȭ
	char keytemp;
	init();
	//ù �� ť ����
	
	//���� ����
	while (1) {
		//���� �� ���� �� ���� �ʱ�ȭ �� ������ �ҷ�����
		printTable();
		for (;1;) { //���� �� ����
			if (_kbhit()) { //Ű�Է� ����
				keytemp = _getch();
				if (keytemp = EXT_KEY) { //����Ű �Է�
					keytemp = _getch();
					Block.move(keytemp);
				}
				if (keytemp = KEY_HOLD) { //Ȧ��Ű �Է�
				
				}

			}

		}
	}
}

void Tetrix::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tetrix::CursorView(char show)
{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = show;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Tetrix::isitFull()
{
	int x, y, ty;

	for (int i = 0; i < 4; i++) {
		
	}
}

void Tetrix::printTable()
{
	int x, y;
	for (x = 0; x < TW + 2; x++) {
		for (y = 0; y < TH + 2; y++) {
			gotoxy(TX + Block.getBlocX() * 2, TY + Block.getBlocY() * 2);
			puts(arTile[table[Block.getBlocX()][Block.getBlocY()]]);
		}
	}
}
