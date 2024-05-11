#pragma once
#ifndef FIGHT_H
#define FIGHT_H
#include "header.h"
using namespace std;
class enemy_s
{//������
protected:
	wstring name;//����
	double hp;//����ֵ
	double atk;//������
	double def;//������
	double atk_temp;//��ʱ������
	double def_temp;//��ʱ������
	double hp_temp;//��ʱ����ֵ
	double atk_b;//������
	double def_b;//ǿ����
	double hp_b;//�ظ���
	double hp_c;//����������
	int actor;//��Ϊ
	double act_num;//��Ϊ��ֵ
	double output_atk;//���������
public:
	enemy_s() {};//Ĭ�Ϲ��캯��
	enemy_s(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c) //���캯��
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
	void show();//��ʾ������Ϣ}
	double op_atk(); //����Եз��Ĺ���
	bool Ifalive();
	void Be_attacked(double be_atk); //����������
	void acts(); //�ж�����
	void pd(); //�ж��жϺ���
};
class player_s :enemy_s
{
private:
	int level;//�ȼ�
	int exp;//����
	int money;//��Ǯ
	int max_exp;//�������辭��
public:
	player_s(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c) :enemy_s() //���캯��
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