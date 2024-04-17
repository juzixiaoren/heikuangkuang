#include<iostream>
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y);//光标移动
typedef struct//球的结构体
{
	int m_x;
	int m_y;
	char m_char;
}Ball;
#define WIDTH (155)//宽度
#define HEIGHT (43)//高度
typedef struct //视口结构体
{
	char m_buffer[WIDTH * HEIGHT];//缓冲区
}Viewport;
void ViewportToScreen(Viewport* viewport)//视口到屏幕
{
	for (int y = 0; y < HEIGHT; y++)//遍历高度
	{
		for (int x = 0; x < WIDTH; x++)//遍历宽度
		{
			int index = x + y * WIDTH;//索引
			char ch = viewport->m_buffer[index];//字符
			if (ch) //如果字符不为空
			{
				gotoxy(x, y);//移动光标
				cout << ch;//输出字符
			}
		}
		cout << endl;//换行
	}
}
void Delay()//延迟
{
	Sleep(100);
};
void gotoxy(int x, int y) {
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//设置光标位置
}
void CleanScreen(Viewport* viewport)//清屏
{
	//system("cls");
	memset(viewport, 0, sizeof(*viewport));//清空缓冲区
}
void RenderBall(Viewport* viewport, Ball* b)//渲染球
{
	/*gotoxy(b->m_x,b->m_y);
	cout<<b->m_char;*/
	int index = b->m_x + b->m_y * WIDTH;//索引
	viewport->m_buffer[index] = b->m_char;//缓冲区赋值

}
void screen_output() {
	Viewport buffer = { 0 };//视口
	int frame = 0;//帧数
	Ball b1, b2;//球
	b1.m_x = 154;//初始化球1
	b1.m_y = 42;//初始化球2
	b1.m_char = 'A';
	b2.m_x = 154;
	b2.m_y = 42;
	b2.m_char = 'B';
	for (;;)
	{
		CleanScreen(&buffer);//清屏
		Delay();
		RenderBall(&buffer, &b1);//渲染点1
		Delay();
		RenderBall(&buffer, &b2);//渲染点2
		Delay();
		ViewportToScreen(&buffer);//视口到屏幕
		gotoxy(0, 0);
		cout << frame;
		Delay();
		frame++;
	}

}
