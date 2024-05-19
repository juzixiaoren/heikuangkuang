#include"controller.h"
#include"header.h"
using namespace std;
bool controller::CheckKeyDown(int vKey)
{
	//Debug(printf("Checking %d", vKey));
	return GetAsyncKeyState(vKey) & 0x8000;
	//GetAsyncKeyState()的返回值表示两个内容，一个是最高位bit的值，代表这个键是否被按下，
	// 一个是最低位bit的值，代表在上次调用GetAsyncKeyState()后，这个键是否被按下。
}
bool controller::CheckIfMove()
{
	if (CheckKeyDown(KEYBOARD_W))
	{
		if (y - 1 < 0)
			return false;
		IfMove = 1;
		return true;
	}
	else if (CheckKeyDown(KEYBOARD_S))
	{
		if (y + 1 > 42)
			return false;
		IfMove = 2;
		return true;
	}
	else if (CheckKeyDown(KEYBOARD_A))
	{
		if (x - 1 < 0)
				return false;
		IfMove = 3;
		return true;
	}

	else if (CheckKeyDown(KEYBOARD_D))
	{
		if (x + 1 > 76)
			return false;
		IfMove = 4;
		return true;
	}
	else
	{
		IfMove = 0;
		return false;
	}
}
void controller::Move()
{
	if (IfMove == 1)
	{
		prex = x;
		prey = y;
		y--;
		IfMove=0;
	}
	else if (IfMove == 2)
	{
		prex = x;
		prey = y;
		y++;
		IfMove = 0;
	}
	else if (IfMove == 3)
	{
		prex = x;
		prey = y;
		x=x-1;
		IfMove = 0;
	}
	else if (IfMove == 4)
	{
		prex = x;
		prey = y;
		x=x+1;
		IfMove = 0;
	}
}
bool Timer(long long ms, int id)
{
	static long long  start[1000] = { 0 };
	long long end = clock();

	if (end - start[id] > ms)
	{
		start[id] = end;
		return 1;
	}
	return 0;
}
//#include "GameController.h"
//
//void GameController::Draw()
//{
//	console.ClearScreen();
//	SetConsoleCursorPosition(console.stdOutput, RotateCoord(playerPosition));
//	putchar('@');
//}
//
//void GameController::Update()
//{
//	// 处理输入
//	InputHandler();
//}
//
//void GameController::InputHandler()
//{
//	int newX = playerPosition.X;
//	int newY = playerPosition.Y;
//	//W
//	if (KeyboardController::CheckKeyDown(KEYBOARD_W)) {
//		newX -= 1;
//	}
//
//	//A
//	if (KeyboardController::CheckKeyDown(KEYBOARD_A)) {
//		newY -= 1;
//	}
//
//	//S
//	if (KeyboardController::CheckKeyDown(KEYBOARD_S)) {
//		newX += 1;
//	}
//
//	//D
//	if (KeyboardController::CheckKeyDown(KEYBOARD_D)) {
//		newY += 1;
//	}
//
//	newX = max(0, newX);
//	newX = min(newX, (console.consoleSize.column - 1));
//	newY = max(0, newY);
//	newY = min(newY, (console.consoleSize.row - 1));
//
//	playerPosition.X = newX;
//	playerPosition.Y = newY;
//}
//
//COORD RotateCoord(const COORD& instance) {
//	return { instance.Y, instance.X };
//}