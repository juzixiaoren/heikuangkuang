#pragma once
#ifndef FIGHT_H
#define FIGHT_H
#include "header.h"
using namespace std;
class enemy_s
{//������
protected:
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
	double getmoney;//��ȡ��Ǯ
	double getexp;//��ȡ����
	wstring name;//����
	wstring info;//�ж���Ϣ
	wstring info2;//�˺���Ϣ
	wstring info3;//��������Ϣ
	wstring infoall;//ȫ����Ϣ
	enemy_s() {};//Ĭ�Ϲ��캯��
	enemy_s(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c, double getexp,double getmoney) //���캯��
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
	virtual double op_atk(); //����Եз��Ĺ���
	virtual bool Ifalive();//�ж��Ƿ���
	virtual void Be_attacked(double be_atk); //����������
	virtual void acts(); //�ж�����
	virtual void pd(); //�ж��жϺ���
	virtual void changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c, double getexp , double getmoney);//�ı����֣�Ѫ���������������������ʣ�ǿ���ʣ��ظ��ʣ�����������
	void showenemyinfo();
};
class player_s :enemy_s
{
private:

public:
	wstring info;//��Ϣ
	wstring info2;
	wstring infoall;
	wstring info3;
	double max_exp;//�������辭��
	int level;//�ȼ�
	double exp;//����
	int money;//��Ǯ
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
	void acts(int r);
	void showplayerinfo();
	void pd(); //�ж��жϺ���
	double op_atk(); //����Եз��Ĺ���
	void changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c);
	void Be_attacked(double be_atk); //����������
	double gethp();
	void ATKUP();
	void DEFUP();
	void HP_CUP();
	void HPUP();
	void statusreset();
	wstring getname();
};

#endif