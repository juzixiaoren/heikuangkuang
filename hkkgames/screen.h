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
void loadMapFile(Viewport* back_buffer, const std::wstring& mapFile);//加载地图文件

#endif
//最大高度索引是42,最大宽度索引是154