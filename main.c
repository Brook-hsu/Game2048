/*摆脱无聊的尝试*/

///游戏2048
///1.打印界面（每次打印要有刷新）2.初始化变量3.键入方向键4.对应操作5.随机位置生成新数6.记分数7.判断游戏是否结束（是：结束；否：回到3）

///游戏扫雷
///

///合作方法：各自完成部分函数，统一变量命名，拿自己喜欢（会写的）的部分写
///代码有问题找百度，找刷子同学也行，他自己也不会，不过可以发给他确认（嘲笑）他不会

#include <stdio.h>
#include <stdlib.h>


int game;

void Welcome();
void Game2048();
void MineSweep();

///main函数作为主体，视图要一目了然，代码量不要太多，主要作用是引入自定义函数
int main()
{
    system("color 06");
    do{
    Welcome();
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
    }
    else break;
    }while(1);
    return 0;
}


void Welcome(){
    printf("\t———————————联合出品，不作商业用———————————\n"
    "\t~欢迎来到****（没想好）游戏~！\n"
    "\t***************************\n"
    "\t请选择游戏：\n"
    "\t1. 游戏2048\n"
    "\t2. 扫雷\n"
    "\t3. 常胜将军\n"
    "\t0. 退出游戏\n"
    "\t***************************\n");
    scanf("%d",&game);
}

