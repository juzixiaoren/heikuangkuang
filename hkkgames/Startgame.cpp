#include"header.h"
#include"Startgame.h"
#include"controller.h"
#include"screen.h"
using namespace std;
extern int mapid;
extern int coord_xy[10][2];
extern int Status;
extern controller player;
extern int info;
extern Viewport buffers[2];
void Startgame()
{
	player.m_char = L'��';
	mapid = 1;
	coord_xy[0][0] = 35;
	coord_xy[0][1] = 33;
	Status = 1;
}
void showstorys() {
	{
		system("cls");
		wifstream file(L"�ı�1.txt");//���ļ�
		file.imbue(locale("zh_CN"));//��txt������Ի�������Ϊzh_CN
		if (!file.is_open()) {
			perror("���ļ��ı�2.txtʧ����");
			cerr << "�޷����ļ� �ı�2.txt" << endl;
			return;
		}
		wstring line;
		wchar_t ch;
		for (int y = 0; y < HEIGHT && getline(file, line); y++)
		{
			for (int x = 0; x < WIDTH && x < line.length(); x++)
			{
				int index = x + y * WIDTH;
				ch = line[x];
				buffers[1].m_buffer[index] = ch;
			}
		}
		file.close();
	}
}
void loadothers() {
	switch (info)
	{
	case 1: {
		showstorys();
		break;
	}
	default:
		break;
	}
}