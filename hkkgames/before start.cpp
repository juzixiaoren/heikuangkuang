#include "header.h"
#include "class_fight.cpp"
using namespace std;
void press_any() //���������ʼ��Ϸ
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
		cout << "���������ʼ��Ϸ" << endl;
}
void fight() {//ս���������ԣ�������С�ֲ���
	enemy_s* A = new enemy_s("������С��A", 100, 15, 10, 10, 10, 10, 10);
	enemy_s* B = new enemy_s("������С��B", 100, 15, 10, 10, 10, 10, 10);
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