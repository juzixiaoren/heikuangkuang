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
	wcout.imbue(locale("zh_CN"));  //�������Ի���
	Hkk_initialize();//��ʼ��
	//GameStart();
	screen_output();//����������Ĳ���,Ŀǰ����ѭ�����Ҫ������һ����ע�͵�
	srand(time(0));//���������
	fight();//ս����������
	return 0;
}