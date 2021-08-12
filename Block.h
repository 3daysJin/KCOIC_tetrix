#pragma once
#include "common.h"

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
	char block[7 /*kind */][4 /* rotation */][5 /* horizontal blocks,x */][5 /* vertical blocks,y */] = {
	// Square
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }}},
	// I
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 1, 1 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 1, 1, 2, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }}},
// L
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 0, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 1, 0 },
	{ 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 2, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0 },
	{ 0, 1, 2, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }}},
// L mirrored
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 0, 0 },
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0 },
	{ 0, 1, 2, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 2, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 1, 0 },
	{ 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0 }}},
// N
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 0, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 1, 2, 0, 0 },
	{ 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }}},
// N mirrored
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0 },
	{ 0, 1, 2, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0 },
	{ 0, 1, 2, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }}},
// T
{{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 2, 1, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 1, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 1, 2, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0 }},
{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0 },
	{ 0, 1, 2, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }}}
};

private:
	POSITION pos;
	int type; //블록의 종류
	int rotation; //블록의 회전상태
public:
	int GetType();
	void SetType(int type);
	int GetRotation();
	void SetRotation(int stat);
	int GetX(); //블록의 X좌표 반환
	void SetX(int loc);
	int GetY(); //블록의 Y좌표 반환
	void SetY(int loc);
	

	void move(char inputKey); //블록을 움직인다
	void print(bool show); //블록을 출력한다, 지울 수도 있음
	void merge(); //블록을 테이블과 합친다.

	CBlock();
	~CBlock();
};

