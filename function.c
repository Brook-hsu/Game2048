#include<windows.h>
void Goto(short x, short y);

void Goto(short x, short y)     //���ù��λ��
{
	COORD pos = {x, y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);

}
