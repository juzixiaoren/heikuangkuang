#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "controller.h"
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


void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer);//�ӿڵ���Ļ
void Delay();//�ӳ�
void gotoxy(int x, int y);
void CleanScreen(Viewport* viewport);//����
void RenderProt(Viewport* viewport, Protagonist* prot);//��Ⱦ����
void screen_output(); //��Ļ���
void screen_input(Viewport* back_buffer);//��Ļ����
void clear_preRenderProt(Viewport* back_buffer, controller* player);//�����һ�ε�����
bool Canmove(controller* player, Viewport* front_buffer, Protagonist* prot);//����Ƿ�����ƶ�
std::wstring selectMapFile(int gameLevel);//ѡ���ͼ�ļ�
void loadMapFile(Viewport* back_buffer, const std::wstring& mapFile);//���ص�ͼ�ļ�
void Coordinate();//�����ж�
int Coordinate_judgment(int coord_xy[][2], controller* player);//�����ж�
bool Timer(long long ms, int id);//��ʱ��
BOOL MByteToWChar_t(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);//���ֽ�ת���ֽ�
BOOL WCharToMByte_t(LPCWSTR lpwszStr, LPSTR lpszStr, DWORD dwSize);//���ֽ�ת���ֽ�
std::wstring to_wide_string(const std::string& input);
std::string to_byte_string(const std::wstring& input);
std::wstring clean_wstring(const std::wstring& w_string);
#endif
//���߶�������42,�����������154