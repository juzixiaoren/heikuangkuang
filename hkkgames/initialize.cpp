#include "header.h"
using namespace std;
void titlecout() {//输出标题
	ifstream file("title.txt");
	string line;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE| FOREGROUND_GREEN);
	int i = 0;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}
void log_cout(string a)//实现一个一个字符输出
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(50);
	}
}
void gui_size(){//设置缓冲区大小，全屏手动全屏
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scr_buff;
	COORD cd;
	cd.X = 155;
	cd.Y = 43;
	if (!SetConsoleScreenBufferSize(hcon, cd)) {
		printf("error\n");
	}
	if (GetConsoleScreenBufferInfo(hcon, &scr_buff)) {

		printf("缓冲区设置成功：X : %d,Y : %d\n", scr_buff.dwSize.X, scr_buff.dwSize.Y);

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	system("pause");
	log_cout("加载中 █ █ █ ");
}

void Hkk_initialize() {//初始化
	gui_size();
	system("cls");
	titlecout();//输出标题
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN);
	string a = "口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口开始游戏口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口口";
	cout<<a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin.get();
	system("cls");
	/*string name = "NULL";
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
	cin.get();*/
}
#ifndef TEST_H
#define TEST_H
#endif