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
int coord_xy[10][2];//��������
controller player(0, 10);//������
int Status= 0;//״̬
int info = 0;//��Ϣ
Viewport buffers[2] = { 0 };//�ӿ�
int front_index = 0;//ǰ����
int back_index = 1;//������
int main() 
{
	wcout.imbue(locale("zh_CN"));  //�������Ի���
	Hkk_initialize();//��ʼ��

	Startgame();//��ʼ��Ϸ

	thread t1(screen_output);//���߳�
	thread t2(Coordinate);//���߳�
	t1.join();
	t2.join();

	loadothers();//��������
	srand(time(0));//���������
	//fight();//ս����������
	return 0;
}