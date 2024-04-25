﻿#include"header.h"
#include"screen.h"
#include"controller.h"
using namespace std;
void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer)//视口到屏幕
{
	for (int y = 0; y < HEIGHT; y++)//遍历高度
	{
		for (int x = 0; x < WIDTH; x++)//遍历宽度
		{
			int index = x + y * WIDTH;//索引
			wchar_t ch = back_buffer->m_buffer[index];//字符
			if (ch != front_buffer->m_buffer[index])
			{
				wcout.imbue(locale("zh_CN"));
				gotoxy(x, y);
				wcout << ch;
				front_buffer->m_buffer[index] = ch; // 使用来自back_buffer的字符更新front_buffer
			}
		}
	}
}
bool Canmove(controller*player,Viewport* front_buffer, Protagonist* prot) {
	if (player->IfMove== 1)
	{
		int index = player->x*2 + (player->y-1) * WIDTH;
		if (front_buffer->m_buffer[index] != prot->m_char && (front_buffer->m_buffer[index] == 0||front_buffer->m_buffer[index]==' ')&& front_buffer->m_buffer[index+1] != prot->m_char && (front_buffer->m_buffer[index+1] == 0 || front_buffer->m_buffer[index+1] == ' '))
		{
			return true;
		}
		else 
			return false;
	}
	if (player->IfMove == 2)
	{
		int index = player->x*2 + (player->y + 1) * WIDTH;
		if (front_buffer->m_buffer[index] != prot->m_char && (front_buffer->m_buffer[index] == 0 || front_buffer->m_buffer[index] == ' ')&& front_buffer->m_buffer[index + 1] != prot->m_char && (front_buffer->m_buffer[index + 1] == 0 || front_buffer->m_buffer[index + 1] == ' '))
			return true;
		else return false;
	}
	if (player->IfMove == 3)
	{
		int index = (player->x*2) + player->y * WIDTH;
		if(front_buffer->m_buffer[index-1] != prot->m_char && (front_buffer->m_buffer[index-1] == 0 || front_buffer->m_buffer[index-1] == ' ')&& front_buffer->m_buffer[index - 2] != prot->m_char && (front_buffer->m_buffer[index - 2] == 0 || front_buffer->m_buffer[index - 2] == ' '))
			return true;
		else return false;
	}
	if (player->IfMove == 4)
	{
		int index = (player->x*2) + player->y * WIDTH;
		if(front_buffer->m_buffer[index+1] != prot->m_char && (front_buffer->m_buffer[index+1] == 0 || front_buffer->m_buffer[index+1] == ' ')&& front_buffer->m_buffer[index + 2] != prot->m_char && (front_buffer->m_buffer[index + 2] == 0 || front_buffer->m_buffer[index + 2] == ' '))
			return true;
		else 
			return false;
	}
	return true;
}
void Delay()//延迟
{
	Sleep(30);
};
void gotoxy(int x, int y) {
	COORD cd = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//设置光标位置
}

void CleanScreen(Viewport* back_buffer)//清屏
{
	//system("cls");
	memset(back_buffer, 0, sizeof(*back_buffer));//清空缓冲区
}

void RenderProt(Viewport* back_buffer, Protagonist* prot)//渲染主角
{
	int index = prot->m_x + prot->m_y * WIDTH;
	if (back_buffer->m_buffer[index] == ' ' || back_buffer->m_buffer[index] == 0)
	{
		back_buffer->m_buffer[index] = prot->m_char;
		back_buffer->m_buffer[index + 1] = 0;
	}
}
void clear_preRenderProt(Viewport* back_buffer, controller* player)//清除上一次的主角
{
	int index = player->prex*2+player->prey * WIDTH;
		back_buffer->m_buffer[index] = ' ';
		back_buffer->m_buffer[index+1] = ' ';
}
void screen_input(Viewport* back_buffer)
{
	wifstream file(L"test.txt");//打开文件
	file.imbue(locale("zh_CN"));//把txt里的语言环境设置为zh_CN
	if (!file.is_open()) {
		perror("打开文件test.txt失败啦");
		cerr << "无法打开文件 test.txt" << endl;
		return;
	}
	wstring line;
	wchar_t ch;
	for (int y = 0; y < HEIGHT && getline(file, line); y++)
	{
		for (int x = 0; x < WIDTH && x < line.length(); x++)
		{
			int index = x + y * WIDTH;
			ch = line[x];
			back_buffer->m_buffer[index] = ch;
		}
	}
	file.close();
}
void screen_output()
{
	Viewport buffers[2] = { 0 };//视口
	int front_index, back_index;//前后索引
	front_index = 0;//初始化索引
	back_index = 1;//初始化索引
	controller player(0, 37);//控制器
	Protagonist prot;//主角
	prot.m_x = 2*player.x;
	prot.m_y = player.y;
	prot.m_char = L'开';
	for (;;)
	{
		CleanScreen(&buffers[back_index]);//清屏
		loadMapFile(&buffers[back_index], selectMapFile(3));//加载地图文件
		RenderProt(&buffers[back_index], &prot);//渲染主角
		while (player.CheckIfMove()&&Canmove(&player, &buffers[front_index],&prot))//检查是否移动
		{
			if (Timer(90,1)) {
				player.Move();//移动
				prot.m_x = 2*player.x;
				prot.m_y = player.y;
				RenderProt(&buffers[back_index], &prot);//渲染主角
				clear_preRenderProt(&buffers[back_index], &player);//清除上一次的主角位置
			}
			else break;
		}
		//PrintFrame(&buffers[back_index], frame);//打印帧数

		ViewportToScreen(&buffers[back_index], &buffers[front_index]);//视口到屏幕
		Delay();


		//swap index
		{
			int temp = back_index;
			back_index = front_index;
			front_index = temp;
		}
	}
}
// 假设地图文件名存储在一个数组中
const std::vector<std::wstring> mapFiles = { L"test.txt", L"title.txt", L"map3.txt",L"test2.txt"};

// 根据游戏状态选择地图文件
wstring selectMapFile(int gameLevel) {
	if (gameLevel < mapFiles.size()) {
		return mapFiles[gameLevel];
	}
	// 如果游戏等级超出了文件列表，返回默认地图文件
	return mapFiles[0];
}

// 读取地图文件内容的函数
void loadMapFile(Viewport* back_buffer, const std::wstring& mapFile) {//加载地图文件
	wifstream file(mapFile.c_str()); // 打开文件
	file.imbue(locale("zh_CN")); // 设置语言环境
	if (!file.is_open()) {
		cerr << "无法打开文件 " << mapFile.c_str() << endl;
		return;
	}

	wstring line;
	wchar_t ch;
	int index;
	for (int y = 0; y < HEIGHT && getline(file, line); y++) {
		index = y * WIDTH;
		for (int x = 0; x < WIDTH && x < line.length();x++) {
			if (line[x]>255) {//中文字符
				ch = line[x];
				back_buffer->m_buffer[index] = ch;
				back_buffer->m_buffer[index + 1] = 0;
				index += 2;//中文字符占两个字符位置
			}
			else {//英文字符
				ch = line[x];
				back_buffer->m_buffer[index] = ch;
				index++;
			}
		}
	}

	file.close();
}


