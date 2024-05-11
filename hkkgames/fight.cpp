#include"header.h"
#include "fight.h"
#include"controller.h"
#include"screen.h"
using namespace std;
extern Viewport buffers[2];
extern int front_index;
extern int back_index;
void enemy_s::show() 
{//显示敌人信息
	wcout << "敌人名字：" << name << endl;
	wcout << "敌人生命值：" << hp << endl;
	wcout << "敌人攻击力：" << atk << endl;
	wcout << "敌人防御力：" << def << endl;
}
double enemy_s::op_atk() //输出对敌方的攻击
{
	return output_atk;
}
bool enemy_s::Ifalive() 
{//判断是否存活
	if (hp_temp > 0)
		return true;
	else
		return false;
}
void enemy_s::Be_attacked(double be_atk) //被攻击函数
{
	double damage;
	if (be_atk < 0)
		{
		damage = abs(be_atk) / 100 * hp;
		hp_temp = hp_temp - damage;
		wcout<< name << "被剥夺了" << damage << "点血量口牙" << endl;
		if (hp_temp > 0)
		{
			wcout << name << "剩余生命值：" << hp_temp << endl;
			return;
		}
		else
		{
			wcout << name << "已经死亡" << endl;
			return;
		}
		return;
	}
	if (be_atk == 0.0)
	{
		wcout << name << "没有被影响" << endl;
		return;
	}
	damage = ((be_atk>def_temp) &&(be_atk -def_temp >be_atk *0.1)) ? be_atk - def_temp : be_atk *0.1;
	if(damage<1)
		damage = 1;
	hp_temp=hp_temp-damage;
	if (hp_temp > 0)
	{
		wcout << name << "受到了" << damage << "点伤害" << endl;
		wcout << name << "剩余生命值：" << hp_temp << endl;
		return;
	}
	else
	{
		wcout << name << "受到了" << damage << "点伤害" << endl;
		wcout << name << "已经死亡" << endl;
		return;
	}
}
void enemy_s::acts() //行动函数
	{
	int r;
	if (hp_temp < hp)
		r = rand() % 4 + 1;//生成1-4的随机数
	else
		r = rand() % 3 + 1;
	actor = r;
	if (r == 1)
	{
		wcout << name << "使用了普通攻击" << endl;
		double rand_num = rand() % 110 + 1;
		if (rand_num <= atk_b)
		{
			wcout << name << "暴击!" << endl;
			act_num = atk_temp * 1.5;
			return;
		}
			else if (rand_num >= 100)
		{
			wcout << name << "攻击失误!" << endl;
			act_num = 0;
			return;
		}
		else
		{
			wcout << name << "攻击成功!" << endl;
			act_num = atk_temp;
			return;
		}
	}
	else if (r == 2) {
		wcout << name << "使用了强化" << endl;
		double rand_num = rand() % 110 + 1;
		if (rand_num <= def_b)
		{
			wcout << name << "防御力和攻击力大提升!" << endl;
			atk_temp += atk * 0.3 > 0 ? atk * 0.3 : 1;
			def_temp += def * 0.3 > 0 ? def * 0.3 : 1;
			act_num = 0;
			return;
		}
		else if (rand_num >= 100)
		{
			wcout << name << "强化失败!" << endl;
			act_num = 0;
			return;
		}
		else
		{
			wcout << name << "防御力和攻击力提升!" << endl;
			atk_temp += atk * 0.1 > 0 ? atk * 0.1 : 1;
			def_temp += def * 0.1 > 0 ? def * 0.1 : 1;
			act_num = 0;
			return;
		}
	}
	else if (r == 3) {
		wcout << name << "使用生命剥夺魔法" << endl;
		double rand_num = rand() % 100 + 1;
		if (rand_num <= 10) 
		{
			wcout << name << "生命值剥夺大成功!" << endl;
			act_num = hp_c + 10;
			return;
		}
		else if (rand_num > 10 && rand_num <= 30) {
			wcout << name << "生命剥夺术小成功!" << endl;
			act_num = hp_c * 0.5;
			return;
		}
		else if (rand_num > 30 && rand_num <= 60)
		{
			wcout << name << "生命值剥夺成功!" << endl;
			act_num = hp_c;
			return;
		}
		else
		{
			wcout << name << "生命值剥夺失败!" << endl;
			act_num = 0;
			return;
		}
	}
	else if (r == 4) {
		wcout << name << "使用了回复术" << endl;
		double rand_num = rand() % 110 + 1;
		if (rand_num <= hp_b)
		{
			wcout << name << "生命值大幅度回复!" << endl;
			hp_temp += hp * 0.4 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
		else if (rand_num >= 80)
		{
			wcout << name << "回复失败!" << endl;
			act_num = 0;
			return;
		}
		else
		{
			wcout << name << "生命值回复成功!" << endl;
			hp_temp += hp * 0.2 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
	}
}
void enemy_s::pd() //行动判断函数
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
void player_s::changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c)
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

void player_s::showplayerinfo()
{
	if (name == L"???")
		for (int i = 0; i < 3; i++) {
			buffers[back_index].m_buffer[21*WIDTH+131+i] = name[i];
		}
	else {
		for (int i = 0; i < 3; i++) {
			buffers[back_index].m_buffer[21 * WIDTH + 131 + 2*i] = name[i];
			buffers[back_index].m_buffer[21 * WIDTH + 131 + 2*i+1] = 0;
		}
	}
	wstring hp_ = to_wide_string(to_string((int)hp_temp));
	for (int i = 0, index = 25 * WIDTH + 129; i < hp_.length(); i++)
	{
		if (hp_[i] == L' ' || hp_[i] == 0) 
		{
			continue;
		}
		else 
		{
			buffers[back_index].m_buffer[index] = hp_[i];
			index++;
		}
	}
	wstring level_ = to_wide_string(to_string((int)level));
	for (int i = 0, index = 23 * WIDTH + 129; i < level_.length(); i++)
	{
		if (level_[i] == L' ' || level_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = level_[i];
			index++;
		}
	}
	wstring atk_ = to_wide_string(to_string((int)atk));
	for (int i = 0, index = 27 * WIDTH + 133; i < atk_.length(); i++)
	{
		if (atk_[i] == L' ' || atk_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = atk_[i];
			index++;
		}
	}
	wstring def_ = to_wide_string(to_string((int)def));
	for (int i = 0, index = 29 * WIDTH + 133; i < def_.length(); i++)
	{
		if (def_[i] == L' ' || def_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = def_[i];
			index++;
		}
	}
	wstring atk_b_ = to_wide_string(to_string((int)atk_b));
	for (int i = 0, index = 31 * WIDTH + 133; i < atk_b_.length(); i++)
	{
		if(def_[i] == L' ' || def_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = atk_b_[i];
			index++;
		}
	}
	wstring money_ = to_wide_string(to_string((int)money));
	for (int i = 0, index = 33 * WIDTH + 131; i < money_.length(); i++)
	{
		if (money_[i] == L' ' || money_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = money_[i];
			index++;
		}
	}
	wstring hp_c_ = to_wide_string(to_string((int)hp_c));
	for (int i = 0, index = 35 * WIDTH + 133; i < hp_c_.length(); i++)
	{
		if(hp_c_[i] == L' ' || hp_c_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = hp_c_[i];
			index++;
		}
	}
	wstring hp_b_ = to_wide_string(to_string((int)hp_b));
	for (int i = 0, index = 37 * WIDTH + 133; i < hp_b_.length(); i++)
	{
		if(hp_b_[i] == L' ' || hp_b_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = hp_b_[i];
			index++;
		}
	}
	wstring exp_ = to_wide_string(to_string((int)exp));
	for (int i = 0, index = 39 * WIDTH + 137; i < exp_.length(); i++)
	{
		if(exp_[i] == L' ' || exp_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = exp_[i];
			index++;
		}
	}
	wstring max_exp_ = to_wide_string(to_string((int)max_exp));
	for (int i = 0, index = 41 * WIDTH + 143; i < max_exp_.length(); i++) 
	{
		if(max_exp_[i] == L' ' || max_exp_[i] == 0)
		{
			continue;
		}
		else
		{
			buffers[back_index].m_buffer[index] = max_exp_[i];
			index++;
		}
	}









		/*wstring name_ = to_wide_string(name);
		int index;
		//for (int i = 0, index = 21 * WIDTH + 132; i < name_.length(); i++)
		//{
		//	if (name_[i] == L' ' || name_[i] == 0) {
		//		continue;
		//	}
			else if (name_[i] > 255)
			{
				buffers[back_index].m_buffer[index] = name_[i];
				buffers[back_index].m_buffer[index+1] = 0;
				index += 2;
				continue;
			}
			else {
				buffers[back_index].m_buffer[index] = name_[i];
				index++;
			}
		}*/
}