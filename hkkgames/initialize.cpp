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
	short width = 1000;//���ô����С
	short height = 500;//���ô����С
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������
	SMALL_RECT wrt = { 0, 0, width - 1, height - 1 };//���ô����С
	SetConsoleWindowInfo(hStdOutput, TRUE, &wrt); // ���ô���ߴ�
	COORD coord = { width, height };//���û�������С
	SetConsoleScreenBufferSize(hStdOutput, coord); // ���û���ߴ�
	//wchar_t title[] = L"��ֵĴ�ð��";
	//SetConsoleTitle(title);
	//SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	HWND hwnd = GetForegroundWindow();				  /* ��ȡ���ھ�� */
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */
	//SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(),GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	//LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
	//SetWindowLong(hwnd, GWL_STYLE, l_WinStyle & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX & ~WS_SYSMENU); /* ���ô��ڷ�� */
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, SWP_SHOWWINDOW); /* ���ô���λ�� */
}
//void FullScreen() {
//	HANDLE Hand;//������
//	CONSOLE_SCREEN_BUFFER_INFO Info;//���建������Ϣ�ṹ��
//	Hand = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ��׼������
//	GetConsoleScreenBufferInfo(Hand, &Info);//��ȡ��������Ϣ
//	COORD size = {89,100};	//���建������С�����ֻ�������С����Ļ��Сһ�¼���ȡ���߿�
//	SetConsoleScreenBufferSize(Hand, size);	//���û�������С
//	SMALL_RECT rect = { 0, 0, 89, 100};//���崰�ڴ�С�����ִ��ڴ�С�ͻ�������Сһ�¼���ȡ��������
//	SetConsoleWindowInfo(Hand, 1, &rect);//���ô��ڴ�С
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
	log_cout("������ �� �� �� ");
	system("cls");
	titlecout();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
	string a = "�ڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿ�ʼ��Ϸ�ڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿ�";
	cout<<a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin.get();
	system("cls");
	string name = "NULL";
	while (name == "NULL") {
		cout << "����������" << endl << "���������:";
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