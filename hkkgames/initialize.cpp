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
	wchar_t title[] = L"��ֵĴ�ð��";
	SetConsoleTitle(title);
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(),GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
	/* ���ô�����Ϣ ��� ȡ�����������߿� */
	SetWindowLong(hwnd, GWL_STYLE, l_WinStyle & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx-1, cy-1, 0);	 /* ���ô���λ�� */
}
void FullScreen() {
	HANDLE Hand;
	CONSOLE_SCREEN_BUFFER_INFO Info;
	Hand = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ��׼������
	GetConsoleScreenBufferInfo(Hand, &Info);//��ȡ��������Ϣ
	int cx = GetSystemMetrics(SM_CXSCREEN);/* ��Ļ��� ���� */
	int cy = GetSystemMetrics(SM_CYSCREEN);/* ��Ļ�߶� ���� */
	COORD size = { cy,cx };	//���建������С�����ֻ�������С����Ļ��Сһ�¼���ȡ���߿� 
	SetConsoleScreenBufferSize(Hand, size);	//���û�������С
}
#ifndef TEST_H
#define TEST_H
#endif