#include "header.h"
using namespace std;
void titlecout() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
	ifstream file("title.txt");
	string line;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE| FOREGROUND_GREEN);
	int i = 0;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}
void gui_size(){
	wchar_t title[] = L"奇怪的大冒险";
	SetConsoleTitle(title);
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(),GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	/* 设置窗口信息 最大化 取消标题栏及边框 */
	SetWindowLong(hwnd, GWL_STYLE, l_WinStyle & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx-1, cy-1, 0);	 /* 设置窗口位置 */
}
void FullScreen() {
	HANDLE Hand;
	CONSOLE_SCREEN_BUFFER_INFO Info;
	Hand = GetStdHandle(STD_OUTPUT_HANDLE);	//获取标准输出句柄
	GetConsoleScreenBufferInfo(Hand, &Info);//获取缓冲区信息
	int cx = GetSystemMetrics(SM_CXSCREEN);/* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);/* 屏幕高度 像素 */
	COORD size = { cy,cx };	//定义缓冲区大小，保持缓冲区大小和屏幕大小一致即可取消边框 
	SetConsoleScreenBufferSize(Hand, size);	//设置缓冲区大小
}
#ifndef TEST_H
#define TEST_H
#endif