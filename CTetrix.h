#pragma once
#include "Block.h"

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
	
	void Play();
	void PrintTable();
	bool CheckAround(int posx,int posy, int type, int stat); //�浹����
//	void Refillque(); //��� ���� ä���
	void MakeNewque(); //���� ������ ��� ��� �����
//	void PrintQue(); //������ ���� ��� � �����ֱ�

	void CursorView(char show);

};

