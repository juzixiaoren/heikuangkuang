#include "header.h"
using namespace std;
void titlecout() {
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
	short width = 1000;//设置窗体大小
	short height = 500;//设置窗体大小
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄
	SMALL_RECT wrt = { 0, 0, width - 1, height - 1 };//设置窗体大小
	SetConsoleWindowInfo(hStdOutput, TRUE, &wrt); // 设置窗体尺寸
	COORD coord = { width, height };//设置缓冲区大小
	SetConsoleScreenBufferSize(hStdOutput, coord); // 设置缓冲尺寸
	//wchar_t title[] = L"奇怪的大冒险";
	//SetConsoleTitle(title);
	//SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	HWND hwnd = GetForegroundWindow();				  /* 获取窗口句柄 */
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
	//SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(),GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	//LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	//SetWindowLong(hwnd, GWL_STYLE, l_WinStyle & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX & ~WS_SYSMENU); /* 设置窗口风格 */
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, SWP_SHOWWINDOW); /* 设置窗口位置 */
}
//void FullScreen() {
//	HANDLE Hand;//定义句柄
//	CONSOLE_SCREEN_BUFFER_INFO Info;//定义缓冲区信息结构体
//	Hand = GetStdHandle(STD_OUTPUT_HANDLE);	//获取标准输出句柄
//	GetConsoleScreenBufferInfo(Hand, &Info);//获取缓冲区信息
//	COORD size = {89,100};	//定义缓冲区大小，保持缓冲区大小和屏幕大小一致即可取消边框
//	SetConsoleScreenBufferSize(Hand, size);	//设置缓冲区大小
//	SMALL_RECT rect = { 0, 0, 89, 100};//定义窗口大小，保持窗口大小和缓冲区大小一致即可取消滚动条
//	SetConsoleWindowInfo(Hand, 1, &rect);//设置窗口大小
//	cout << SetConsoleScreenBufferSize(Hand, size) << endl;
//}
void log_cout(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(50);
	}
}
void Hkk_initialize() {
	gui_size();
	//FullScreen();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	log_cout("加载中 █ █ █ ");
	system("cls");
	titlecout();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
	string a = "口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口开始游戏口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口";
	cout<<a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin.get();
	system("cls");
	string name = "NULL";
	while (name == "NULL") {
		cout << "请输入名字" << endl << "你的名字是:";
		getline(cin, name);
	}
	cout << "Hello, " << name << "!" << endl;
	cout << "Press any key to continue..." << endl;
	cin.get();
	system("cls");
	cout << "Please select a game to play:" << endl;
	cout << "1. Tic-Tac-Toe" << endl;
	cout << "2. Hangman" << endl;
	cout << "3. Rock-Paper-Scissors" << endl;
	cout << "4. Exit" << endl;
	int choice;
	cout << "Press any key to exit..." << endl;
	cin.get();
	cin.get();
}
#ifndef TEST_H
#define TEST_H
#endif