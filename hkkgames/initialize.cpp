#include "header.h"
using namespace std;
void titlecout() {//�������
	FILE* fileptr = fopen("title.txt", "r");
	if (fileptr == nullptr) {
		std::cout << "error oprning file" << endl;
		std::exit(EXIT_FAILURE);
	}
	const size_t buffersize = 6665;//���������ݵĳ��ȶ�Ӧ��������С
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
		Sleep(10);
	}
}
static void rule_out() {
	//�������
	FILE* fileptr = fopen("rule.txt", "r");
	if (fileptr == nullptr) {
		std::cout << "error oprning file" << endl;
		std::exit(EXIT_FAILURE);
	}
	const size_t buffersize = 6665;//���������ݵĳ��ȶ�Ӧ��������С
	char buffer[buffersize]{};
	char* ptr = buffer;//ָ��buffer��������ָ��
	size_t bytesRead = 0;//��ȡ���ֽ���
	while ((bytesRead = fread(ptr, sizeof(char), buffersize - 1, fileptr)) > 0) {//��ȡ�ļ�
			buffer[bytesRead] = '\0';
			std::cout << buffer << std::endl;
		}
	fclose(fileptr);

}
static void pic_out() {
	//�������
	FILE* fileptr = fopen("intro.txt", "r");
	if (fileptr == nullptr) {
		std::cout << "error oprning file" << endl;
		std::exit(EXIT_FAILURE);
	}
	const size_t buffersize = 6665;//���������ݵĳ��ȶ�Ӧ��������С
	char buffer[buffersize]{};
	char* ptr = buffer;//ָ��buffer��������ָ��
	size_t bytesRead = 0;//��ȡ���ֽ���
	while ((bytesRead = fread(ptr, sizeof(char), buffersize - 1, fileptr)) > 0) {//��ȡ�ļ�
		buffer[bytesRead] = '\0';
		std::cout << buffer << std::endl;
	}
	fclose(fileptr);

}
void hide_cursor()//���ع��
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}

void gui_size(){//���û�������С��ȫ���ֶ�ȫ��
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
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
	system("pause");
	pic_out();
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	rule_out();
	system("pause");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	log_cout("��Ϸ������ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
}
#pragma comment (lib,"winmm.lib")
void Hkk_initialize() {//��ʼ��
	gui_size();
	hide_cursor();
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
void music() {
	Sleep(100);
	while (1)
	{
		if (0 == PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_LOOP))
		{
			printf("playsound false");
		}
	}
}
#ifndef TEST_H
#define TEST_H
#endif