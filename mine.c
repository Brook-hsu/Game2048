#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///ɨ����Ϸģ�飬��MineSweep()�൱��Դ�ļ���main()����������������Ϸ����
///Ϊ��ֹ��2048��ͻ��������������ͳһ��ǰ׺  m_  �����ܻ��е㷳��
///��Ϸ˼·��
///1.��10��10�����������ʮ����
///2.��һ��С�ˣ�����û���׵ĵط�Ϲ��
///3.���ܱ������ֱ���
///4.ʤ��������С�˰�����ȷ������߹��������׵���
///����������

///�����������������ͷ
///һ����ʼ��ֵ������ʮ��������������������ÿ�������Ӧ���֣��������з��촦��cover״̬0
///��������С���ƶ�Control������Ƚϼ򵥣���ע����ƶ�����
///����С��ÿ�ƶ�һ�μ���һ��compute��С���ܱ߰˸�����uncover״̬
///ע�⣺ ����ֻ��cover��uncover����ı�,coverʱ��ʾ�ڿ�,uncoverʱ��ʾ���ֻ�հ�

short cov[12][12];///δ֪��1����֪��0
short loc[12][12];
short m_Col=10,m_Line=10;
short man_i,man_j;
short uncover;

void m_Print();
void m_Initial();///�����������initial������
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
    system("title ɨ��");
    m_Initial();
    do{
        m_Control();
        m_Man_around();
        m_Print();
    }while(m_Is_over());
}


void m_Print(){

    system("cls");
    printf("\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n\n");
    int i,j;
    ///Head
    printf("\t\t�X");
    for(j=1;j<=m_Col;j++)        printf("�T�T");
    printf("�[");
    printf("\t�ף�10��\n");
    ///body
    for(i=1;i<=m_Line;i++){
        printf("\t\t�U");
        for(j=1;j<=m_Col;j++){
            if(!cov[i][j])  printf("��");
            else{
                if(i==man_i&&j==man_j)  printf("��");
                else if(loc[i][j]&&loc[i][j]<9)  printf(" %d",loc[i][j]);
                else if(loc[i][j])  printf(" *");
                else    printf("  ");
            }
        }
        printf("�U\n");
    }
    ///foot
    printf("\t\t�^");
    for(j=1;j<=m_Col;j++)        printf("�T�T");
    printf("�a\n");
    printf("\t\t����%d��\n",90-uncover);
    printf("\t\tw:��  s:��  a:��  d:��\n\n");
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
    ///����ʮ���ף�����loc>=9
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

    ///�����˵�λ��
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
    char operation=getch();  /*������� awsd;*/
	switch(operation){
		/*����*/
        case 75:
		case 'a':
		case 'A':
			m_Turn_left();
			break;
		/*����*/
		case 77:
		case 'd':
		case 'D':
		    m_Turn_right();
		    break;
		/*����*/
        case 72:
		case 'w':
		case 'W':
			m_Turn_up();
			break;
		/*����*/
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
