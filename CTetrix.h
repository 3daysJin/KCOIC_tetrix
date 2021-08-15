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
	int isGameover = 0;
private:
	void init();
	void PrintTable();
	bool CheckAround(int posx,int posy, int type, int stat); //�浹����
	bool CheckAround(POS pos, int type, int stat);
															 //	void Refillque(); //��� ���� ä���
	void MakeNewque(); //���� ������ ��� ��� �����
//	void PrintQue(); //������ ���� ��� � �����ֱ�
	
	void merge(); //����� ���̺�� ��ģ��.
	void IsLineFull();

	void CursorView(char show);
public:
	void Play();
	CTetrix();
	~CTetrix();
};

