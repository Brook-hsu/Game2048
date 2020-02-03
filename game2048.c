
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<Windows.h>

/*打印界面*/
void Print(int **num,int Line,int Col,int Target);

/*初始化变量*/
void Initial(int **num,int Line,int Col);

/*键入方向键*/
int Control(int **num,int Line,int Col,int Target);
    void Turn_left(int **num,int Line,int Col,int Target);
    void Turn_right(int **num,int Line,int Col,int Target);
    void Turn_up(int **num,int Line,int Col,int Target);
    void Turn_down(int **num,int Line,int Col,int Target);

/*生成随机数*/
///用rand()种子
void New_random(int **num,int Line,int Col,int Target);

/*判断游戏是否结束*/
int Is_over(int **num,int Line,int Col,int Target);

void difficulty_level();
void default_difficulty();

int Score;
int Choose_of_de_level;
int game2048;


void Game2048()
{
    system("title 游戏2048");
    system("color 07");

    int Line,Col,Target;
    difficulty_level();
    if(game2048==1){
        default_difficulty();
        Line=4*Choose_of_de_level;
        Col=4*Choose_of_de_level;
        Target=2048*Choose_of_de_level*Choose_of_de_level;

    }
    if(game2048==2){
        system("cls");
        printf("\n\n\n\n\n\t\t\t%s\n\n\n","input the number of Line , Column and Target you want");
        printf("\t\t\t建议玩家将行列数设为4的倍数\n");
        printf("\t\t\t将目标值设为行数(Line)除以4的整数部分\n\t\t\t乘以 列数(Col)除以4的整数部分 再乘以512\n\n");
        printf("\t\t\t");
        printf("%s\n\n","Of course,you happy is OKKKK!");
        printf("\t\t\t%s\t","Line:");
        scanf("%d",&Line);
        printf("\n\t\t\t%s\t","Columm:");
        scanf("%d",&Col);
        printf("\n\t\t\t%s\t","Target:");
        scanf("%d",&Target);

    }
    if(game2048==3){
        return;
    }

    //此处增加二维数组申请内存
    int **num;
    int i;
    num=(int **)malloc(sizeof(*num)*(Line+1));
    for(i=0;i<Line+1;++i)    num[i]=(int *)malloc(sizeof(**num)*(Col+1));
    Initial(num,Line,Col);
    New_random(num,Line,Col,Target);
    New_random(num,Line,Col,Target);//此处照搬原游戏，使得一开始便可生成两个随机数
    int judge=1;
    system("cls");
    while(judge==1){
        Print(num,Line,Col,Target);
        judge=Is_over(num,Line,Col,Target);
        if(judge==2||judge==0)			break;
        if(!Control(num,Line,Col,Target))  continue;
        New_random(num,Line,Col,Target);
    }
    for(i=0;i<Line+1;++i)        free(num[i]);
    free(num);
    if(judge==2)    Win();
    else    		Lose();
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


///function 'New_random'
void New_random(int **num,int Line,int Col,int Target)
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

///function 'Control':
int Control(int **num,int Line,int Col,int Target)
{
	char operation;
	operation=getch();  /*键入操作 awsd;*/
	switch(operation){
		/*向左*/
        case 75:
		case 'a':
		case 'A':
			Turn_left(num,Line,Col,Target);
			break;
		/*向右*/
		case 77:
		case 'd':
		case 'D':
		    Turn_right(num,Line,Col,Target);
		    break;
		/*向上*/
        case 72:
		case 'w':
		case 'W':
			Turn_up(num,Line,Col,Target);
			break;
		/*向下*/
        case 80:
		case 's':
		case 'S':
			Turn_down(num,Line,Col,Target);
			break;
		default:
			return 0;
	}//end switch
	return 1;
}
///end function 'Control';
///移动操作
    void Turn_left(int **num,int Line,int Col,int Target){
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
    void Turn_right(int **num,int Line,int Col,int Target){
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
    void Turn_up(int **num,int Line,int Col,int Target){
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
    void Turn_down(int **num,int Line,int Col,int Target){
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


void Print(int **num,int Line,int Col,int Target){
    Goto(1,1);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
    printf("\t———————————联合出品，不作商业用———————————\n\n\n");
    printf("\t\t你的分数是：%4d\n",Score);
    printf("\n\t\t你需要合并到%d\n",Target);
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
            if(!num[i][j])printf("║    ");
            else {
                printf("║");
                if(num[i][j]==2)
                    color(8);
                if(num[i][j]==8)
                    color(14);
                if(num[i][j]==16)
                    color(5);
                if(num[i][j]==32)
                    color(3);
                if(num[i][j]==64)
                    color(10);
                if(num[i][j]==128)
                    color(9);
                if(num[i][j]==256)
                    color(12);
                if(num[i][j]==512)
                    color(13);
                if(num[i][j]==1024)
                    color(4);
                printf("%4d",num[i][j]);
            }
            color(7);
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


/*
function 'Is_over"
返回 0 表示空格已满，游戏结束；
返回 1 表示未结束，游戏继续；
返回 2 表示出现最大值2048，游戏胜利，结束
*/
int Is_over(int **num,int Line,int Col,int Target)
{
	int i,j;//i 由于行计数；j 用于列计数///偷偷嫌弃一句，这函数的空行怎么这么长啊（看不到我看不到我）

	//行扫描判断
	for(j=Col;j>=1;--j){
		for(i=Line;i>=1;--i){

			if(num[i][j]==Target){
				return 2;//出现Target，胜利，游戏结束
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

void difficulty_level()
{
    int Choice_of_game2048=2;

        game2048=1;
        while(1){

            system("cls");
            printf("\n\n\n\n\n\t\t\t\t\t%s\n\n\t\t\t\t\t%s\n\n\n\n\n","Welcome to 2048game!","Now please choose the difficulty level you want.");
             printf("\t\t\t\t\t");
             if(game2048==1){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
                 printf("%s 默认难度\n\n","Default difficulty");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("%s 默认难度\n\n","Default difficulty");
            }

            printf("\t\t\t\t\t");
            if(game2048==2){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
                 printf("%s 自定义难度\n\n","Custom difficulty");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("%s 自定义难度\n\n","Custom difficulty");
            }


            printf("\t\t\t\t\t");
            if(game2048==Choice_of_game2048+1){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
                 printf("退出2048游戏\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("退出2048游戏\n\n");
            }

            char choose=getch();
            switch(choose){
            /*向上*/
            case 72:
            case 'w':
            case 'W':
                if(game2048>1)game2048--;
                break;
            /*向下*/
            case 80:
            case 's':
            case 'S':
                if(game2048<=Choice_of_game2048)game2048++;
                break;
            case 13:
                return;
            default:
                continue;
        }//end switch

        }//end while
        return;
}

void default_difficulty()
{
    Choose_of_de_level=1;
    while(1){
        system("cls");
            printf("\n\n\n\n\n\t\t\t\t\t%s\n\n\n","Choose the difficulty level you wanted");

            printf("\t\t\t\t\t");
            if(Choose_of_de_level==1){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
                 printf("4行4列\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("4行4列\n\n");
            }

            printf("\t\t\t\t\t");
            if(Choose_of_de_level==2){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取控制台句柄
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// 设置为黄色
                 printf("8行8列\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("8行8列\n\n");
            }

            char choose=getch();
            switch(choose){
            /*向上*/
            case 72:
            case 'w':
            case 'W':
                if(Choose_of_de_level>1)Choose_of_de_level--;
                break;
            /*向下*/
            case 80:
            case 's':
            case 'S':
                if(Choose_of_de_level<=2)Choose_of_de_level++;
                break;
            case 13:
                return;
            default:
                continue;
        }//end switch

        }//end while
        return;
    }
