#pragma once
#ifndef FIGHT_H
#define FIGHT_H
#include "header.h"
using namespace std;
class enemy_s
{//������
protected:
	string name;//����
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
	enemy_s(string _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c) //���캯��
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
#endif