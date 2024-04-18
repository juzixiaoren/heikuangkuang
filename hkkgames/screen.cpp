#include<iostream>
#include<Windows.h>
#include"header.h"
using namespace std;
void gotoxy(int x, int y);//光标移动
typedef struct//主角的结构体
{
	int m_x;
	int m_y;
	char m_char;
}Protagonist;
#define WIDTH (155)//宽度
#define HEIGHT (43)//高度

typedef struct //视口结构体
{
	char m_buffer[WIDTH * HEIGHT];//缓冲区
}Viewport;

void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer)//视口到屏幕
{
	for (int y = 0; y < HEIGHT; y++)//遍历高度
	{
		for (int x = 0; x < WIDTH; x++)//遍历宽度
		{
			int index = x + y * WIDTH;//索引
			char ch = back_buffer->m_buffer[index];//字符
			if (ch != front_buffer->m_buffer[index]) //如果字符不为空
			{
				gotoxy(x, y);//移动光标
				cout << ch;//输出字符
				front_buffer->m_buffer[index] = ch;//赋值
			}
		}
		cout << endl;//换行
	}
}
void PrintFrame(Viewport* back_buffer, int frame)
{
	//打印帧数
	char str[255];//字符串
	sprintf_s(str,255, "Frame:%d", frame);//格式化字符串
	for (int i = 0, max_i = strlen(str); i < max_i; i++)//遍历字符串
	{
		back_buffer->m_buffer[i] = str[i];//赋值
	}
}
void Delay()//延迟
{
	Sleep(1500);
};
void gotoxy(int x, int y) {
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//设置光标位置
}

void CleanScreen(Viewport* back_buffer)//清屏
{
	//system("cls");
	memset(back_buffer, 0, sizeof(*back_buffer));//清空缓冲区
}

void RenderProt(Viewport* back_buffer, Protagonist* prot)//渲染主角位置
{
	/*gotoxy(b->m_x,b->m_y);
	cout<<b->m_char;*/
	int index = prot->m_x + prot->m_y * WIDTH;//索引
	back_buffer->m_buffer[index] = prot->m_char;//缓冲区赋值
}
void screen_input(Viewport* back_buffer) 
{
	ifstream file("test.txt");
	if (!file.is_open()) {
		cerr << "无法打开文件 test.txt" << endl;
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
	Viewport buffers[2] = { 0 };//视口
	int front_index, back_index;//前后索引
	int frame = 0;//帧数
	front_index = 0;
	back_index = 1;
	Protagonist prot;//主角
	prot.m_x = 5;
	prot.m_y = 4;
	prot.m_char ='O';
	for (;;)
	{
		CleanScreen(&buffers[back_index]);

		screen_input(&buffers[back_index]);

		//RenderProt(&buffers[back_index], &prot);

		//PrintFrame(&buffers[back_index], frame);//打印帧数

		ViewportToScreen(&buffers[back_index], &buffers[front_index]);//视口到屏幕
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
