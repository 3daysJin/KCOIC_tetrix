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
	//table �ʱ�ȭ
	for (int Y = 0; Y < 22; Y++) {//Y��ǥ
		for (int X = 0; X < 12; X++) {//X��ǥ
			if (Y == 0 || Y == 21 || X == 0 || X == 11) table[Y][X] = 1;
			else table[Y][X] = 0;
		}
	}
	//Block = CBlock();
	//Block �ʱ�ȭ
	Block->SetType(3);
	Block->SetRotation(0);
	Block->SetX(3);
	Block->SetY(4);
	
}

void CTetrix::Play()
{
	CursorView(0); //Ŀ���� �������� �ʰ�

	char keytemp;
	init();
	MakeNewque();
	PrintTable();
	
	Block->SetType(blockQue.front());
	Block->print(1);
	while (1) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp = EXT_KEY) { //����Ű �Է�
				keytemp = _getch();
				switch (keytemp) {
				case KEY_DOWN:  //�Ʒ� �̵�
					if (!CheckAround(Block->GetX(), Block->GetY() - 1, Block->GetType(), Block->GetRotation()))
						Block->move(keytemp);
					break;
				case KEY_UP: //ȸ��
					if (!CheckAround(Block->GetX(), Block->GetY(), Block->GetType(), (Block->GetRotation() + 1) % 4))
						Block->move(keytemp);
					break;
				case KEY_LEFT: //�� �̵�
					if (!CheckAround(Block->GetX()-1, Block->GetY(), Block->GetType(), Block->GetRotation()))
						Block->move(keytemp);
					break;
				case KEY_RIGHT: //�� �̵�
					if (!CheckAround(Block->GetX()+1, Block->GetY(), Block->GetType(), Block->GetRotation()))
						Block->move(keytemp);
					break;
				}
			}
			if (keytemp = KEY_HOLD) { //Ȧ��Ű �Է�

			}
		}
		//�ð� ���� ���� �������� ��
		//�ٸ� ���� ������ ������
		//Que�� ������� ä������
	}
}

void CTetrix::PrintTable()
{
	int x = 0;
	int y = 0;
	for (x=0; x < TW + 2; x++) {		
		for (y=0; y < TH + 2; y++) {
			gotoxy(TX + x * 2, TY + y);
			if (table[y][x])	puts("��");
		}
	}
	//for debug
	gotoxy(42, 3); puts("Tetris Ver 1.0");
	gotoxy(42, 5); puts("�¿�:�̵�, ��:ȸ��, �Ʒ�:����");
	gotoxy(42, 6); puts("����:���� ����");
	gotoxy(42, 21); //����Ϸ��� ~~
	//
}

bool CTetrix::CheckAround(int posx,int posy, int type, int stat)
{
	int x=0,y=0; 
	for (x = -2; x <= 2; x++) {
		for (y=-2; y <= 2; y++) {
			if(table[posy+y][posx+x] && Block->block[type][stat][x+2][y+2])
			return true; //�浹 ����
		}
	}
	return false; //�浹 ����
}

void CTetrix::MakeNewque()
{
	while (!blockQue.empty())
		blockQue.pop();
	while (!previewQue.empty())
		previewQue.pop();
	//�ΰ��� ť �ʱ�ȭ
	srand(time(NULL));
	int temp[7] = { 0,1,2,3,4,5,6 };
	for (int i = 0; i < 50; i++) { //shuffle
		int randm1 = rand() % 7;
		int randm2 = rand() % 7;
		int tempN = temp[randm1];
		temp[randm1] = temp[randm2];
		temp[randm2] = tempN;
	}
	for(int i = 0; i<7;i++)
		blockQue.push(temp[i]);
}

void CTetrix::merge()
{
	int x, y;
	for (y = -2; y <= 2; y++) {
		for (x = -2; x <= 2; x++) {
			if (Block->GetY() + y >= 0)
				table[Block->GetY() + y][Block->GetX() + x] |= Block->block[Block->GetType()][Block->GetRotation()][x][y];
		}
	}
	IsLineFull();
	PrintTable();
}

void CTetrix::IsLineFull()
{
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
