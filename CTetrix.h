#pragma once
#include "Block.h"

using namespace std;
class CTetrix
{
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] ����10ĭ, ����20ĭ
	CBlock* Block;
	queue<int> blockQue;
	vector<int> previewQue;
	bool downFlag = false;
	int isGameover = 0;
	int holdBlock = -1;
private:
	void Init();
	void PrintTable();
	bool CheckAround(int posx,int posy, int type, int stat); //�浹����
	void MakeNewque(); //���� ������ ��� ��� �����
	void EraseBlockQue();
	void PrintBlockQue(); //������ ���� ��� � �����ֱ�
	
	void Merge(); //����� ���̺�� ��ģ��.
	void IsLineFull();
	void PrepareNewBlock();

	void CursorView(char show);
public:
	void Play();
	CTetrix();
	~CTetrix();
};

