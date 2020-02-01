#include<windows.h>
void Goto(short x, short y);

void Goto(short x, short y)     //设置光标位置
{
	COORD pos = {x, y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);

}
