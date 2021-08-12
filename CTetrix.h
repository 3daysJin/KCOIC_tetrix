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
public:
	CTetrix();
	~CTetrix();
	void init();
	
	void Play();
	void PrintTable();
	bool CheckAround(int posx,int posy, int type, int stat); //충돌감지
//	void Refillque(); //블록 새로 채우기
	void MakeNewque(); //게임 시작전 블록 목록 만들기
//	void PrintQue(); //앞으로 나올 블록 몇개 보여주기

	void CursorView(char show);

};

