#include<iostream>
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y);//����ƶ�
typedef struct//��Ľṹ��
{
	int m_x;
	int m_y;
	char m_char;
}Ball;
#define WIDTH (155)//���
#define HEIGHT (43)//�߶�
typedef struct //�ӿڽṹ��
{
	char m_buffer[WIDTH * HEIGHT];//������
}Viewport;
void ViewportToScreen(Viewport* viewport)//�ӿڵ���Ļ
{
	for (int y = 0; y < HEIGHT; y++)//�����߶�
	{
		for (int x = 0; x < WIDTH; x++)//�������
		{
			int index = x + y * WIDTH;//����
			char ch = viewport->m_buffer[index];//�ַ�
			if (ch) //����ַ���Ϊ��
			{
				gotoxy(x, y);//�ƶ����
				cout << ch;//����ַ�
			}
		}
		cout << endl;//����
	}
}
void Delay()//�ӳ�
{
	Sleep(100);
};
void gotoxy(int x, int y) {
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//���ù��λ��
}
void CleanScreen(Viewport* viewport)//����
{
	//system("cls");
	memset(viewport, 0, sizeof(*viewport));//��ջ�����
}
void RenderBall(Viewport* viewport, Ball* b)//��Ⱦ��
{
	/*gotoxy(b->m_x,b->m_y);
	cout<<b->m_char;*/
	int index = b->m_x + b->m_y * WIDTH;//����
	viewport->m_buffer[index] = b->m_char;//��������ֵ

}
void screen_output() {
	Viewport buffer = { 0 };//�ӿ�
	int frame = 0;//֡��
	Ball b1, b2;//��
	b1.m_x = 154;//��ʼ����1
	b1.m_y = 42;//��ʼ����2
	b1.m_char = 'A';
	b2.m_x = 154;
	b2.m_y = 42;
	b2.m_char = 'B';
	for (;;)
	{
		CleanScreen(&buffer);//����
		Delay();
		RenderBall(&buffer, &b1);//��Ⱦ��1
		Delay();
		RenderBall(&buffer, &b2);//��Ⱦ��2
		Delay();
		ViewportToScreen(&buffer);//�ӿڵ���Ļ
		gotoxy(0, 0);
		cout << frame;
		Delay();
		frame++;
	}

}
