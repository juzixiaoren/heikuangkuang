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
	player.m_char = L'��';
	mapid = 1;
	coord_xy[0][0] = 35;//��ʾ���Ļ��Χ
	coord_xy[0][1] = 33;
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
				buffers[1].m_buffer[index] = ch;
				index++;
			}
			else if (line[x] > 255) {//�����ַ�
				ch = line[x];
				buffers[1].m_buffer[index] = ch;
				buffers[1].m_buffer[index + 1] = 0;
				index += 2;//�����ַ�ռ�����ַ�λ��
			}
			else {//Ӣ���ַ�
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