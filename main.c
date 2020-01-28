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
#include <conio.h>
#include <time.h>

///定义全局变量4*4个，从num[1][1]开始

int Score,game;
///自定义函数 ,初步定义函数都为void，可能后续有些要变为int

void Welcome();
/*打印界面*/
void Print(int **num,int Line,int Col);

/*初始化变量*/
void Initial(int **num,int Line,int Col);

/*键入方向键*/
int Control(int **num,int Line,int Col);
    void Turn_left(int **num,int Line,int Col);
    void Turn_right(int **num,int Line,int Col);
    void Turn_up(int **num,int Line,int Col);
    void Turn_down(int **num,int Line,int Col);

/*生成随机数*/
///用rand()种子
void New_random(int **num,int Line,int Col);

/*判断游戏是否结束*/
int Is_over(int **num,int Line,int Col);
    void Lose();
    void Win();

///main函数作为主体，视图要一目了然，代码量不要太多，主要作用是引入自定义函数
int main()
{
    system("color 06");
    do{
    Welcome();
    if(game)
    switch(game){
        case 1:{
            system("color 03");
        	system("cls");
        	int Line;
            int Col;
            printf("\n\n\n\n\n\n\t\t\t\t\t%s\n","input the number of Line and Column you want");
            printf("\t\t\t\t\t%s\t","Line:");
            scanf("%d",&Line);
            printf("\t\t\t\t\t%s\t","Columm:");
            scanf("%d",&Col);
            //此处增加二维数组申请内存 
        	int **num;
        	int i;
        	num=(int **)malloc(sizeof(*num)*(Line+1));
         	for(i=0;i<Line+1;++i){
     		num[i]=(int *)malloc(sizeof(**num)*(Col+1));
	}
	
	// 
            Initial(num,Line,Col);
            New_random(num,Line,Col);
			New_random(num,Line,Col);//此处照搬原游戏，使得一开始便可生成两个随机数
            int judge=1;
            while(judge==1){
                Print(num,Line,Col);
                judge=Is_over(num,Line,Col);
                if(judge==2||judge==0)			break;
                if(!Control(num,Line,Col))  continue;
                New_random(num,Line,Col);
            }
         	for(i=0;i<Line+1;++i){
         		free(num[i]);
        	}
         	free(num);
            if(judge==2)    Win();
            else    		Lose();
        }
    }
    else break;
    }while(1);
    return 0;
}

void Print(int **num,int Line,int Col){
    system("cls");
    printf("\t———————————联合出品，不作商业用———————————\n\n\n");
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
    printf("╝\n\n\n");
    printf("\t\tw:↑  s:↓  a:←  d:→");
}


///初始化变量
void Initial(int **num,int Line,int Col)
{
    Score=0;
	int i,j;
	for(i=0;i<=Line;++i){
		for(j=0;j<=Col;++j){
			num[i][j]=0;
		}
	}
}
///初始化完成
/*其实，全局变量如果没有显式初始化的话，代码运行时会被自动初始化为 0 */


///function 'Control':
int Control(int **num,int Line,int Col)
{
	char operation;
	operation=getch();  /*键入操作 awsd;*/
	switch(operation){
		/*向左*/
        case 75:
		case 'a':
		case 'A':
			Turn_left(num,Line,Col);
			break;
		/*向右*/
		case 77:
		case 'd':
		case 'D':
		    Turn_right(num,Line,Col);
		    break;
		/*向上*/
        case 72:
		case 'w':
		case 'W':
			Turn_up(num,Line,Col);
			break;
		/*向下*/
        case 80:
		case 's':
		case 'S':
			Turn_down(num,Line,Col);
			break;
		default:
			return 0;
	}//end switch
	return 1;
}
///end function 'Control';
///移动操作
    void Turn_left(int **num,int Line,int Col){
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
    void Turn_right(int **num,int Line,int Col){
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
    void Turn_up(int **num,int Line,int Col){
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
    void Turn_down(int **num,int Line,int Col){
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
void New_random(int **num,int Line,int Col)
{
    int i,j,check=0;
    for(i=1;i<=Line;i++){
        for(j=1;j<=Col;j++)
            if(!num[i][j]){check=1;break;}
        if(check)break;
    }
    if(!check)  return;
	srand(time(NULL));
	int colu,row;
	do{
	    colu=rand()%Col+1;
	    row=rand()%Line+1;
	}while(num[row][colu]);
	/* 生成随机位置
	此处有必要进行优化，减少随机位置生成的时间  */
	int a=rand()%2;
	if(a)
		num[row][colu]=2;
	else
		num[row][colu]=4;

	return;
}
///end function 'New_random'

/*
function 'Is_over"
返回 0 表示空格已满，游戏结束；
返回 1 表示未结束，游戏继续；
返回 2 表示出现最大值2048，游戏胜利，结束
*/
int Is_over(int **num,int Line,int Col)
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

void Welcome(){
    printf("\t———————————联合出品，不作商业用———————————\n"
    "\t~欢迎来到****（没想好）游戏~！\n"
    "\t***************************\n"
    "\t请选择游戏：\n"
    "\t1.游戏2048\n"
    "\t2.\n"
    "\t0.退出游戏\n"
    "\t***************************\n");
    scanf("%d",&game);
}
void Lose(){
    printf("\n\n\t\t YOU LOSE !\n\n");
}
void Win(){
    printf("\n\n\t\t YOU WIN !\n\n");
}
