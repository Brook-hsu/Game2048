#include <stdio.h>
#include <stdlib.h>

///ɨ����Ϸģ�飬��MineSweep()�൱��Դ�ļ���main()����������������Ϸ����
///Ϊ��ֹ��2048��ͻ��������������ͳһ��ǰ׺  m_  �����ܻ��е㷳��
///��Ϸ˼·��
///1.��10��10�����������ʮ����
///2.��һ��С�ˣ�����û���׵ĵط�Ϲ��
///3.���ܱ������ֱ���
///4.ʤ��������С�˰�����ȷ������߹��������׵���
///����������

short loc[11][11];///���ױ�1�����ױ�0
int m_Col=10,m_Line=10;

void m_Print();
void m_Initial();///�����������initial������
void m_Control();
    void m_Turn_left();
    void m_Turn_right();
    void m_Turn_up();
    void m_Turn_down();
void m_Is_over();

void MineSweep(){
    //m_Initial();
    m_Print();

}


void m_Print(){
    system("cls");
    printf("\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n\n");
    int i,j;
    ///Head
    printf("\t\t�X");
    for(j=1;j<=m_Col;j++){
        printf("�T�T");
        if(m_Col-j)   printf("�j");
    }
    printf("�[\n");
    ///body
    for(i=1;i<=m_Line;i++){
        printf("\t\t");
        for(j=1;j<=m_Col;j++){
            if(!loc[i][j]){printf("�U��");continue;}
        }
        printf("�U\n\t\t");
        if(i-m_Line){
        for(j=1;j<=m_Col;j++){
            printf("�U�T�T");
        }
        printf("�U\n");}
    }
    ///foot
    printf("�^");
    for(j=1;j<=m_Col;j++){
        printf("�T�T");
        if(m_Col-j)   printf("�m");
    }
    printf("�a\n\n");
    printf("\t\tw:��  s:��  a:��  d:��");
}

