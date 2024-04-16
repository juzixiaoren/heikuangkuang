#include "header.h"
using namespace std;
void press_any() {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
		cout << "按任意键开始游戏" << endl;
}