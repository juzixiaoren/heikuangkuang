#pragma once
void gotoxy(int x, int y);//光标移动
typedef struct{}Ball;//球结构体
typedef struct {}Viewport;//视口结构体
void ViewportToScreen(Viewport* viewport);
void Delay();
void gotoxy(int x, int y);
void CleanScreen(Viewport* viewport);//清屏
void RenderBall(Viewport* viewport, Ball* b);//渲染球
void screen_output(); 
//最大高度索引是42,最大宽度索引是154