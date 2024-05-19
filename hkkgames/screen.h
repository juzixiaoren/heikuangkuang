#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "controller.h"
void gotoxy(int x, int y);//光标移动
#define WIDTH (155)//宽度
#define HEIGHT (43)//高度

typedef struct//主角的结构体
{
	int m_x;
	int m_y;
	wchar_t m_char;
}Protagonist;

typedef struct //视口结构体
{
	wchar_t m_buffer[WIDTH * HEIGHT];//缓冲区
}Viewport;


void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer);//视口到屏幕
void Delay();//延迟
void gotoxy(int x, int y);
void CleanScreen(Viewport* viewport);//清屏
void RenderProt(Viewport* viewport, Protagonist* prot);//渲染主角
void screen_output(); //屏幕输出
void screen_input(Viewport* back_buffer);//屏幕输入
void clear_preRenderProt(Viewport* back_buffer, controller* player);//清除上一次的主角
bool Canmove(controller* player, Viewport* front_buffer, Protagonist* prot);//检查是否可以移动
std::wstring selectMapFile(int gameLevel);//选择地图文件
std::wstring selectEnemyFile(int enemyid);//选择敌人文件
void loadMapFile(Viewport* back_buffer, const std::wstring& mapFile);//加载地图文件
void Coordinate();//坐标判断
int Coordinate_judgment(int coord_xy[][2], controller* player);//坐标判断
void Coordinate_judgment_fiht(controller* player);//坐标判断
bool Timer(long long ms, int id);//计时器
void loadenemy(Viewport* back_buffer, const std::wstring& enemyid);//加载敌人
BOOL MByteToWChar_t(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize);//多字节转宽字节
BOOL WCharToMByte_t(LPCWSTR lpwszStr, LPSTR lpszStr, DWORD dwSize);//宽字节转多字节
std::wstring to_wide_string(const std::string& input);
std::string to_byte_string(const std::wstring& input);
std::wstring clean_wstring(const std::wstring& w_string);
#endif
//最大高度索引是42,最大宽度索引是154