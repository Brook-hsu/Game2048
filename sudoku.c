/*
# 这边要写一下数独开发的事情（文字描述有点多）
**首先**：目前的思路是写一个能解数独的机器
          也就是说，这个程序不能生成数独
          但是，它会做数独题，把数独补全

          所以：这个游戏就是，你输入一个已经可以玩的数独
          然后程序吐出一个补完后的数独

**其次**：游戏过程，两个阶段
    第一阶段：先Print一个九宫格，全空白，但有一个光标（参考扫雷中的小人）来输入对应位置的数，
                用Control来控制光标的移动，移动到需要输入的地方，
                然后按p（其他键也行）（即对应Control里的case 'p'：）进入输入状态Input（里有scanf()）
                输入后储存在su[][]里，然后返回光标移动状态，所有数字输入完毕后后
                按enter进入计算过程，对接刷子同学的程序
    第二阶段：刷子同学

**index**：
    给纯哥同学安插代码的地方是sudoku_demo(){}里的指定区域和各函数{}内
*/

#include<stdio.h>
///All thing is unknown

/*
    Waiting excellent coding by
    Chen
*/


int su[10][10];
short count;

void s_Print();
void s_Initial();
void s_Control();
    void s_Turn_left();
    void s_Turn_right();
    void s_Turn_up();
    void s_Turn_down();
void s_Input(int m,int n);///新类型函数，用来输入数
int s_Scan(int m,int n);
int s_Is_over();

void Sudoku_demo(){
    system("cls");
    printf("\t\tWelcome!\n\n\t\tChen!");

    int i,j;
    /*给纯哥同学安插代码的地方

    //s_Initial();








    */
    do{
        for(i=1;i<10;i++){
            for(j=1;j<10;j++){
                su[i][j]=s_Scan(i,j);
            }
        }


    }while(s_Is_over());

}

int s_Scan(int m,int n){
    int a,b,i,j,temp,store;
    int s[10]={0};
    ///行列一起扫描
    for(temp=1;temp<10;temp++){
        if(store=su[m][temp])
            s[store]++;
        if(store=su[temp][n])
            s[store]++;
    }
    ///方快扫描
    a=(m-1)%3,b=(n-1)%3;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(store=su[a*3+i][b*3+j])
                s[store]++;
    store=0;
    ///数组检验
    for(temp=1;temp<10;temp++){
        if(!s[temp]){
            if(!store)
                store=s[temp];
            else{
                store=0;
                break;
            }
        }
    }
    return store;

}
int s_Is_over(){
}
