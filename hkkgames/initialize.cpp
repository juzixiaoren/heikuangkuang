#include "header.h"
using namespace std;
void titlecout() {//�������
	FILE* fileptr = fopen("title.txt", "r");
	if (fileptr == nullptr) {
		std::cout << "error oprning file" << endl;
		std::exit(EXIT_FAILURE);
	}
	const size_t buffersize = 6665;
	char buffer[buffersize]{};
	char* ptr = buffer;//ָ��buffer��������ָ��
	size_t bytesRead = 0;//��ȡ���ֽ���
	while ((bytesRead = fread(ptr, sizeof(char), buffersize - 1, fileptr)) > 0) {//��ȡ�ļ�
		buffer[bytesRead] = '\0';
		std::cout << buffer << std::endl;
	}
	fclose(fileptr);
}
void log_cout(string a)//ʵ��һ��һ���ַ����
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(50);
	}
}
void gui_size(){//���û�������С��ȫ���ֶ�ȫ��
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scr_buff;
	COORD cd;
	cd.X = 310;
	cd.Y = 43;
	if (!SetConsoleScreenBufferSize(hcon, cd)) {//���û�������С
		printf("error\n");
	}
	if (GetConsoleScreenBufferInfo(hcon, &scr_buff)) {

		printf("���������óɹ���X : %d,Y : %d\n", scr_buff.dwSize.X, scr_buff.dwSize.Y);

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	system("pause");
	log_cout("������ �� �� �� ");
}

void Hkk_initialize() {//��ʼ��
	gui_size();
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	/*string name = "NULL";
	while (name == "NULL") {
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