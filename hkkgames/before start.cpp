#include "header.h"
using namespace std;
void press_any() //按任意键开始游戏
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
		cout << "按任意键开始游戏" << endl;
}
//void fight() {//战斗函数测试，用两个小怪测试
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