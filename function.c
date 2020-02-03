#include<windows.h>
void Goto(short x, short y);
void Goto(short x, short y)     //设置光标位置
{
	COORD pos = {x, y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);

}

void Win();
void Lose();
void Lose(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
    SetConsoleTextAttribute(handle,FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);// 设置为黄色
    printf("\n\n\t\t  YOU LOSE ! 你输了  \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
}
void Win(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
    SetConsoleTextAttribute(handle,FOREGROUND_RED );// 设置为黄色
    printf("\n\n\t\t  YOU WIN ! 你赢了  \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
}

int color(int c);
int color(int c)
{
	//SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
	return 0;
}
