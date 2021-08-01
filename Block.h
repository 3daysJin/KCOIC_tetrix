#pragma once
#include <Windows.h>

#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define EMPTY			0

#define TX 5 //벽안에 들어가기 위한 보정치
#define TY 1 //벽안에 들어가기 위한 보정치
#define TW 10 //가로 길이
#define TH 20 //세로 길이
class CBlock
{
public:
	bool block[7][4][4][4] = { //data 따로 처리할 방법 생각하기
							   //막대모양
		1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
		//네모모양
		1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
		//'ㅓ' 모양
		0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,	1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
		//'ㄱ'모양
		1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,	1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,	0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,
		//'ㄴ' 모양
		1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,	1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,	1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,
		//'Z' 모양
		1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,	0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,
		//'S' 모양
		0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,	0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0
	};
private:
	int B_locX, B_locY; //블록의 위치 정보 저장
	int B_type; //블록의 종류
	int B_rot_stat; //블록의 회전상태

public:
	int getBtype(); //블록종류 반환
	void setBtype(int type);
	int getBrotstat(); //블록회전상태 반환
	void setBrotstat(int stat);
	int getBlocX(); //블록의 X좌표 반환
	void setBlocX(int loc);
	int getBlocY(); //블록의 Y좌표 반환
	void setBlocY(int loc);

	void B_move(char inputKey); //블록을 움직인다
	void printB(bool show); //블록을 출력한다, 지울 수도 있음
	void mergeB(); //블록을 테이블과 합친다.

	void gotoxy(int x, int y);
	CBlock();
	~CBlock();
};

