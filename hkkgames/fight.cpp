#include"header.h"
#include "fight.h"
using namespace std;
void enemy_s::show() 
{//��ʾ������Ϣ
	cout << "�������֣�" << name << endl;
	cout << "��������ֵ��" << hp << endl;
	cout << "���˹�������" << atk << endl;
	cout << "���˷�������" << def << endl;
}
double enemy_s::op_atk() //����Եз��Ĺ���
{
	return output_atk;
}
bool enemy_s::Ifalive() 
{//�ж��Ƿ���
	if (hp_temp > 0)
		return true;
	else
		return false;
}
void enemy_s::Be_attacked(double be_atk) //����������
{
	double damage;
	if (be_atk < 0)
		{
		damage = abs(be_atk) / 100 * hp;
		hp_temp = hp_temp - damage;
		cout<< name << "��������" << damage << "��Ѫ������" << endl;
		if (hp_temp > 0)
		{
			cout << name << "ʣ������ֵ��" << hp_temp << endl;
			return;
		}
		else
		{
			cout << name << "�Ѿ�����" << endl;
			return;
		}
		return;
	}
	if (be_atk == 0.0)
	{
		cout << name << "û�б�Ӱ��" << endl;
		return;
	}
	damage = ((be_atk>def_temp) &&(be_atk -def_temp >be_atk *0.1)) ? be_atk - def_temp : be_atk *0.1;
	if(damage<1)
		damage = 1;
	hp_temp=hp_temp-damage;
	if (hp_temp > 0)
	{
		cout << name << "�ܵ���" << damage << "���˺�" << endl;
		cout << name << "ʣ������ֵ��" << hp_temp << endl;
		return;
	}
	else
	{
		cout << name << "�ܵ���" << damage << "���˺�" << endl;
		cout << name << "�Ѿ�����" << endl;
		return;
	}
}
void enemy_s::acts() //�ж�����
	{
	int r;
	if (hp_temp < hp)
		r = rand() % 4 + 1;//����1-4�������
	else
		r = rand() % 3 + 1;
	actor = r;
	if (r == 1)
	{
		cout << name << "ʹ������ͨ����" << endl;
		double rand_num = rand() % 110 + 1;
		if (rand_num <= atk_b)
		{
			cout << name << "����!" << endl;
			act_num = atk_temp * 1.5;
			return;
		}
			else if (rand_num >= 100)
		{
			cout << name << "����ʧ��!" << endl;
			act_num = 0;
			return;
		}
		else
		{
			cout << name << "�����ɹ�!" << endl;
			act_num = atk_temp;
			return;
		}
	}
	else if (r == 2) {
		cout << name << "ʹ����ǿ��" << endl;
		double rand_num = rand() % 110 + 1;
		if (rand_num <= def_b)
		{
			cout << name << "�������͹�����������!" << endl;
			atk_temp += atk * 0.3 > 0 ? atk * 0.3 : 1;
			def_temp += def * 0.3 > 0 ? def * 0.3 : 1;
			act_num = 0;
			return;
		}
		else if (rand_num >= 100)
		{
			cout << name << "ǿ��ʧ��!" << endl;
			act_num = 0;
			return;
		}
		else
		{
			cout << name << "�������͹���������!" << endl;
			atk_temp += atk * 0.1 > 0 ? atk * 0.1 : 1;
			def_temp += def * 0.1 > 0 ? def * 0.1 : 1;
			act_num = 0;
			return;
		}
	}
	else if (r == 3) {
		cout << name << "ʹ����������ħ��" << endl;
		double rand_num = rand() % 100 + 1;
		if (rand_num <= 10) 
		{
			cout << name << "����ֵ�����ɹ�!" << endl;
			act_num = hp_c + 10;
			return;
		}
		else if (rand_num > 10 && rand_num <= 30) {
			cout << name << "����������С�ɹ�!" << endl;
			act_num = hp_c * 0.5;
			return;
		}
		else if (rand_num > 30 && rand_num <= 60)
		{
			cout << name << "����ֵ����ɹ�!" << endl;
			act_num = hp_c;
			return;
		}
		else
		{
			cout << name << "����ֵ����ʧ��!" << endl;
			act_num = 0;
			return;
		}
	}
	else if (r == 4) {
		cout << name << "ʹ���˻ظ���" << endl;
		double rand_num = rand() % 110 + 1;
		if (rand_num <= hp_b)
		{
			cout << name << "����ֵ����Ȼظ�!" << endl;
			hp_temp += hp * 0.4 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
		else if (rand_num >= 80)
		{
			cout << name << "�ظ�ʧ��!" << endl;
			act_num = 0;
			return;
		}
		else
		{
			cout << name << "����ֵ�ظ��ɹ�!" << endl;
			hp_temp += hp * 0.2 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
	}
}
void enemy_s::pd() //�ж��жϺ���
{
	if (actor == 1)
	{
		output_atk = act_num;
		return;
	}
	else if (actor == 2||actor==4)
	{
		output_atk = 0;
		return;
	}
	else if (actor == 3)
	{
		output_atk=-act_num;
		return;
	}
}