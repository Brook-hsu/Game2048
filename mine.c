#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///扫雷游戏模块，这MineSweep()相当于源文件的main()函数，控制整个游戏节奏
///为防止与2048冲突，这里所有命名统一加前缀  m_  （可能会有点烦）
///游戏思路：
///1.在10×10方阵随机生成十个雷
///2.有一个小人￥，在没有雷的地方瞎逛
///3.雷周边有数字标明
///4.胜利条件：小人把雷正确标完或走过所有无雷地区
///其他待构想

///函数构建：分两大块头
///一、初始化值，创建十个互异随机数，并计算出每个方快对应数字，并令所有方快处于cover状态0
///二、控制小人移动Control，这里比较简单，但注意别移动出界
///三、小人每移动一次计算一次compute，小人周边八个格变成uncover状态
///注意： 方快只有cover到uncover单向改变,cover时显示黑块,uncover时显示数字或空白

short cov[12][12];///未知标1，已知标0
short loc[12][12];
short m_Col=10,m_Line=10;
short man_i,man_j;
short uncover;

void m_Print();
void m_Initial();///产生随机数在initial里面了
void m_Man_around();
void m_Control();
    void m_Turn_left();
    void m_Turn_right();
    void m_Turn_up();
    void m_Turn_down();
int m_Is_over();
void m_Lose();
void m_Win();


void MineSweep(){
    system("title 扫雷");
    m_Initial();
    do{
        m_Control();
        m_Man_around();
        m_Print();
    }while(m_Is_over());
}


void m_Print(){

    system("cls");
    printf("\t———————————联合出品，不作商业用———————————\n\n");
    int i,j;
    ///Head
    printf("\t\t╔");
    for(j=1;j<=m_Col;j++)        printf("══");
    printf("╗");
    printf("\t雷：10个\n");
    ///body
    for(i=1;i<=m_Line;i++){
        printf("\t\t║");
        for(j=1;j<=m_Col;j++){
            if(!cov[i][j])  printf("□");
            else{
                if(i==man_i&&j==man_j)  printf("♀");
                else if(loc[i][j]&&loc[i][j]<9)  printf(" %d",loc[i][j]);
                else if(loc[i][j])  printf(" *");
                else    printf("  ");
            }
        }
        printf("║\n");
    }
    ///foot
    printf("\t\t╚");
    for(j=1;j<=m_Col;j++)        printf("══");
    printf("╝\n");
    printf("\t\t还需%d块\n",90-uncover);
    printf("\t\tw:↑  s:↓  a:←  d:→\n\n");
}

void m_Initial(){
    system("color 07");
    uncover=0;
    int i,j;
    for(i=1;i<=m_Line;i++){
        for(j=1;j<=m_Col;j++){
            cov[i][j]=0;loc[i][j]=0;
        }
    }
    ///定义十个雷，雷是loc>=9
    int count=0,temp_i,temp_j;
    srand(time(NULL));
    for(i=0;i<10;i++){
        count=count+rand()%((count<85)?19:5)+1;
        count=count%100;
        temp_i=count/10+1,temp_j=count%10+1;
        loc[temp_i][temp_j]=9;
        for(j=temp_i-1;j<=temp_i+1;j++)
            loc[j][temp_j-1]++,loc[j][temp_j]++,loc[j][temp_j+1]++;
    }

    ///定义人的位置
    do{
        man_i=rand()%10+1;
        man_j=rand()%10+1;
    }while(loc[man_i][man_j]);
    m_Man_around();
    m_Print();
}

void m_Man_around(){
    int i,j;
    if(!cov[man_i][man_j]){uncover++;cov[man_i][man_j]=1;}
    if(!loc[man_i][man_j])
    for(i=man_i-1;i<=man_i+1;i++)
        for(j=man_j-1;j<=man_j+1;j++)
        if(!cov[i][j]&&loc[i][j]<=8&&i*j&&i<=m_Line&&j<=m_Col){
            uncover++;cov[i][j]=1;}

}

void m_Control(){
    char operation=getch();  /*键入操作 awsd;*/
	switch(operation){
		/*向左*/
        case 75:
		case 'a':
		case 'A':
			m_Turn_left();
			break;
		/*向右*/
		case 77:
		case 'd':
		case 'D':
		    m_Turn_right();
		    break;
		/*向上*/
        case 72:
		case 'w':
		case 'W':
			m_Turn_up();
			break;
		/*向下*/
        case 80:
		case 's':
		case 'S':
			m_Turn_down();
			break;
		default:
			return 0;
	}//end switch
	return;

}

    void m_Turn_left(){
        if(man_j>1) man_j--;
    }
    void m_Turn_down(){
        if(man_i<m_Line)    man_i++;
    }
    void m_Turn_right(){
        if(man_j<m_Col) man_j++;
    }
    void m_Turn_up(){
        if(man_i>1)    man_i--;
    }

int m_Is_over(){
    if(loc[man_i][man_j]>8){m_Lose(); return 0;}
    else if(uncover>=90){m_Win();return 0;}
    return 1;
}

void m_Lose(){
    int i,j;
    for(i=1;i<=m_Line;i++)
        for(j=1;j<=m_Col;j++)
            if(loc[i][j]>=8)    cov[i][j]=1;
    m_Print();
    printf("\n\n\t\tYOU LOSE!\n");
}
void m_Win(){
    printf("\n\n\t\tYOU WIN!\n");
}
