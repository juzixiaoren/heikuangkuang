#include"header.h"
using namespace std;
class actor {
public :
	int act_c;
	int num;
	actor(int a, int b) {
		this->act_c = a;
		this->num = b;
	}
};
class enemy_s {
protected:
	string name;
	int hp;
	int atk;
	int def;
	int atk_temp;
	int def_temp;
	int hp_temp;
	int atk_b;
	int def_b;
	int hp_b;
	int hp_c;
public:
	enemy_s(string name, int hp, int atk, int def,int atk_b,int def_b,int hp_b) {
		this->name = name;
		this->hp = hp;
		this->atk = atk;
		this->def = def;
		this->atk_temp = atk;
		this->def_temp = def;
		this->hp_temp = hp;
		this->atk_b = atk_b;
		this->def_b = def_b;
		this->hp_b = hp_b;
		this->hp_c = hp_c;
	}
	void show() {
		cout << "敌人名字：" << name << endl;
		cout << "敌人生命值：" << hp << endl;
		cout << "敌人攻击力：" << atk << endl;
		cout << "敌人防御力：" << def << endl;
	}
	int Be_attacked(int be_atk) 
	{
		int damage = be_atk>def_temp &&be_atk -def_temp >be_atk *0.1 ? be_atk - def_temp : be_atk *0.1;
		if (be_atk == 0) {
			damage = 1;
		}
		hp_temp=hp_temp-damage;
		if (hp > 0)
		{
			cout << name << "受到了" << damage << "点伤害" << endl;
			cout << name << "剩余生命值：" << hp_temp << endl;
			return 1;
		}
		else
		{
			cout << name << "受到了" << damage << "点伤害" << endl;
			cout << name << "已经死亡" << endl;
			return 0;
		}
	}
	actor acts() 
	{
		int r;
		if (hp_temp < hp)
			r = rand() % 4 + 1;//生成1-4的随机数
		else
			r = rand() % 3 + 1;
		if (r == 1)
		{
			cout << name << "使用了普通攻击" << endl;
			int rand_num = rand() % 110 + 1;
			if (rand_num <= atk_b)
			{
				cout << name << "暴击!" << endl;
				return actor(r, atk_temp * 2);
			}
			else if (rand_num >= 100)
			{
				cout << name << "攻击失误!" << endl;
				return actor(r, 0);
			}
			else
			{
				cout << name << "攻击成功!" << endl;
				return actor(r, atk_temp);
			}
		}
		else if (r == 2) {
			cout << name << "使用了强化" << endl;
			int rand_num = rand() % 110 + 1;
			if (rand_num <= def_b)
			{
				cout << name << "防御力和攻击力大提升!" << endl;
				atk_temp += atk * 0.3 > 0 ? atk * 0.3 : 1;
				def_temp += def * 0.3 > 0 ? def * 0.3 : 1;
				return actor(r, 0);
			}
			else if (rand_num >= 100)
			{
				cout << name << "强化失败!" << endl;
				return actor(r, 0);
			}
			else
			{
				cout << name << "防御力和攻击力提升!" << endl;
				atk_temp += atk * 0.1 > 0 ? atk * 0.1 : 1;
				def_temp += def * 0.1 > 0 ? def * 0.1 : 1;
				return actor(r, 0);
			}
		}
		else if (r == 3) {
			cout << name << "使用生命剥夺魔法" << endl;
			int rand_num = rand() % 100 + 1;
			if (rand_num <= 10) {
				cout << name << "生命值剥夺大成功!" << endl;
				return actor(r, hp_c + 10);
			}
			else if (rand_num > 10 && rand_num <= 30) {
				cout << name << "生命剥夺术小成功!" << endl;
				return actor(r, hp_c * 0.5);
			}
			else if (rand_num > 30 && rand_num <= 60)
			{
				cout << name << "生命值剥夺成功!" << endl;
				return actor(r, hp_c);
			}
			else
			{
				cout << name << "生命值剥夺失败!" << endl;
				return actor(r, 0);
			}
		}
		else if (r == 4) {
			cout << name << "使用了回复术" << endl;
			int rand_num = rand() % 110 + 1;
			if (rand_num <= hp_b)
			{
				cout << name << "生命值大幅度回复!" << endl;
				hp_temp = hp * 0.4 + 1;
				if (hp_temp > hp)
					hp_temp = hp;
				return actor(r, 0);
			}
			else if (rand_num >= 80)
			{
				cout << name << "回复失败!" << endl;
				return actor(r, 0);
			}
			else
			{
				cout << name << "生命值回复成功!" << endl;
				hp_temp = hp * 0.2 + 1;
				if (hp_temp > hp)
					hp_temp = hp;
				return actor(r, 0);
			}
		}
	}
	int pd(actor a) 
	{
		if (a.act_c = 1)
		{
			return Be_attacked(a.num);
		}
		if (a.act_c = 2)
		{
			return 1;
		}
		if (a.act_c = 3)
		{
			return Be_attacked(a.num*hp);
		}
		if (a.act_c = 4)
		{
			return 1;
		}
	}
};