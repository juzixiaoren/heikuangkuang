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
	player.m_char = L'开';
	mapid = 1;
	coord_xy[0][0] = 35;
	coord_xy[0][1] = 33;
	Status = 1;
}
void showstorys() {
	{
		system("cls");
		wifstream file(L"文本1.txt");//打开文件
		file.imbue(locale("zh_CN"));//把txt里的语言环境设置为zh_CN
		if (!file.is_open()) {
			perror("打开文件文本2.txt失败啦");
			cerr << "无法打开文件 文本2.txt" << endl;
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