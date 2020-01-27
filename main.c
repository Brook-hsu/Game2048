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
int Is_over();


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


///初始化变量
void Initial()
{
	int i,j;
	for(i=1;i<Line+1;++i){
		for(j=1;j<Col+1;++j){
			num[i][j]=0;
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

///function 'New_random'
void New_random()
{
	srand(time(NULL));
	int col,row;
	do{
		col=rand()%4+1;
		row=rand()%4+1;
	}while(num[row][col]!=0);
	/* 生成随机位置 
	此处有必要进行优化，减少随机位置生成的时间  */ 
	
	int a;
	a=rand()%2;
	if(a==1){
		num[row][col]=2;
	}
	else{
		num[row][col]=4;
	}
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
	int i,j;//i 由于行计数；j 用于列计数
	
	//行扫描判断 
	for(j=col;j>=1;--j){
		for(i=line;i>=1;--i){
			
			if(num[i][j]=2048){
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
	for(i=line;i>=1;--i){
		for(j=col;j>=1;--j){
			if(num[i-1][j]==num[i][j]){
				return 1;
			}
		}
	} 
	 //列扫描判断结束部分结束 
	
	//能运行到这里表明没有空格，没有最大值，所以输了 
	return 0;
	
}


