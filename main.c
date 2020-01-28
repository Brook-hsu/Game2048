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
#include<time.h>

///定义全局变量4*4个，从num[1][1]开始
int num[5][5];
int Line=5;
int Col=4;
int Score;
///自定义函数 ,初步定义函数都为void，可能后续有些要变为int

/*打印界面*/
void Print();

/*初始化变量*/
void Initial();

/*键入方向键*/
int Control();
    void Turn_left();
    void Turn_right();
    void Turn_up();
    void Turn_down();

/*生成随机数*/
///用rand()种子
void New_random();

/*判断游戏是否结束*/
int Is_over();


///main函数作为主体，视图要一目了然，代码量不要太多，主要作用是引入自定义函数
int main()
{
	Initial();
	New_random();//此处照搬原游戏，使得一开始便可生成两个随机数

	int judge=1;

	while(judge==1){

		Print();
		judge=Is_over();
		if(judge==2||judge==0){
			break;
		}
        if(!Control())continue;
        New_random();
	}
	if(judge==2)
		printf("%s","WIN");
	else
		printf("%s","LOSE");
    return 0;
}

void Print(){
    system("cls");
    printf("\t\t你的分数是：%4d\n",Score);
    int i,j;
    ///Head
    printf("\t\t╔");
    for(j=1;j<=Col;j++){
        printf("════");
        if(Col-j)   printf("╦");
    }
    printf("╗\n");
    ///body
    for(i=1;i<=Line;i++){
        printf("\t\t");
        for(j=1;j<=Col;j++){
            if(!num[i][j]){printf("║    ");continue;}
            printf("║%4d",num[i][j]);
        }
        printf("║\n\t\t");
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
    Score=0;
	int i,j;
	for(i=0;i<=Line;++i){
		for(j=0;j<Col;++j){
			num[i][j]=0;
		}
	}
}
///初始化完成
/*其实，全局变量如果没有显式初始化的话，代码运行时会被自动初始化为 0 */


///function 'Control':
int Control()
{
	char operation;
	operation=getch();  /*键入操作 awsd;*/
	switch(operation){
		/*向左*/
		case 'a':
		case 'A':
        case 75:
			Turn_left();
			break;
		/*向右*/
		case 'd':
		case 'D':
        case 77:
		    Turn_right();
		    break;
		/*向上*/
		case 'w':
		case 'W':
        case 72:
			Turn_up();
			break;
		/*向下*/
		case 's':
		case 'S':
        case 80:
			Turn_down();
			break;
		default:
			return 0;
	}//end switch
	return 1;
}
///end function 'Control';
///移动操作
    void Turn_left(){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=1;j<=Col;j++){
                if(!num[i][j])for(temp=j+1;temp<=Col;temp++)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;break;}
                if(!num[i][j])continue;
                for(temp=j+1;temp<=Col;temp++){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[i][temp])continue;      ///空白处理
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        Score+=num[i][j];
                    break;}                         ///相同时合并
                    else if(temp!=j+1){
                        num[i][j+1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///不同时碰撞
		    break;
                }
            }
        }
    }
    void Turn_right(){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=Col;j>=1;j--){
                if(!num[i][j])for(temp=j-1;temp>=1;temp--)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;break;}
                if(!num[i][j])continue;
                for(temp=j-1;temp>=1;temp--){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[i][temp])continue;      ///空白处理
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        Score+=num[i][j];
                    break;}                         ///相同时合并
                    else if(temp!=j-1){
                        num[i][j-1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///不同时碰撞
		    break;
                }
            }
        }
    }
    void Turn_up(){
        int i,j,temp;
        for(j=1;j<=Col;j++){
            for(i=1;i<=Line;i++){
                if(!num[i][j])for(temp=i+1;temp<=Line;temp++)if(num[temp][j]){num[i][j]=num[temp][j];num[temp][j]=0;break;}
                if(!num[i][j])continue;
                for(temp=i+1;temp<=Line;temp++){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[temp][j])continue;      ///空白处理
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        Score+=num[i][j];
                    break;}                         ///相同时合并
                    else if(temp!=i+1){
                        num[i+1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///不同时碰撞
		    break;
                }
            }
        }
    }
    void Turn_down(){
        int i,j,temp;
        for(j=1;j<=Col;j++){
            for(i=Line;i>=1;i--){
                if(!num[i][j])for(temp=i-1;temp>=1;temp--)if(num[temp][j]){num[i][j]=num[temp][j];num[temp][j]=0;break;}
                if(!num[i][j])continue;
                for(temp=i-1;temp>=1;temp--){     ///设置temp循环作用：逐个temp与j比较
                    if(!num[temp][j])continue;      ///空白处理
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        Score+=num[i][j];
                    break;}                         ///相同时合并
                    else if(temp!=i-1){
                        num[i-1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///不同时碰撞
		    break;
                }
            }
        }
    }

///function 'New_random'
void New_random()
{
	srand(time(NULL));
    int index=rand()%16;
	while(num[index/4+1][index%4+1])    index=(index+3)%16;
	/* 生成随机位置
	此处有必要进行优化，减少随机位置生成的时间  */
	int a=rand()%2;
	if(a)
		num[index/4+1][index%4+1]=2;
	else
		num[index/4+1][index%4+1]=4;
	return;
}
///end function 'New_random'

/*
function 'Is_over"
返回 0 表示空格已满，游戏结束；
返回 1 表示未结束，游戏继续；
返回 2 表示出现最大值2048，游戏胜利，结束
*/
int Is_over()
{
	int i,j;//i 由于行计数；j 用于列计数///偷偷嫌弃一句，这函数的空行怎么这么长啊（看不到我看不到我）

	//行扫描判断
	for(j=Col;j>=1;--j){
		for(i=Line;i>=1;--i){

			if(num[i][j]==2048){
				return 2;//出现2048，胜利，游戏结束
			}

			else{

				if(num[i][j]==0){
					return 1;//没有2048但仍有空格，游戏继续；
				}

				else{
					if(num[i][j-1]==num[i][j]){
				    	return 1;//左边相等未结束的情况，游戏继续
				    }
				}

			}
		}
	}
	//行扫描判断结束

	//列扫描判断部分，该部分只需判断上面的数是否能合并
	for(i=Line;i>=1;--i){
		for(j=Col;j>=1;--j){
			if(num[i-1][j]==num[i][j]){
				return 1;
			}
		}
	}
	 //列扫描判断结束部分结束

	//能运行到这里表明没有空格，没有最大值，所以输了
	return 0;
}
