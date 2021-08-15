#include "Block.h"



void CBlock::move(char inputKey)
{
	//1. 움직이기전에 충돌검사
	//2. 변한 상태 재출력
	switch (inputKey) {
	case KEY_UP: //회전
		print(false);
		rotation = ++rotation % 4;
		print(true);
		break;
	case KEY_LEFT: //좌로
		print(false);
		--pos.x;
		print(true);
		break;
	case KEY_RIGHT: //우로
		print(false);
		++pos.x;
		print(true);		
		break;
	case KEY_DOWN: //하강
		print(false);
		++pos.y;
		print(true);
		break;
	}
}

void CBlock::print(bool show)
{
	for (int y = -2; y <= 2; y++) {
		for (int x = -2; x <= 2; x++) {
			if(block[type][rotation][x+2][y+2]) {
				gotoxy(TX + (x + pos.x) * 2, TY + y + pos.y);
				if(show) puts("■");
				else puts("  ");
			}
		}
	}
}


int CBlock::GetType()
{
	return type;
}

void CBlock::SetType(int type)
{
	this->type = type;
}

int CBlock::GetRotation()
{
	return rotation;
}

void CBlock::SetRotation(int stat)
{
	rotation = stat;
}

int CBlock::GetX()
{
	return pos.x;
}

void CBlock::SetX(int loc)
{
	pos.x = loc;
}

int CBlock::GetY()
{
	return pos.y;
}

void CBlock::SetY(int loc)
{
	pos.y = loc;
}

POSITION CBlock::GetPos()
{
	return pos;
}

CBlock::CBlock() : pos(0,0), type(0), rotation(0)
{
}


CBlock::~CBlock()
{
}
