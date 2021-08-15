#pragma once
#include "Block.h"

using namespace std;
class CTetrix
{
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] 가로10칸, 세로20칸
	CBlock* Block;
	queue<int> blockQue;
	queue<int> previewQue;
	int isGameover = 0;
private:
	void init();
	void PrintTable();
	bool CheckAround(int posx,int posy, int type, int stat); //충돌감지
	bool CheckAround(POS pos, int type, int stat);
															 //	void Refillque(); //블록 새로 채우기
	void MakeNewque(); //게임 시작전 블록 목록 만들기
//	void PrintQue(); //앞으로 나올 블록 몇개 보여주기
	
	void merge(); //블록을 테이블과 합친다.
	void IsLineFull();

	void CursorView(char show);
public:
	void Play();
	CTetrix();
	~CTetrix();
};

