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
int player_temp_coord[2];//�����ʱ����
int Status= 0;//״̬
int info = 0;//��Ϣ
int fightinfo = 0;//ս����Ϣ
int Canfight = 1;//�Ƿ����ս��
Viewport buffers[2] = { 0 };//�ӿ�
int front_index = 0;//ǰ����
int back_index = 1;//������
int enemyid = 0;//����id
int levelup=0;//����
player_s Playerinfo(L"???",10,0,0,0,0,0,0);//�����Ϣ
vector <enemy_s> enemyinfo;//������Ϣ
int main() 
{
	wcout.imbue(locale("zh_CN"));  //�������Ի���
	Hkk_initialize();//��ʼ��
	srand(time(0));//���������
	Startgame();//��ʼ��Ϸ

	thread t1(screen_output);//���߳�
	thread t2(Coordinate);//���߳�
	thread t3(Update);//���߳�
	t1.join();
	t2.join();
	t3.join();
	//fight();//ս����������
	return 0;
}