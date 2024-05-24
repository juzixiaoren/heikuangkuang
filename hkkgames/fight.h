#pragma once
#ifndef FIGHT_H
#define FIGHT_H
#include "header.h"
using namespace std;
class enemy_s
{//敌人类
protected:
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
	double getmoney;//获取金钱
	double getexp;//获取经验
	wstring name;//名字
	wstring info;//行动信息
	wstring info2;//伤害信息
	wstring info3;//被攻击信息
	wstring infoall;//全部信息
	enemy_s() {};//默认构造函数
	enemy_s(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c, double getexp,double getmoney) //构造函数
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
		this->getexp = getexp;
		this->getmoney = getmoney;
	}
	virtual double op_atk(); //输出对敌方的攻击
	virtual bool Ifalive();//判断是否存活
	virtual void Be_attacked(double be_atk); //被攻击函数
	virtual void acts(); //行动函数
	virtual void pd(); //行动判断函数
	virtual void changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c, double getexp , double getmoney);//改变名字，血量，攻击，防御，暴击率，强化率，回复率，生命剥夺率
	void showenemyinfo();
};
class player_s :enemy_s
{
private:

public:
	wstring info;//信息
	wstring info2;
	wstring infoall;
	wstring info3;
	double max_exp;//升级所需经验
	int level;//等级
	double exp;//经验
	int money;//金钱
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
	void acts(int r);
	void showplayerinfo();
	void pd(); //行动判断函数
	double op_atk(); //输出对敌方的攻击
	void changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c);
	void Be_attacked(double be_atk); //被攻击函数
	double gethp();
	void ATKUP();
	void DEFUP();
	void HP_CUP();
	void HPUP();
	void statusreset();
	wstring getname();
};

#endif