#include"header.h"
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
	wchar_t title[] = L"奇怪的大冒险";
	SetConsoleTitle(title);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "欢迎来到奇怪的大冒险！!" << endl;
	cout << "Press any key to continue..." << endl;
	cin.get();
	system("cls");
	cout << "Please enter your name: ";
	string name;
	getline(cin, name);
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