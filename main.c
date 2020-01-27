/*摆脱无聊的尝试*/

///游戏2048工作台
///程序步骤
///1.打印界面（每次打印要有刷新）
///2.初始化变量
///3.键入方向键
///4.对应操作
///5.随机位置生成新数
///6.记分数
///7.判断游戏是否结束（是：结束；否：回到3）

///合作方法：各自完成部分函数，统一变量命名，拿自己喜欢（会写的）的部分写

///代码有问题找百度，找刷子同学也行，他自己也不会，不过可以发给他确认（嘲笑）他不会
#include <stdio.h>
#include <stdlib.h>
///定义全局变量4*4个，从num[1][1]开始
int num[5][5],Line=4,Col=4;
///自定义函数    初步定义函数都为void，可能后续有些要变为int
/*打印界面*/
void Print();
/*初始化变量*/
void Initial();
/*键入方向键*////可能要百度解决
void Control();
    void Turn_left();
    void Turn_right();
    void Turn_up();
    void Turn_down();
/*生成随机数*////用rand()种子
void New_random();
/*判断游戏是否结束*/
void Is_over();


///main函数作为主体，视图要一目了然，代码量不要太多，主要作用是引入自定义函数
int main()
{
    Print();
    return 0;
}

void Print(){
    int i,j;
    ///Head
    printf("╔");
    for(j=1;j<=Col;j++){
        printf("════");
        if(Col-j)   printf("╦");
    }
    printf("╗\n");
    ///body
    for(i=1;i<=Line;i++){
        for(j=1;j<=Col;j++){
            printf("║%4d",num[i][j]);
        }
        printf("║\n");
        if(i-Line){
        for(j=1;j<=Col;j++){
            printf("║════");
        }
        printf("║\n");}
    }
    ///foot
    printf("╚");
    for(j=1;j<=Col;j++){
        printf("════");
        if(Col-j)   printf("╩");
    }
    printf("╝");


}
