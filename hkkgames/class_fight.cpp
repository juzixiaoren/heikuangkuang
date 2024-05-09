#include"header.h"
using namespace std;
class enemy_s {//敌人类
protected:
	string name;//名字
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
	enemy_s(string _name, double _hp, double _atk, double _def,double _atk_b,double _def_b,double _hp_b,double _hp_c) //构造函数
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
	void show() {//显示敌人信息
		cout << "敌人名字：" << name << endl;
		cout << "敌人生命值：" << hp << endl;
		cout << "敌人攻击力：" << atk << endl;
		cout << "敌人防御力：" << def << endl;
	}
	double op_atk() //输出对敌方的攻击
	{
		return output_atk;
	}
	bool Ifalive() {//判断是否存活
		if (hp_temp > 0)
			return true;
		else
			return false;
	}
	void Be_attacked(double be_atk) //被攻击函数
	{
		double damage;
		if (be_atk < 0)
		{
			damage = abs(be_atk) / 100 * hp;
			hp_temp = hp_temp - damage;
			cout<< name << "被剥夺了" << damage << "点血量口牙" << endl;
			if (hp_temp > 0)
			{
				cout << name << "剩余生命值：" << hp_temp << endl;
				return;
			}
			else
			{
				cout << name << "已经死亡" << endl;
				return;
			}
			return;
		}
		if (be_atk == 0.0)
		{
			cout << name << "没有被影响" << endl;
			return;
		}
		damage = ((be_atk>def_temp) &&(be_atk -def_temp >be_atk *0.1)) ? be_atk - def_temp : be_atk *0.1;
		if(damage<1)
			damage = 1;
		hp_temp=hp_temp-damage;
		if (hp_temp > 0)
		{
			cout << name << "受到了" << damage << "点伤害" << endl;
			cout << name << "剩余生命值：" << hp_temp << endl;
			return;
		}
		else
		{
			cout << name << "受到了" << damage << "点伤害" << endl;
			cout << name << "已经死亡" << endl;
			return;
		}
	}
	void acts() //行动函数
	{
		int r;
		if (hp_temp < hp)
			r = rand() % 4 + 1;//生成1-4的随机数
		else
			r = rand() % 3 + 1;
		actor = r;
		if (r == 1)
		{
			cout << name << "使用了普通攻击" << endl;
			double rand_num = rand() % 110 + 1;
			if (rand_num <= atk_b)
			{
				cout << name << "暴击!" << endl;
				act_num = atk_temp * 1.5;
				return;
			}
			else if (rand_num >= 100)
			{
				cout << name << "攻击失误!" << endl;
				act_num = 0;
				return;
			}
			else
			{
				cout << name << "攻击成功!" << endl;
				act_num = atk_temp;
				return;
			}
		}
		else if (r == 2) {
			cout << name << "使用了强化" << endl;
			double rand_num = rand() % 110 + 1;
			if (rand_num <= def_b)
			{
				cout << name << "防御力和攻击力大提升!" << endl;
				atk_temp += atk * 0.3 > 0 ? atk * 0.3 : 1;
				def_temp += def * 0.3 > 0 ? def * 0.3 : 1;
				act_num = 0;
				return;
			}
			else if (rand_num >= 100)
			{
				cout << name << "强化失败!" << endl;
				act_num = 0;
				return;
			}
			else
			{
				cout << name << "防御力和攻击力提升!" << endl;
				atk_temp += atk * 0.1 > 0 ? atk * 0.1 : 1;
				def_temp += def * 0.1 > 0 ? def * 0.1 : 1;
				act_num = 0;
				return;
			}
		}
		else if (r == 3) {
			cout << name << "使用生命剥夺魔法" << endl;
			double rand_num = rand() % 100 + 1;
			if (rand_num <= 10) {
				cout << name << "生命值剥夺大成功!" << endl;
				act_num = hp_c + 10;
				return;
			}
			else if (rand_num > 10 && rand_num <= 30) {
				cout << name << "生命剥夺术小成功!" << endl;
				act_num = hp_c * 0.5;
				return;
			}
			else if (rand_num > 30 && rand_num <= 60)
			{
				cout << name << "生命值剥夺成功!" << endl;
				act_num = hp_c;
				return;
			}
			else
			{
				cout << name << "生命值剥夺失败!" << endl;
				act_num = 0;
				return;
			}
		}
		else if (r == 4) {
			cout << name << "使用了回复术" << endl;
			double rand_num = rand() % 110 + 1;
			if (rand_num <= hp_b)
			{
				cout << name << "生命值大幅度回复!" << endl;
				hp_temp += hp * 0.4 + 1;
				if (hp_temp > hp)
					hp_temp = hp;
				act_num = 0;
				return;
			}
			else if (rand_num >= 80)
			{
				cout << name << "回复失败!" << endl;
				act_num = 0;
				return;
			}
			else
			{
				cout << name << "生命值回复成功!" << endl;
				hp_temp += hp * 0.2 + 1;
				if (hp_temp > hp)
					hp_temp = hp;
				act_num = 0;
				return;
			}
		}
	}
	void pd() //行动判断函数
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
};