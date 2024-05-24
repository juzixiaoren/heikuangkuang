#include "header.h"
#include "update.h"
extern player_s Playerinfo;
extern int fightinfo;
extern int levelup;
extern int coinskill;
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
using namespace std;

bool CheckKeyDown(int vKey)
{
	//Debug(printf("Checking %d", vKey));
	return GetAsyncKeyState(vKey) & 0x8000;
	//GetAsyncKeyState()的返回值表示两个内容，一个是最高位bit的值，代表这个键是否被按下，
	// 一个是最低位bit的值，代表在上次调用GetAsyncKeyState()后，这个键是否被按下。
}
void Update()
{
	while (1)
	{
		Sleep(30);
		if (Playerinfo.gethp() <= 0)
		{
			exit(0);
		}
		if (CheckKeyDown(VK_5))
		{
			if (!coinskill&&Playerinfo.money>=20) {
				coinskill = 1;
				Playerinfo.money -= 20;
			}
		}
		if (Playerinfo.exp >= Playerinfo.max_exp)
		{
			Playerinfo.level++;
			Playerinfo.exp = Playerinfo.exp-Playerinfo.max_exp;
			Playerinfo.max_exp = (Playerinfo.level ^ 2) / 2 + Playerinfo.max_exp + 4;
			levelup++;
		}
		if (levelup) {
			if (CheckKeyDown(VK_1))
			{
				Playerinfo.ATKUP();
				levelup--;
			}
			else if (CheckKeyDown(VK_2))
			{
				Playerinfo.DEFUP();
				levelup--;
			}
			else if (CheckKeyDown(VK_3))
			{
				Playerinfo.HPUP();
				levelup--;
			}
			else if (CheckKeyDown(VK_4))
			{
				Playerinfo.HP_CUP();
				levelup--;
			}
		}
	}
}