#include<iostream>
#include<Windows.h>
#include"header.h"
using namespace std;
void gotoxy(int x, int y);//����ƶ�
typedef struct//���ǵĽṹ��
{
	int m_x;
	int m_y;
	char m_char;
}Protagonist;
#define WIDTH (155)//���
#define HEIGHT (43)//�߶�

typedef struct //�ӿڽṹ��
{
	char m_buffer[WIDTH * HEIGHT];//������
}Viewport;

void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer)//�ӿڵ���Ļ
{
	for (int y = 0; y < HEIGHT; y++)//�����߶�
	{
		for (int x = 0; x < WIDTH; x++)//�������
		{
			int index = x + y * WIDTH;//����
			char ch = back_buffer->m_buffer[index];//�ַ�
			if (ch != front_buffer->m_buffer[index]) //����ַ���Ϊ��
			{
				gotoxy(x, y);//�ƶ����
				cout << ch;//����ַ�
				front_buffer->m_buffer[index] = ch;//��ֵ
			}
		}
		cout << endl;//����
	}
}
void PrintFrame(Viewport* back_buffer, int frame)
{
	//��ӡ֡��
	char str[255];//�ַ���
	sprintf_s(str,255, "Frame:%d", frame);//��ʽ���ַ���
	for (int i = 0, max_i = strlen(str); i < max_i; i++)//�����ַ���
	{
		back_buffer->m_buffer[i] = str[i];//��ֵ
	}
}
void Delay()//�ӳ�
{
	Sleep(1500);
};
void gotoxy(int x, int y) {
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//���ù��λ��
}

void CleanScreen(Viewport* back_buffer)//����
{
	//system("cls");
	memset(back_buffer, 0, sizeof(*back_buffer));//��ջ�����
}

void RenderProt(Viewport* back_buffer, Protagonist* prot)//��Ⱦ����λ��
{
	/*gotoxy(b->m_x,b->m_y);
	cout<<b->m_char;*/
	int index = prot->m_x + prot->m_y * WIDTH;//����
	back_buffer->m_buffer[index] = prot->m_char;//��������ֵ
}
void screen_input(Viewport* back_buffer) 
{
	ifstream file("test.txt");
	if (!file.is_open()) {
		cerr << "�޷����ļ� test.txt" << endl;
		return;
	}

	string line;
	int y = 0;
	int index = 0;
	while (getline(file, line) && y < HEIGHT-1) 
	{
		for (int x = 0; x < WIDTH; x++) 
		{
			index = x + y * WIDTH;
			if (x < line.length()) {
				if (line[x] != ' ' && line[x] != '\n' && line[x] != 0)
					back_buffer->m_buffer[index] = line[x];
			}
		}
		y++;
	}
	file.close();
}
void screen_output() 
{
	Viewport buffers[2] = { 0 };//�ӿ�
	int front_index, back_index;//ǰ������
	int frame = 0;//֡��
	front_index = 0;
	back_index = 1;
	Protagonist prot;//����
	prot.m_x = 5;
	prot.m_y = 4;
	prot.m_char ='O';
	for (;;)
	{
		CleanScreen(&buffers[back_index]);

		screen_input(&buffers[back_index]);

		//RenderProt(&buffers[back_index], &prot);

		//PrintFrame(&buffers[back_index], frame);//��ӡ֡��

		ViewportToScreen(&buffers[back_index], &buffers[front_index]);//�ӿڵ���Ļ
		Delay();


		//swap index
		{
			int temp = back_index;
			back_index = front_index;
			front_index = temp;
		}
		frame++;
	}
}
