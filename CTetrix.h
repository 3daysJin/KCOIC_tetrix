#pragma once
#include "Block.h"

using namespace std;
class CTetrix
{
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] 가로10칸, 세로20칸
	CBlock* Block;
	queue<int> blockQue;
	vector<int> previewQue;
	bool downFlag = false;
	int isGameover = 0;
	int holdBlock = -1;
private:
	void Init();
	void PrintTable();
	bool CheckAround(int posx,int posy, int type, int stat); //충돌감지
	void MakeNewque(); //게임 시작전 블록 목록 만들기
	void EraseBlockQue();
	void PrintBlockQue(); //앞으로 나올 블록 몇개 보여주기
	
	void Merge(); //블록을 테이블과 합친다.
	void IsLineFull();
	void PrepareNewBlock();

	void CursorView(char show);
public:
	void Play();
	CTetrix();
	~CTetrix();
};

