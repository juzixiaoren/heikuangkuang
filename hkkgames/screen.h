#pragma once
void gotoxy(int x, int y);//����ƶ�
typedef struct{}Ball;//��ṹ��
typedef struct {}Viewport;//�ӿڽṹ��
void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer);
void Delay();
void gotoxy(int x, int y);
void CleanScreen(Viewport* viewport);//����
void RenderBall(Viewport* viewport, Ball* b);//��Ⱦ��
void screen_output(); 
//���߶�������42,�����������154