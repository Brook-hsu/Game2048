/*�������ĵĳ���*/

///��Ϸ2048����̨
///������
///1.��ӡ���棨ÿ�δ�ӡҪ��ˢ�£�
///2.��ʼ������
///3.���뷽���
///4.��Ӧ����
///5.���λ����������
///6.�Ƿ���
///7.�ж���Ϸ�Ƿ�������ǣ��������񣺻ص�3��

///����������������ɲ��ֺ�����ͳһ�������������Լ�ϲ������д�ģ��Ĳ���д

///�����������Ұٶȣ���ˢ��ͬѧҲ�У����Լ�Ҳ���ᣬ�������Է�����ȷ�ϣ���Ц��������
#include <stdio.h>
#include <stdlib.h>
///����ȫ�ֱ���4*4������num[1][1]��ʼ
int num[5][5],Line=4,Col=4;
///�Զ��庯��    �������庯����Ϊvoid�����ܺ�����ЩҪ��Ϊint
/*��ӡ����*/
void Print();
/*��ʼ������*/
void Initial();
/*���뷽���*////����Ҫ�ٶȽ��
void Control();
    void Turn_left();
    void Turn_right();
    void Turn_up();
    void Turn_down();
/*���������*////��rand()����
void New_random();
/*�ж���Ϸ�Ƿ����*/
void Is_over();


///main������Ϊ���壬��ͼҪһĿ��Ȼ����������Ҫ̫�࣬��Ҫ�����������Զ��庯��
int main()
{
    Print();
    return 0;
}

void Print(){
    int i,j;
    ///Head
    printf("�X");
    for(j=1;j<=Col;j++){
        printf("�T�T�T�T");
        if(Col-j)   printf("�j");
    }
    printf("�[\n");
    ///body
    for(i=1;i<=Line;i++){
        for(j=1;j<=Col;j++){
            printf("�U%4d",num[i][j]);
        }
        printf("�U\n");
        if(i-Line){
        for(j=1;j<=Col;j++){
            printf("�U�T�T�T�T");
        }
        printf("�U\n");}
    }
    ///foot
    printf("�^");
    for(j=1;j<=Col;j++){
        printf("�T�T�T�T");
        if(Col-j)   printf("�m");
    }
    printf("�a");


}
