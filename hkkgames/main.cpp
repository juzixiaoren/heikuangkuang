#include"header.h"
#include"initialize.h"
#include"beforestart.h"
#include"screen.h" 
#include"Startgame.h"
#include "update.h"
//#include"functions.cpp"
//#include"classes.cpp"
//#include"variables.cpp"
//#include"functions.h"
//#include"classes.h"
//#include"variables.h"
#include"fight.h"
using namespace std;
int coord_xy[10][2];//坐标数组
controller player(0, 10);//控制器
int player_temp_coord[2];//玩家临时坐标
int Status= 0;//状态
int info = 0;//信息
int fightinfo = 0;//战斗信息
int Canfight = 1;//是否可以战斗
Viewport buffers[2] = { 0 };//视口
int front_index = 0;//前索引
int back_index = 1;//后索引
int enemyid = 0;//敌人id
int levelup=0;//升级
player_s Playerinfo(L"???",10,0,0,0,0,0,0);//玩家信息
vector <enemy_s> enemyinfo;//敌人信息
int main() 
{
	wcout.imbue(locale("zh_CN"));  //设置语言环境
	Hkk_initialize();//初始化
	srand(time(0));//随机数种子
	Startgame();//开始游戏

	thread t1(screen_output);//多线程
	thread t2(Coordinate);//多线程
	thread t3(Update);//多线程
	t1.join();
	t2.join();
	t3.join();
	//fight();//战斗函数测试
	return 0;
}