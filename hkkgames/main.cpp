#include"header.h"
#include"initialize.h"
#include"beforestart.h"
#include"screen.h"
using namespace std;
// #include"main.cpp"
// #include"functions.cpp"
// #include"classes.cpp"
// #include"variables.cpp"
// #include"functions.h"
// #include"classes.h"
// #include"variables.h"
// #include"main.h"
int main() {
	Hkk_initialize();//��ʼ��
	screen_output();//����������Ĳ���,Ŀǰ����ѭ�����Ҫ������һ����ע�͵�
	srand(time(0));//���������
	fight();//ս����������
	return 0;
}