#include "header.h"
#include "class_fight.cpp"
using namespace std;
void press_any() //按任意键开始游戏
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
		cout << "按任意键开始游戏" << endl;
}
void fight() {//战斗函数测试，用两个小怪测试
	enemy_s* A = new enemy_s("测试用小怪A", 100, 15, 10, 10, 10, 10, 10);
	enemy_s* B = new enemy_s("测试用小怪B", 100, 15, 10, 10, 10, 10, 10);
	A->show();
	B->show();
	while (A->Ifalive() && B->Ifalive()) 
	{
		B->acts();
		B->pd();
		A->Be_attacked(B->op_atk());
		A->acts();
		A->pd();
		B->Be_attacked(A->op_atk());
	}
	system("pause");
}