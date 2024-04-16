#include"header.h"
#include"initialize.h"
using namespace std;
// #include"main.cpp"
// #include"functions.cpp"
// #include"classes.cpp"
// #include"variables.cpp"
// #include"functions.h"
// #include"classes.h"
// #include"variables.h"
// #include"main.h"
int main() {
	srand(time(0));
	FullScreen();
	gui_size();
	titlecout();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE| FOREGROUND_GREEN);
	cout << "按任意键开始游戏" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cin.get();
	system("cls");
	string name="NULL";
	while (name == "NULL") {
		cout << "请输入名字"<<endl<<"你的名字是:";
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
	return 0;
}