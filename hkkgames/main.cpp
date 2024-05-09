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
int coord_xy[10][2];//坐标数组
controller player(0, 10);//控制器
int Status= 0;//状态
int info = 0;//信息
Viewport buffers[2] = { 0 };//视口
int front_index = 0;//前索引
int back_index = 1;//后索引
int main() 
{
	wcout.imbue(locale("zh_CN"));  //设置语言环境
	Hkk_initialize();//初始化

	Startgame();//开始游戏

	thread t1(screen_output);//多线程
	thread t2(Coordinate);//多线程
	t1.join();
	t2.join();

	loadothers();//加载其他
	srand(time(0));//随机数种子
	//fight();//战斗函数测试
	return 0;
}