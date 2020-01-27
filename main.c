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
#include<conio.h>
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
    Initial();
    for(;1;){
        Print();
        Control();
    }




    return 0;
}

void Print(){
    system("cls");
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
            if(!num[i][j]){printf("║    ");continue;}
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


///初始化变量
void Initial()
{
	int i,j;
	for(i=1;i<Line+1;++i){
		for(j=1;j<Col+1;++j){
			num[i][j]=2;
		}
	}
}
///初始化完成
/*其实，全局变量如果没有显式初始化的话，代码运行时会被自动初始化为 0 */


///function 'Control':
void Control()
{
	char operation;
	operation=getch();  /*键入操作 awsd;*/

	switch(operation){

		/*向左*/
		case 'a':
		case 'A':
			Turn_left();
			break;


		/*向右*/
		case 'd':
		case 'D':
		    Turn_right();
		    break;

		/*向上*/
		case 'w':
		case 'W':
			Turn_up();
			break;

		/*向下*/
		case 's':
		case 'S':
			Turn_down();
			break;

	}//end switch
}
///end function 'Control';
///移动操作
    void Turn_left(){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=1;j<=Col;j++){
                if(!num[i][j])for(temp=j+1;temp<=Col;temp++)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;}
                if(!num[i][j])continue;
                for(temp=j+1;temp<=Col;temp++){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[i][temp])continue;      ///空白处理
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        ///后续计分操作
                    break;}                         ///相同时合并
                    else if(temp!=j+1){
                        num[i][j+1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///不同时碰撞
                }
            }
        }
    }
    void Turn_right(){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=Col;j>=1;j--){
                if(!num[i][j])for(temp=j-1;temp>=1;temp--)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;}
                if(!num[i][j])continue;
                for(temp=j-1;temp>=1;temp--){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[i][temp])continue;      ///空白处理
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        ///后续计分操作
                    break;}                         ///相同时合并
                    else if(temp!=j-1){
                        num[i][j-1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///不同时碰撞
                }
            }
        }
    }
    void Turn_up(){
        int i,j,temp;
        for(j=1;j<=Col;j++){
            for(i=1;i<=Line;i++){
                if(!num[i][j])for(temp=i+1;temp<=Line;temp++)if(num[temp][j]){num[i][j]=num[temp][j];num[temp][j]=0;}
                if(!num[i][j])continue;
                for(temp=i+1;temp<=Line;temp++){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[temp][j])continue;      ///空白处理
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        ///后续计分操作
                    break;}                         ///相同时合并
                    else if(temp!=i+1){
                        num[i+1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///不同时碰撞
                }
            }
        }
    }
    void Turn_down(){
        int i,j,temp;
        for(j=1;j<=Col;j++){
            for(i=Line;i>=1;i--){
                if(!num[i][j])for(temp=i-1;temp>=1;temp--)if(num[temp][j]){num[i][j]=num[temp][j];num[temp][j]=0;}
                if(!num[i][j])continue;
                for(temp=i-1;temp>=1;temp--){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[i][temp])continue;      ///空白处理
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        ///后续计分操作
                    break;}                         ///相同时合并
                    else if(temp!=i-1){
                        num[i-1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///不同时碰撞
                }
            }
        }
    }

