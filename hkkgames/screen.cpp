#include"header.h"
#include"screen.h"
#include"controller.h"
#include "Startgame.h"
#include "fight.h"
using namespace std;
int mapid;
extern int coord_xy[10][2];
extern controller player;
extern int Status;
extern int info;
extern Viewport buffers[2];
std::atomic<bool> stopThread(false); // 使用原子变量以确保线程安全
extern int front_index;
extern int back_index;
extern player_s Playerinfo;

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
			}
		}
	}
}
int Coordinate_judgment(int x[][2],controller*player)
{
	for (int i = 0; i < 10; i++)
	{
		if (player->x == x[i][0] && player->y == x[i][1])
		{
			return i+1;
		}
	}
	return 0;
}
bool Canmove(controller*player,Viewport* front_buffer, Protagonist* prot) 
{
	if (player->IfMove== 1)
	{
		int index = player->x*2 + (player->y-1) * WIDTH;
		if (front_buffer->m_buffer[index] != player->m_char && (front_buffer->m_buffer[index] == 0||front_buffer->m_buffer[index]==L' ')&& front_buffer->m_buffer[index+1] != player->m_char && (front_buffer->m_buffer[index+1] == 0 || front_buffer->m_buffer[index+1] == L' '))
		{
			return true;
		}
		else 
			return false;
	}
	if (player->IfMove == 2)
	{
		int index = player->x*2 + (player->y + 1) * WIDTH;
		if (front_buffer->m_buffer[index] != player->m_char && (front_buffer->m_buffer[index] == 0 || front_buffer->m_buffer[index] == L' ')&& front_buffer->m_buffer[index + 1] != player->m_char && (front_buffer->m_buffer[index + 1] == 0 || front_buffer->m_buffer[index + 1] == L' '))
			return true;
		else return false;
	}
	if (player->IfMove == 3)
	{
		int index = (player->x*2) + player->y * WIDTH;
		if(front_buffer->m_buffer[index-1] != player->m_char && (front_buffer->m_buffer[index-1] == 0 || front_buffer->m_buffer[index-1] == L' ')&& front_buffer->m_buffer[index - 2] != player->m_char && (front_buffer->m_buffer[index - 2] == 0 || front_buffer->m_buffer[index - 2] == L' '))
			return true;
		else return false;
	}
	if (player->IfMove == 4)
	{
		int index = (player->x*2) + player->y * WIDTH;
		if(front_buffer->m_buffer[index+1] != player->m_char && (front_buffer->m_buffer[index+1] == 0 || front_buffer->m_buffer[index+1] == L' ')&& front_buffer->m_buffer[index + 2] != player->m_char && (front_buffer->m_buffer[index + 2] == 0 || front_buffer->m_buffer[index + 2] == L' '))
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

//这段函数的作用是将光标移动到指定位置，放在循环中会使得光标在屏幕上移动
void gotoxy(int x, int y) 
{
	COORD cd = { x,y };//COORD是Windows.h中定义的一种结构体，表示控制台屏
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//设置光标位置
}

void CleanScreen(Viewport* back_buffer)//清屏
{
	for (int i = 0; i < WIDTH * HEIGHT; i++)
		back_buffer->m_buffer[i] = L' ';//L是宽字符的意思
}

void RenderProt(Viewport* back_buffer, Protagonist* prot)//渲染主角
{
	int index = prot->m_x + prot->m_y * WIDTH;
	if (back_buffer->m_buffer[index] == L' ' || back_buffer->m_buffer[index] == 0)
	{
		back_buffer->m_buffer[index] = player.m_char;
		back_buffer->m_buffer[index + 1] = 0;
	}
}
void clear_preRenderProt(Viewport* back_buffer, controller* player)//清除上一次的主角
{
	int index = player->prex*2+player->prey * WIDTH;
		back_buffer->m_buffer[index] = L' ';
		back_buffer->m_buffer[index+1] = L' ';
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
	for (int y = 0; y < HEIGHT && getline(file, line); y++)//getline是读取一行
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
void Coordinate()//判断循环
{
	while (1)
	{
		if (Coordinate_judgment(coord_xy, &player))
		{
			switch (Status)
			{
			case 1: {
				mapid = 0;
				Status = 0;
				info = 1;
				player.x = 0;
				player.y = 0;
				player.m_char = NULL;
				break;
			}
			case 2: 
			{
				mapid = 0;
				Status = 0;
				if (Coordinate_judgment(coord_xy, &player) == 1)
				{
					Playerinfo.changeinfo(L"史尔特", 120, 25, 12, 20, 12, 10, 10);
				}
				else if (Coordinate_judgment(coord_xy, &player) == 2)
				{
					Playerinfo.changeinfo(L"李狗剩", 90, 10, 10, 10, 40, 35, 24);
				}
				else if (Coordinate_judgment(coord_xy, &player) == 3)
				{
					Playerinfo.changeinfo(L"马恩纳", 150, 10, 15, 15, 20, 9, 10);
				}
				break;
			}
			default:
				break;
			}
		}
	}	
}
void screen_output()
{
	front_index = 0;//初始化索引
	back_index = 1;//初始化索引
	Protagonist prot{};//主角
	prot.m_x = 2*player.x;
	prot.m_y = player.y;
	
	for (;;)
	{
		CleanScreen(&buffers[back_index]);//清屏
		loadMapFile(&buffers[back_index], selectMapFile(mapid));//加载地图文件
		loadothers();//加载其他
		//loadothers();//加载其他
		//loadothers();//加载其他

		if (player.m_char != NULL) 
		{
			RenderProt(&buffers[back_index], &prot);//渲染主角
			while (player.CheckIfMove() && Canmove(&player, &buffers[front_index], &prot))//检查是否移动
			{
				if (Timer(90, 1)) 
				{
					player.Move();//移动
					/*	cout << player.x << player.y << endl;*/
					prot.m_x = 2 * player.x;
					prot.m_y = player.y;
					RenderProt(&buffers[back_index], &prot);//渲染主角
					clear_preRenderProt(&buffers[back_index], &player);//清除上一次的主角位置
				}
				else break;
			}
		}
		ViewportToScreen(&buffers[back_index], &buffers[front_index]);//视口到屏幕
		/*Delay();*/

		//swap index
		{
			int temp = back_index;
			back_index = front_index;
			front_index = temp;
		}
	}
}
// 假设地图文件名存储在一个数组中
const std::vector<std::wstring> mapFiles = { L"NULL.txt", L"title.txt", L"map1.txt",L"test2.txt",L"BIGEYES.txt",L"HELL.txt",L"SLIME.txt",L"BOOS.txt"};

// 根据游戏状态选择地图文件
wstring selectMapFile(int gameLevel) 
{
	if (gameLevel < mapFiles.size()) 
	{
		return mapFiles[gameLevel];
	}
	// 如果游戏等级超出了文件列表，返回默认地图文件
	return mapFiles[0];
}
// 读取地图文件内容的函数
void loadMapFile(Viewport* back_buffer, const std::wstring& mapFile)
{//加载地图文件
	wifstream file(mapFile.c_str()); // 打开文件。c_str()函数将wstring转换为C风格的字符串
	file.imbue(locale("zh_CN")); // 设置语言环境
	if (!file.is_open())
	{
		cerr << "无法打开文件 " << mapFile.c_str() << endl;
		return;
	}

	wstring line;
	wchar_t ch;
	int index;
	for (int y = 0; y < HEIGHT && getline(file, line); y++) 
	{
		index = y * WIDTH;
		for (int x = 0; x < WIDTH; x++) 
		{
			if (x > line.length()) 
			{
				ch = L' ';
				back_buffer->m_buffer[index] = ch;
				index++;
			}
			else if (line[x] > 255) 
			{//中文字符
				ch = line[x];
				back_buffer->m_buffer[index] = ch;
				back_buffer->m_buffer[index + 1] = 0;
				index += 2;//中文字符占两个字符位置
			}
			else 
			{//英文字符
				ch = line[x];
				back_buffer->m_buffer[index] = ch;
				index++;
			}
		}
	}
	file.close();
}
BOOL MByteToWChar_t(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)//多字节转宽字节
{
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, NULL, 0);

	if (dwSize < dwMinSize)
	{
		return FALSE;
	}
	return TRUE;
}
BOOL WCharToMByte_t(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)//宽字节转多字节
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, NULL, 0, NULL, FALSE);
	if (dwSize < dwMinSize)
	{
		return FALSE;
	}
	WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, lpszStr, dwSize, NULL, FALSE);
	return TRUE;
}

#include <codecvt>
//convert string to wstring
wstring to_wide_string(const std::string& input)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(input);
}

//convert wstring to string 
string to_byte_string(const std::wstring& input)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.to_bytes(input);
}
wstring clean_wstring(const std::wstring& w_string) {
	wstring temp;
	for (int i = 0, k = i; i < w_string.size(); i++)
	{
		if (w_string[i] != L' ' && w_string[i] != 0)
		{
			temp[k] = w_string[i];
			k++;
		}
	}
	return temp;
}