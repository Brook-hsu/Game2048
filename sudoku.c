/*
# ���Ҫдһ���������������飨���������е�ࣩ
**����**��Ŀǰ��˼·��дһ���ܽ������Ļ���
          Ҳ����˵�������������������
          ���ǣ������������⣬��������ȫ

          ���ԣ������Ϸ���ǣ�������һ���Ѿ������������
          Ȼ������³�һ������������

**���**����Ϸ���̣������׶�
    ��һ�׶Σ���Printһ���Ź���ȫ�հף�����һ����꣨�ο�ɨ���е�С�ˣ��������Ӧλ�õ�����
                ��Control�����ƹ����ƶ����ƶ�����Ҫ����ĵط���
                Ȼ��p��������Ҳ�У�������ӦControl���case 'p'������������״̬Input������scanf()��
                ����󴢴���su[][]�Ȼ�󷵻ع���ƶ�״̬����������������Ϻ��
                ��enter���������̣��Խ�ˢ��ͬѧ�ĳ���
    �ڶ��׶Σ�ˢ��ͬѧ

**index**��
    ������ͬѧ�������ĵط���sudoku_demo(){}���ָ������͸�����{}��
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
void s_Input(int m,int n);///�����ͺ���������������
int s_Scan(int m,int n);
int s_Is_over();

void Sudoku_demo(){
    system("cls");
    printf("\t\tWelcome!\n\n\t\tChen!");

    int i,j;
    /*������ͬѧ�������ĵط�

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
    ///����һ��ɨ��
    for(temp=1;temp<10;temp++){
        if(store=su[m][temp])
            s[store]++;
        if(store=su[temp][n])
            s[store]++;
    }
    ///����ɨ��
    a=(m-1)%3,b=(n-1)%3;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(store=su[a*3+i][b*3+j])
                s[store]++;
    store=0;
    ///�������
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
