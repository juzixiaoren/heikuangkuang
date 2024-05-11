#pragma once
#ifndef FIGHT_H
#define FIGHT_H
#include "header.h"
using namespace std;
class enemy_s
{//敌人类
protected:
	wstring name;//名字
	double hp;//生命值
	double atk;//攻击力
	double def;//防御力
	double atk_temp;//临时攻击力
	double def_temp;//临时防御力
	double hp_temp;//临时生命值
	double atk_b;//暴击率
	double def_b;//强化率
	double hp_b;//回复率
	double hp_c;//生命剥夺率
	int actor;//行为
	double act_num;//行为数值
	double output_atk;//输出攻击力
public:
	enemy_s() {};//默认构造函数
	enemy_s(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c) //构造函数
	{
		this->name = _name;
		this->hp = _hp;
		this->atk = _atk;
		this->def = _def;
		this->atk_temp = _atk;
		this->def_temp = _def;
		this->hp_temp = this->hp;
		this->atk_b = _atk_b;
		this->def_b = _def_b;
		this->hp_b = _hp_b;
		this->hp_c = _hp_c;
	}
	void show();//显示敌人信息}
	double op_atk(); //输出对敌方的攻击
	bool Ifalive();
	void Be_attacked(double be_atk); //被攻击函数
	void acts(); //行动函数
	void pd(); //行动判断函数
};
class player_s :enemy_s
{
private:
	int level;//等级
	int exp;//经验
	int money;//金钱
	int max_exp;//升级所需经验
public:
	player_s(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c) :enemy_s() //构造函数
	{
		this->name = _name;
		this->hp = _hp;
		this->atk = _atk;
		this->def = _def;
		this->atk_temp = _atk;
		this->def_temp = _def;
		this->hp_temp = this->hp;
		this->atk_b = _atk_b;
		this->def_b = _def_b;
		this->hp_b = _hp_b;
		this->hp_c = _hp_c;
		money=0;
		exp=0;
		level = 1;
		max_exp = 10;
	}
	void showplayerinfo();
	void changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c);
};

#endif