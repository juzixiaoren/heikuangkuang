#include "header.h"
using namespace std;
void press_any() //���������ʼ��Ϸ
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
		cout << "���������ʼ��Ϸ" << endl;
}
//void fight() {//ս���������ԣ�������С�ֲ���
//	A->show();
//	B->show();
//	system("pause");
//	while (A->Ifalive() && B->Ifalive()) 
//	{
//		B->acts();
//		B->pd();
//		A->Be_attacked(B->op_atk());
//		A->acts();
//		A->pd();
//		B->Be_attacked(A->op_atk());
//		system("pause");
//	}
//	system("pause");
//}