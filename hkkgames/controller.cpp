#include"controller.h"
#include"header.h"
using namespace std;
bool controller::CheckKeyDown(int vKey)
{
	//Debug(printf("Checking %d", vKey));
	return GetAsyncKeyState(vKey) & 0x8000;
	//GetAsyncKeyState()�ķ���ֵ��ʾ�������ݣ�һ�������λbit��ֵ������������Ƿ񱻰��£�
	// һ�������λbit��ֵ���������ϴε���GetAsyncKeyState()��������Ƿ񱻰��¡�
}
bool controller::CheckIfMove()
{
	if (CheckKeyDown(KEYBOARD_W))
	{
		IfMove = 1;
		return true;
	}
	else if (CheckKeyDown(KEYBOARD_S))
	{
		IfMove = 2;
		return true;
	}
	else if (CheckKeyDown(KEYBOARD_A))
	{
		IfMove = 3;
		return true;
	}

	else if (CheckKeyDown(KEYBOARD_D))
	{
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
//	// ��������
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