/*摆脱无聊的尝试*/

///游戏2048
///1.打印界面（每次打印要有刷新）2.初始化变量3.键入方向键4.对应操作5.随机位置生成新数6.记分数7.判断游戏是否结束（是：结束；否：回到3）

///游戏扫雷
///

///常胜将军

///数独

///合作方法：各自完成部分函数，统一变量命名，拿自己喜欢（会写的）的部分写
///代码有问题找百度，找刷子同学也行，他自己也不会，不过可以发给他确认（嘲笑）他不会

#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

#define Count_of_game 4

int game;


void Welcome();
void A_Control();
int Is_continue();
void Is_continue_print(int n);

void Game2048();
void MineSweep();
void Sudoku_demo();


///main函数作为主体，视图要一目了然，代码量不要太多，主要作用是引入自定义函数
int main()
{
    do{
    A_Control();
    if(game)
    switch(game){
        case 1:
            Game2048();
        break;
        case 2:
            MineSweep();
        break;
        case 3:
            General();
        break;

	    case 4:
		    Sudoku_demo();
		    break;
    }
    else break;
    }while(Is_continue());
    return 0;
}


void Welcome(){
    printf("\n\n\n\t\t\t\t———————————联合出品，不作商业用———————————\n"
    "\t\t\t\t欢迎来到时间空洞！\n"
    "\n\t\t\t\t游戏仍开发中，暂有某些缺漏属正常（1.2.3.已上线）\n"
    "\t\t\t\t若发现bug，影响游戏体验,那也忍着:)\n\n"
    "\t\t\t\t祝您游戏愉快！"
    "\n\n\n"
    "\t\t\t\t请选择游戏 :\n");
    printf("\t\t\t\t");
    if(game==0){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
        printf("0. 结束游戏\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("0. 结束游戏\n\t\t\t\t");
    }

    if(game==1){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
        printf("1. 游戏2048\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("1. 游戏2048\n\t\t\t\t");
    }

    if(game==2){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
        printf("2. 扫雷\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("2. 扫雷\n\t\t\t\t");
    }

    if(game==3){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
        printf("3. 常胜将军\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("3. 常胜将军\n\t\t\t\t");
    }

    if(game==4){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
        printf("4. 数独\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("4. 数独\n\t\t\t\t");
    }


}


void A_Control(){
    game=0;
    while(1){
        system("cls");
        Welcome();
        char operation=getch();  /*键入操作 awsd;*/
        switch(operation){
            /*向上*/
            case 72:
            case 'w':
            case 'W':
                if(game>0)game--;
                break;
            /*向下*/
            case 80:
            case 's':
            case 'S':
                if(game<Count_of_game)game++;
                break;
            case 13:
                return ;
            default:
                continue;
        }//end switch
    }
	return;
}

int Is_continue(){
    int index=1;
    printf("\t————游戏已结束，是否回到主页面————\n\n");
    Is_continue_print(index);
    while(1){
        char operation=getch();  /*键入操作 awsd;*/
        switch(operation){
            /*向右*/
            case 77:
            case 'd':
            case 'D':
                if(index){index--;
                printf("\r");
                Is_continue_print(index);}
                break;
            /*向左*/
            case 75:
            case 'a':
            case 'A':
                if(!index){index++;
                printf("\r");
                Is_continue_print(index);}
                break;
            case 13:
                return index;
            default:
                continue;
        }//end switch
    }
}

void Is_continue_print(int n){
    if(n){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle,BACKGROUND_GREEN );// 设置为黄色
        printf("\t          是          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else    printf("\t          是          ");
    if(!n){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
        SetConsoleTextAttribute(handle,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED| FOREGROUND_RED );// 设置为黄色
        printf("          否          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else    printf("          否          ");
}
