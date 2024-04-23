#include"header.h"
#include"initialize.h"
#include"beforestart.h"
#include"screen.h" 
#include"Startgame.h"
//#include"functions.cpp"
//#include"classes.cpp"
//#include"variables.cpp"
//#include"functions.h"
//#include"classes.h"
//#include"variables.h"

using namespace std;

int main() 
{
	wcout.imbue(locale("zh_CN"));  //设置语言环境
	Hkk_initialize();//初始化
	//GameStart();
	screen_output();//单缓冲输出的测试,目前是死循环如果要进入下一步请注释掉
	srand(time(0));//随机数种子
	fight();//战斗函数测试
	return 0;
}