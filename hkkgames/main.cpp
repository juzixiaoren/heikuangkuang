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
int coord_xy[10][2];//��������
controller player(0, 10);//������
int player_temp_coord[2];//������ʱ����
int Status= 0;//״̬
int info = 0;//��Ϣ
int fightinfo = 0;//ս����Ϣ
int Canfight = 1;//�Ƿ�����ս��
Viewport buffers[2] = { 0 };//�ӿ�
int front_index = 0;//ǰ����
int back_index = 1;//������
int enemyid = 0;//����id
int levelup=0;//����
int coinskill = 0;//��������
player_s Playerinfo(L"???",10,0,0,0,0,0,0);//������Ϣ
vector <enemy_s> enemyinfo;//������Ϣ
int main() 
{
	wcout.imbue(locale("zh_CN"));  //设置语言环境
	Hkk_initialize();//初始化
	srand(time(0));//随机数种子
	Startgame();//开始游戏

	thread t1(screen_output);//多线程
	thread t2(Coordinate);//多线程
	thread t3(Update);//多线程
	thread t4(music);//音乐线程
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	//fight();//ս����������
	return 0;
}