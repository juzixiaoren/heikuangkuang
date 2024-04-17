#include"header.h"
#include"initialize.h"
#include"class_fight.cpp"
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
	int i = 1;
	enemy_s *A=new enemy_s("测试用小怪A",100,10,10,10,10,10);
	enemy_s* B = new enemy_s("测试用小怪B", 100, 10, 10, 10, 10, 10);
	while (i) {
		B->Be_attacked(A->pd(A->acts()));
		system("pause");
		A->Be_attacked(B->pd(B->acts()));
	}
	//Hkk_initialize();
	return 0;
}