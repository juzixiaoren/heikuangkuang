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
	int IfMove;//0:不动 1:上 2:左 3:下 4:右
	bool CheckKeyDown(int vKey);//检查按键是否按下
	bool CheckIfMove();//检查是否移动
	void Move();//移动
};
bool Timer(long long ms, int id);//计时器