#pragma once
void gotoxy(int x, int y);//����ƶ�
#define WIDTH (155)//���
#define HEIGHT (43)//�߶�
typedef struct//���ǵĽṹ��
{
	int m_x;
	int m_y;
	wchar_t m_char;
}Protagonist;

typedef struct //�ӿڽṹ��
{
	wchar_t m_buffer[WIDTH * HEIGHT];//������
}Viewport;


void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer);
void Delay();
void gotoxy(int x, int y);
void CleanScreen(Viewport* viewport);//����
void RenderProt(Viewport* viewport, Protagonist* prot);//��Ⱦ��
void screen_output(); //��Ļ���
void screen_input(Viewport* back_buffer);//��Ļ����

//���߶�������42,�����������154