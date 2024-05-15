#include"header.h"
#include"Startgame.h"
#include"controller.h"
#include"screen.h"
#include "fight.h"
using namespace std;
extern int mapid;
extern int coord_xy[10][2];
extern int Status;
extern controller player;
extern int info;
extern Viewport buffers[2];
extern int front_index;
extern int back_index;
extern player_s Playerinfo;
extern int fightinfo;
extern vector <enemy_s> enemyinfo;
void Startgame()
{
	player.m_char = L'��';
	mapid = 1;
	coord_xy[0][0] = 35;//��ʾ���Ļ��Χ
	coord_xy[0][1] = 30;
	Status = 1;
}

void showstorys() {
	
	wifstream file("�ı�1.txt");//���ļ�
	file.imbue(locale("zh_CN"));//��txt������Ի�������Ϊzh_CN
	if (!file.is_open()) {
		perror("���ļ��ı�1.txtʧ����");
		cerr << "�޷����ļ� �ı�1.txt" << endl;
		return;
	}
	wstring line;
	wchar_t ch;
	int index;
	for (int y = 0; y < HEIGHT && getline(file, line); y++) {
		index = y * WIDTH;
		for (int x = 0; x < WIDTH; x++) {
			if (x > line.length()) {
				ch = L' ';
				buffers[back_index].m_buffer[index] = ch;
				index++;
			}
			else if (line[x] > 255) {//�����ַ�
				ch = line[x];
				buffers[back_index].m_buffer[index] = ch;
				buffers[back_index].m_buffer[index + 1] = 0;
				index += 2;//�����ַ�ռ�����ַ�λ��
			}
			else {//Ӣ���ַ�
				ch = line[x];
				buffers[back_index].m_buffer[index] = ch;
				index++;
			}
		}
	}
	file.close();
}
void showstorys_2() {

	wifstream file("kobe.txt");//���ļ�
	file.imbue(locale("zh_CN"));//��txt������Ի�������Ϊzh_CN
	if (!file.is_open()) {
		perror("���ļ��ı�1.txtʧ����");
		cerr << "�޷����ļ� �ı�1.txt" << endl;
		return;
	}
	wstring line;
	wchar_t ch;
	int index;
	for (int y = 0; y < HEIGHT && getline(file, line); y++) {
		index = y * WIDTH;
		for (int x = 0; x < WIDTH; x++) {
			if (x > line.length()) {
				ch = L' ';
				buffers[back_index].m_buffer[index] = ch;
				index++;
			}
			else if (line[x] > 255) {//�����ַ�
				ch = line[x];
				buffers[back_index].m_buffer[index] = ch;
				buffers[back_index].m_buffer[index + 1] = 0;
				index += 2;//�����ַ�ռ�����ַ�λ��
			}
			else {//Ӣ���ַ�
				ch = line[x];
				buffers[back_index].m_buffer[index] = ch;
				index++;
			}
		}
	}
	file.close();
}
void showbaseinfo() {
	wifstream file("baseinfo.txt");//���ļ�
	file.imbue(locale("zh_CN"));//��txt������Ի�������Ϊzh_CN
	if (!file.is_open()) {
		perror("���ļ��ı�1.txtʧ����");
		cerr << "�޷����ļ� �ı�1.txt" << endl;
		return;
	}
	wstring line;
	wchar_t ch;
	int index;
	for (int y = 0; y < HEIGHT && getline(file, line); y++) {
		index = y * WIDTH;
		for (int x = 0; x < WIDTH; x++) {
			if (x > line.length()) {
				break;
			}
			else if (line[x] == L' ')
			{
				index++;
				continue;
			}
			else if (line[x] > 255) {//�����ַ�
				ch = line[x];
				buffers[back_index].m_buffer[index] = ch;
				buffers[back_index].m_buffer[index + 1] = 0;
				index += 2;//�����ַ�ռ�����ַ�λ��
			}
			else {//Ӣ���ַ�
				ch = line[x];
				buffers[back_index].m_buffer[index] = ch;
				index++;
			}
		}
	}
	file.close();
}
void showfightinfo() {
	wifstream file("fightinfo.txt");//���ļ�
	file.imbue(locale("zh_CN"));//��txt������Ի�������Ϊzh_CN
	if (!file.is_open()) {
		perror("���ļ��ı�1.txtʧ����");
		cerr << "�޷����ļ� �ı�1.txt" << endl;
		return;
	}
	wstring line;
	wchar_t ch;
	int index;
	for (int y = 0; y < HEIGHT && getline(file, line); y++) {
		index = y * WIDTH;
		for (int x = 0; x < WIDTH; x++) {
			if (x > line.length()) {
				break;
			}
			else if (line[x] == L' ')
			{
				index++;
				continue;
			}
			else if (line[x] > 255) {//�����ַ�
							ch = line[x];
							buffers[back_index].m_buffer[index] = ch;
							buffers[back_index].m_buffer[index + 1] = 0;
							index += 2;//�����ַ�ռ�����ַ�λ��
						}
			else {//Ӣ���ַ�
							ch = line[x];
							buffers[back_index].m_buffer[index] = ch;
							index++;
						}
		}
	}
	file.close();
}
void loadothers() {
	switch (info)
	{
	case 1: {
		showstorys();
		if (Timer(10000, 2))
			info = 2;
		break;
	}
	case 2: {
		showstorys_2();
		if (Timer(20000, 3)) {
			info = 3;
			player.m_char = L'��';
			player.x = 1;
			player.y = 1;
			mapid = 2;
			memset(coord_xy, NULL, sizeof(coord_xy));
			coord_xy[0][0] = 56; coord_xy[0][1] = 22;
			coord_xy[1][0] = 6; coord_xy[1][1] =31;
			coord_xy[2][0] = 41; coord_xy[2][1] = 35;
			Status = 2;
		}
		break;
	}
	case 3: {
		showbaseinfo();
		Playerinfo.showplayerinfo();
		break;
	}
	case 4:
	{
		Status = 3;
		if (!fightinfo) 
		{
			showbaseinfo();
		}
		else {
			showfightinfo();
			enemyinfo[0].showenemyinfo();
		}
		Playerinfo.showplayerinfo();
		break;
	}
	case 5:
	{
		Status = 4;
		if (!fightinfo)
		{
			showbaseinfo();
		}
		else {
			showfightinfo();
			enemyinfo[0].showenemyinfo();
		}
		Playerinfo.showplayerinfo();
		break;
	}
	case 6:
	{
		Status = 5;
		if (!fightinfo)
		{
			showbaseinfo();
		}
		else {
			showfightinfo();
			enemyinfo[0].showenemyinfo();
		}
		Playerinfo.showplayerinfo();
		break;
	}
	default:
		break;
	}
}