#include<windows.h>
void Goto(short x, short y);

void Goto(short x, short y)     //���ù��λ��
{
	COORD pos = {x, y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);

}

void Win();
void Lose();

void Lose(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
    SetConsoleTextAttribute(handle,FOREGROUND_RED |BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);// ����Ϊ��ɫ
    printf("\n\n\t\t  YOU LOSE ! ������  \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
}
void Win(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
    SetConsoleTextAttribute(handle,FOREGROUND_RED );// ����Ϊ��ɫ
    printf("\n\n\t\t  YOU WIN ! ��Ӯ��  \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
}
