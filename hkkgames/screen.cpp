#include"header.h"
#include"screen.h"
using namespace std;
void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer)//视口到屏幕
{
	for (int y = 0; y < HEIGHT; y++)//遍历高度
	{
		for (int x = 0; x < WIDTH; x++)//遍历宽度
		{
			int index = x + y * WIDTH;//索引
			wchar_t ch = back_buffer->m_buffer[index];//字符
			if (ch != front_buffer->m_buffer[index]) //如果字符不为空
			{
				gotoxy(x, y);//移动光标
				wcout << ch;//输出字符
				front_buffer->m_buffer[index] = ch;//赋值
			}
		}
	}
}
void PrintFrame(Viewport* back_buffer, int frame)
{
	//打印帧数
	wchar_t str[255];//字符串
	for (int i = 0, max_i = wcslen(str); i < max_i; i++)//遍历字符串
	{
		back_buffer->m_buffer[i] = str[i];//赋值
	}
}
void Delay()//延迟
{
	Sleep(3000);
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
	}
}
void screen_input(Viewport* back_buffer)
{
	wifstream file(L"test.txt");//打开文件
	file.imbue(locale("zh_CN"));//把txt里的语言环境设置为zh_CN
	if (!file.is_open()) {
		cerr << "无法打开文件 test.txt" << endl;
		return;
	}
	wstring line;
	int y = 0;
	int index = 0;
	while (y < HEIGHT)
	{
		getline(file, line);
		for(int x = 0; x < WIDTH; x++)
		{
			if(x < line.length())
			back_buffer->m_buffer[x + y * WIDTH] = line[x];
		}
		y++;
	}
	file.close();
}
void screen_output() 
{
	Viewport buffers[2] = { 0 };//视口
	int front_index, back_index;//前后索引
	int frame = 0;//帧数
	front_index = 0;//初始化索引
	back_index = 1;//初始化索引
	Protagonist prot;//主角
	prot.m_x = 6;
	prot.m_y = 4;
	prot.m_char = L'我';
	for (;;)
	{
		CleanScreen(&buffers[back_index]);

		screen_input(&buffers[back_index]);

		RenderProt(&buffers[back_index], &prot);

		//PrintFrame(&buffers[back_index], frame);//打印帧数

		ViewportToScreen(&buffers[back_index], &buffers[front_index]);//视口到屏幕
		Delay();


		//swap index
		{
			int temp = back_index;
			back_index = front_index;
			front_index = temp;
		}
		frame++;
	}
}

