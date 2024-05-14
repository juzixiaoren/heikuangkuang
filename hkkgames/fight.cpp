#include"header.h"
#include "fight.h"
#include"controller.h"
#include"screen.h"
using namespace std;
extern Viewport buffers[2];
extern int front_index;
extern int back_index;
extern player_s Playerinfo;
extern vector <enemy_s> enemyinfo;

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
void player_s::Be_attacked(double be_atk) //被攻击函数
{
	info2.clear();
	double damage;
	if (be_atk < 0)
	{
		damage = abs(be_atk) / 100 * hp;
		hp_temp = hp_temp - damage;
	}
	else if (be_atk > 0)
	{
		damage = ((be_atk > def_temp) && (be_atk - def_temp > be_atk * 0.1)) ? be_atk - def_temp : be_atk * 0.1;
		if (damage < 1)
			damage = 1;
		hp_temp = hp_temp - damage;
	}
	if (be_atk == 0) 
	{
		info3 =name+ L"不受影响";
	}
	else if(be_atk<0)
	{
		info3 = name + L"受到魔曲剥夺";
		info2= to_wide_string(to_string((int)damage));
	}
	else 
	{
		info3 = name +L"受到攻击";
		info2 = to_wide_string(to_string((int)damage));
	}
}
void enemy_s::Be_attacked(double be_atk) //被攻击函数
{
	info2.clear();
	double damage;
	if (be_atk < 0)
	{
		damage = abs(be_atk) / 100 * hp;
		hp_temp = hp_temp - damage;
	}
	else if (be_atk > 0)
	{
		damage = ((be_atk > def_temp) && (be_atk - def_temp > be_atk * 0.1)) ? be_atk - def_temp : be_atk * 0.1;
		if (damage < 1)
			damage = 1;
		hp_temp = hp_temp - damage;
	}
	if (be_atk == 0)
	{
		info3 = name + L"不受影响";
	}
	else if (be_atk < 0)
	{
		info3 = name + L"受到魔曲剥夺";
		info2 = to_wide_string(to_string((int)damage));
	}
	else
	{
		info3 = name + L"受到攻击";
		info2 = to_wide_string(to_string((int)damage));
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
		double rand_num = rand() % 110 + 1;
		if (rand_num <= atk_b)
		{
			info = L"暴击！";
			act_num = atk_temp * 1.5;
			return;
		}
		else if (rand_num >= 100)
		{
			info = L"攻击失误";
			act_num = 0;
			return;
		}
		else
		{
			info = L"攻击成功";
			act_num = atk_temp;
			return;
		}
	}
	else if (r == 2) {
		double rand_num = rand() % 110 + 1;
		if (rand_num <= def_b)
		{
			info = L"强化大成功";
			atk_temp += atk * 0.3 > 0 ? atk * 0.3 : 1;
			def_temp += def * 0.3 > 0 ? def * 0.3 : 1;
			act_num = 0;
			return;
		}
		else if (rand_num >= 100)
		{
			info = L"强化失败";
			act_num = 0;
			return;
		}
		else
		{
			info = L"强化成功";
			atk_temp += atk * 0.1 > 0 ? atk * 0.1 : 1;
			def_temp += def * 0.1 > 0 ? def * 0.1 : 1;
			act_num = 0;
			return;
		}
	}
	else if (r == 3) {
		double rand_num = rand() % 100 + 1;
		if (rand_num <= 10)
		{
			info = L"魔曲大成功";
			act_num = hp_c + 10;
			return;
		}
		else if (rand_num > 10 && rand_num <= 30) {
			info = L"魔曲小成功";
			act_num = hp_c * 0.5;
			return;
		}
		else if (rand_num > 30 && rand_num <= 60)
		{
			info = L"魔曲成功";
			act_num = hp_c;
			return;
		}
		else
		{
			info = L"魔曲失败";
			act_num = 0;
			return;
		}
	}
	else if (r == 4) {
		double rand_num = rand() % 110 + 1;
		if (rand_num <= hp_b)
		{
			info = L"回复大成功";
			hp_temp += hp * 0.4 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
		else if (rand_num >= 80)
		{
			info = L"回复失败";
			act_num = 0;
			return;
		}
		else
		{
			info = L"回复成功";
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
void enemy_s::changeinfo(wstring _name, double _hp, double _atk, double _def, double _atk_b, double _def_b, double _hp_b, double _hp_c,double getexp)
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
}
void enemy_s::showenemyinfo() 
{
	for (int i = 0; i < name.length(); i++)
	{
		buffers[back_index].m_buffer[31*WIDTH+7+i*2]=name[i];
		buffers[back_index].m_buffer[31*WIDTH+7+i*2+1]=0;
	}
	wstring hp_ = to_wide_string(to_string((int)hp_temp));
	for (int i = 0, index = 31 * WIDTH + 50; i < hp_.length(); i++)
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
	wstring atk_ = to_wide_string(to_string((int)atk_temp));
	for (int i = 0, index = 32 * WIDTH + 9; i < atk_.length(); i++)
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
	wstring def_ = to_wide_string(to_string((int)def_temp));
	for (int i = 0, index = 32 * WIDTH + 54; i < def_.length(); i++)
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
	{
		wstring zt;
		if (hp_temp >= 0.5 * hp) {
			zt = L"正常";
		}
		else if (hp_temp < 0.5 * hp && hp_temp >= 0.2 * hp)
		{
			zt = L"受伤";
		}
		else
		{
			zt = L"濒死";
		}
		for (int i = 0, index = 33 * WIDTH + 7; i < zt.length(); i++)
		{
			if (zt[i] == L' ' || zt[i] == 0)
			{
				continue;
			}
			else
			{
				buffers[back_index].m_buffer[index] = zt[i];
				buffers[back_index].m_buffer[index+1] = 0;
				index+=2;
			}
		}
	}
	if (!info.empty()) {
		if (!info2.empty()) {
			infoall = Playerinfo.getname() + L"向上天祈祷，" + Playerinfo.info + L"，对" + info3+L"造成" + info2 + L"伤害";
			for (int i = 0, index = 33 * WIDTH + 53; i < infoall.length(); i++)
			{
				if (infoall[i] == L' ' || infoall[i] == 0)
				{
					continue;
				}
				else if (infoall[i] < 255)
				{
					buffers[back_index].m_buffer[index] = infoall[i];
					index++;
				}
				else {
					buffers[back_index].m_buffer[index] = infoall[i];
					buffers[back_index].m_buffer[index+1] = 0;
					index+=2;
				}
			}
		}
		else 
		{
			infoall = Playerinfo.getname()+L"向上天祈祷，"+Playerinfo.info +L"，"+info3;
			for (int i = 0, index = 33 * WIDTH + 53; i < infoall.length(); i++)
			{
				if (infoall[i] == L' ' || infoall[i] == 0)
				{
					continue;
				}
				else if (infoall[i] < 255)
				{
					buffers[back_index].m_buffer[index] = infoall[i];
					index++;
				}
				else {
					buffers[back_index].m_buffer[index] = infoall[i];
					buffers[back_index].m_buffer[index+1] = 0;
					index += 2;
				}
			}
		}
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
wstring player_s::getname() {
	return name;
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
	wstring atk_ = to_wide_string(to_string((int)atk_temp));
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
	wstring def_ = to_wide_string(to_string((int)def_temp));
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
	if (!info.empty()) 
	{
		if (!info2.empty()) 
		{
			infoall = Playerinfo.getname() + L"小心移动，但还是挨了一下，" + enemyinfo[0].name+L"进行" + enemyinfo[0].info + L"，对" + info3 + L"造成" + info2 + L"伤害";
			for (int i = 0, index = 34 * WIDTH; i < infoall.length(); i++)
			{
				if (infoall[i] == L' ' || infoall[i] == 0)
				{
					continue;
				}
				else if (infoall[i] < 255)
				{
					buffers[back_index].m_buffer[index] = infoall[i];
					index++;
				}
				else {
					buffers[back_index].m_buffer[index] = infoall[i];
					buffers[back_index].m_buffer[index + 1] = 0;
					index += 2;
				}
			}
		}
		else
		{
			infoall = Playerinfo.getname() + L"准备进行防守反击，"+L"然而"+enemyinfo[0].name +enemyinfo[0].info + L"，" + info3;
			for (int i = 0, index = 34 * WIDTH; i < infoall.length(); i++)
			{
				if (infoall[i] == L' ' || infoall[i] == 0)
				{
					continue;
				}
				else if (infoall[i] < 255)
				{
					buffers[back_index].m_buffer[index] = infoall[i];
					index++;
				}
				else {
					buffers[back_index].m_buffer[index] = infoall[i];
					buffers[back_index].m_buffer[index + 1] = 0;
					index += 2;
				}
			}
		}
	}
}

void player_s::acts(int r) //行动函数
{
	actor = r;
	if (r == 1)
	{
		double rand_num = rand() % 110 + 1;
		if (rand_num <= atk_b)
		{
			info = L"暴击！";
			act_num = atk_temp * 1.5;
			return;
		}
		else if (rand_num >= 100)
		{
			info = L"攻击失误";
			act_num = 0;
			return;
		}
		else
		{
			info=L"攻击成功";
			act_num = atk_temp;
			return;
		}
	}
	else if (r == 2) {
		double rand_num = rand() % 110 + 1;
		if (rand_num <= def_b)
		{
			info = L"强化大成功";
			atk_temp += atk * 0.3 > 0 ? atk * 0.3 : 1;
			def_temp += def * 0.3 > 0 ? def * 0.3 : 1;
			act_num = 0;
			return;
		}
		else if (rand_num >= 100)
		{
			info=L"强化失败";
			act_num = 0;
			return;
		}
		else
		{
			info=L"强化成功";
			atk_temp += atk * 0.1 > 0 ? atk * 0.1 : 1;
			def_temp += def * 0.1 > 0 ? def * 0.1 : 1;
			act_num = 0;
			return;
		}
	}
	else if (r == 3) {
		double rand_num = rand() % 100 + 1;
		if (rand_num <= 10)
		{
			info=L"魔曲大成功";
			act_num = hp_c + 10;
			return;
		}
		else if (rand_num > 10 && rand_num <= 30) {
			info = L"魔曲小成功";
			act_num = hp_c * 0.5;
			return;
		}
		else if (rand_num > 30 && rand_num <= 60)
		{
			info = L"魔曲成功";
			act_num = hp_c;
			return;
		}
		else
		{
			info = L"魔曲失败,反噬自身";
			act_num = 0;
			hp_temp = hp_temp - hp_c * 0.1;
			return;
		}
	}
	else if (r == 4) {
		double rand_num = rand() % 110 + 1;
		if (rand_num <= hp_b)
		{
			info = L"回复大成功";
			hp_temp += hp * 0.4 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
		else if (rand_num >= 80)
		{
			info = L"回复失败";
			act_num = 0;
			return;
		}
		else
		{
			info = L"回复成功";
			hp_temp += hp * 0.2 + 1;
			if (hp_temp > hp)
				hp_temp = hp;
			act_num = 0;
			return;
		}
	}
}
void player_s::pd() {
		if (actor == 1)
		{
			output_atk = act_num;
			return;
		}
		else if (actor == 2 || actor == 4)
		{
			output_atk = 0;
			return;
		}
		else if (actor == 3)
		{
			output_atk = -act_num;
			return;
		}
}
double player_s::op_atk() {
	return output_atk;
}
double player_s::gethp() {
	return hp_temp;
}
void player_s::ATKUP() 
{
	atk += 5+atk/30;
	def += 1;
	hp += 10;
	hp_temp+=10;
}
void player_s::DEFUP()
{
	atk += 1;
	def += 5+def/30;
	hp += 10;
	hp_temp += 10;
}
void player_s::HPUP()
{
	atk += 1;
	def += 1;
	hp += 25;
	hp_temp += 25;
}
void player_s::HP_CUP()
{
	if (hp_c < 30) 
	{
		hp_c += 3;
		hp += 15;
		def += 3;
	}
	else if (hp_c > 30)
	{
		hp += 30;
		def += 4 + def / 50;
	}
}
void player_s::statusreset() 
{
	atk_temp = atk;
	def_temp = def;
}