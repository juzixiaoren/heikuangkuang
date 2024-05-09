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
extern int front_index;
extern int back_index;

void Startgame()
{
	player.m_char = L'开';
	mapid = 1;
	coord_xy[0][0] = 35;//表示光标的活动范围
	coord_xy[0][1] = 33;
	Status = 1;
}

void showstorys() {
	
	wifstream file("文本1.txt");//打开文件
	file.imbue(locale("zh_CN"));//把txt里的语言环境设置为zh_CN
	if (!file.is_open()) {
		perror("打开文件文本1.txt失败啦");
		cerr << "无法打开文件 文本1.txt" << endl;
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
				buffers[1].m_buffer[index] = ch;
				index++;
			}
			else if (line[x] > 255) {//中文字符
				ch = line[x];
				buffers[1].m_buffer[index] = ch;
				buffers[1].m_buffer[index + 1] = 0;
				index += 2;//中文字符占两个字符位置
			}
			else {//英文字符
				ch = line[x];
				buffers[1].m_buffer[index] = ch;
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
		break;
	}
	default:
		break;
	}
}