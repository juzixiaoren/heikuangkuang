#include"header.h"
#include"screen.h"
using namespace std;
void ViewportToScreen(Viewport* back_buffer, Viewport* front_buffer)//�ӿڵ���Ļ
{
	for (int y = 0; y < HEIGHT; y++)//�����߶�
	{
		for (int x = 0; x < WIDTH; x++)//�������
		{
			int index = x + y * WIDTH;//����
			wchar_t ch = back_buffer->m_buffer[index];//�ַ�
			if (ch != front_buffer->m_buffer[index])
			{
				wcout.imbue(locale("zh_CN"));
				gotoxy(x, y);
				wcout << ch;
				front_buffer->m_buffer[index] = ch; // ʹ������back_buffer���ַ�����front_buffer
			}
		}
	}
}
void PrintFrame(Viewport* back_buffer, int frame)
{
	//��ӡ֡��
	wchar_t str[255];//�ַ���
	for (int i = 0, max_i = wcslen(str); i < max_i; i++)//�����ַ���
	{
		back_buffer->m_buffer[i] = str[i];//��ֵ
	}
}
void Delay()//�ӳ�
{
	Sleep(3000);
};
void gotoxy(int x, int y) {
	COORD cd = { 2*x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);//���ù��λ��
}

void CleanScreen(Viewport* back_buffer)//����
{
	//system("cls");
	memset(back_buffer,0, sizeof(*back_buffer));//��ջ�����
}

void RenderProt(Viewport* back_buffer, Protagonist* prot)//��Ⱦ����
{
	int index = prot->m_x + prot->m_y * WIDTH;
	if (back_buffer->m_buffer[index] == ' ' || back_buffer->m_buffer[index] == 0)
	{
		back_buffer->m_buffer[index] = prot->m_char;
	}
}
void screen_input(Viewport* back_buffer)
{
	wifstream file(L"test.txt");//���ļ�
	file.imbue(locale("zh_CN"));//��txt������Ի�������Ϊzh_CN
	if (!file.is_open()) {
		cerr << "�޷����ļ� test.txt" << endl;
		return;
	}
	wstring line;
	wchar_t ch;
	for(int y = 0; y < HEIGHT&&getline(file,line); y++)
	{
		for(int x = 0; x < WIDTH && x<line.length(); x++)
		{
			int index= x + y * WIDTH;
			ch = line[x];
			back_buffer->m_buffer[index] = ch;
		}
	}
	file.close();
}
void screen_output() 
{
	Viewport buffers[2] = { 0 };//�ӿ�
	int front_index, back_index;//ǰ������
	int frame = 0;//֡��
	front_index = 0;//��ʼ������
	back_index = 1;//��ʼ������
	Protagonist prot;//����
	prot.m_x = 6;
	prot.m_y = 4;
	prot.m_char = L'��';
	for (;;)
	{
		CleanScreen(&buffers[back_index]);

		screen_input(&buffers[back_index]);

		RenderProt(&buffers[back_index], &prot);

		//PrintFrame(&buffers[back_index], frame);//��ӡ֡��

		ViewportToScreen(&buffers[back_index], &buffers[front_index]);//�ӿڵ���Ļ
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

