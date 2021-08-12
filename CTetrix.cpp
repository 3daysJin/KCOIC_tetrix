#include "CTetrix.h"


CTetrix::CTetrix()
{
	Block = new CBlock();
}


CTetrix::~CTetrix()
{
	delete Block;
}

void CTetrix::init()
{
	//table 초기화
	for (int Y = 0; Y < 22; Y++) {//Y좌표
		for (int X = 0; X < 12; X++) {//X좌표
			if (Y == 0 || Y == 21 || X == 0 || X == 11) table[Y][X] = 1;
			else table[Y][X] = 0;
		}
	}
	//Block = CBlock();
	//Block 초기화
	Block->SetType(3);
	Block->SetRotation(0);
	Block->SetX(3);
	Block->SetY(4);
	
}

void CTetrix::Play()
{
	CursorView(0); //커서가 깜빡이지 않게

	char keytemp;
	init();
	MakeNewque();
	PrintTable();
	
	Block->SetType(blockQue.front());
	Block->print(1);
	while (1) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp = EXT_KEY) { //방향키 입력
				keytemp = _getch();
				if (keytemp != KEY_UP) {
					if(!CheckAround(Block->GetX(),Block->GetY(), Block->GetType(), Block->GetRotation()))
					Block->move(keytemp);
				}
				else {
					int next = Block->GetRotation();
					next = ++next % 4;
					if(!CheckAround(Block->GetX(), Block->GetY(), Block->GetType(), next))
					Block->move(keytemp);
				}
			}
			if (keytemp = KEY_HOLD) { //홀드키 입력

			}
		}
		//시간 진행 마다 내려가는 블럭
		//다른 블럭에 닿을시 합쳐짐
		//Que가 비기전에 채워야함
	}
}

void CTetrix::PrintTable()
{
	int x = 0;
	int y = 0;
	for (x=0; x < TW + 2; x++) {		
		for (y=0; y < TH + 2; y++) {
			gotoxy(TX + x * 2, TY + y);
			if (table[y][x])	puts("■");
		}
	}
	//for debug
	gotoxy(42, 3); puts("Tetris Ver 1.0");
	gotoxy(42, 5); puts("좌우:이동, 위:회전, 아래:내림");
	gotoxy(42, 6); puts("공백:전부 내림");
	gotoxy(42, 21); //계속하려면 ~~
	//
}

bool CTetrix::CheckAround(int posx,int posy, int type, int stat)
{
	int x=0,y=0; 
	for (x = -2; x <= 2; x++) {
		for (y=-2; y <= 2; y++) {
			if(table[posy+y][posx+x] && Block->block[type][stat][x+2][y+2])
			return true; //충돌 있음
		}
	}
	return false; //충돌 없음
}

void CTetrix::MakeNewque()
{
	while (!blockQue.empty())
		blockQue.pop();
	while (!previewQue.empty())
		previewQue.pop();
	//두개의 큐 초기화
	srand(time(NULL));
	int temp[7] = { 0,1,2,3,4,5,6 };
	for (int i = 0; i < 50; i++) {
		int randm1 = rand() % 7;
		int randm2 = rand() % 7;
		int tempN = temp[randm1];
		temp[randm1] = temp[randm2];
		temp[randm2] = tempN;
	}
	for(int i = 0; i<7;i++)
		blockQue.push(temp[i]);
}



void CTetrix::CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
