#pragma once
#define KEYBOARD_W 0x57
#define KEYBOARD_A 0x41
#define KEYBOARD_S 0x53
#define KEYBOARD_D 0x44
class controller {
public:
	int x, y;
	int prex, prey;
	controller(int a, int b)
	{
		x = a;
		y = b;
		prex = x;
		prey = y;
	}
	int IfMove;//0:���� 1:�� 2:�� 3:�� 4:��
	bool CheckKeyDown(int vKey);//��鰴���Ƿ���
	bool CheckIfMove();//����Ƿ��ƶ�
	void Move();//�ƶ�
};
bool Timer(long long ms, int id);//��ʱ��