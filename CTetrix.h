#pragma once
#include "Block.h"
#include <queue>
#define EXT_KEY			0xffffffe0 //Ȯ��Ű �νİ�
#define KEY_HOLD		0x5A	//Z

using namespace std;
class CTetrix
{
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] ����10ĭ, ����20ĭ
	CBlock* Block;
	queue<int> blockQue;
	queue<int> previewQue;
public:
	CTetrix();
	~CTetrix();
	void init();
	
	void Play_tetrix();
	void printTable();
	bool checkAround(int x, int y,int bt, int r); //�浹����
//	void refillque(); //��� ���� ä���
	void makeNewque(); //���� ������ ��� ��� �����
//	void printQue(); //������ ���� ��� � �����ֱ�

	void gotoxy(int x, int y);
	void CursorView(char show);

};

