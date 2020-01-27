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
#include<conio.h>
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
    Initial();
    for(;1;){
        Print();
        Control();
    }




    return 0;
}

void Print(){
    system("cls");
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
            if(!num[i][j]){printf("�U    ");continue;}
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


///��ʼ������
void Initial()
{
	int i,j;
	for(i=1;i<Line+1;++i){
		for(j=1;j<Col+1;++j){
			num[i][j]=2;
		}
	}
}
///��ʼ�����
/*��ʵ��ȫ�ֱ������û����ʽ��ʼ���Ļ�����������ʱ�ᱻ�Զ���ʼ��Ϊ 0 */


///function 'Control':
void Control()
{
	char operation;
	operation=getch();  /*������� awsd;*/

	switch(operation){

		/*����*/
		case 'a':
		case 'A':
			Turn_left();
			break;


		/*����*/
		case 'd':
		case 'D':
		    Turn_right();
		    break;

		/*����*/
		case 'w':
		case 'W':
			Turn_up();
			break;

		/*����*/
		case 's':
		case 'S':
			Turn_down();
			break;

	}//end switch
}
///end function 'Control';
///�ƶ�����
    void Turn_left(){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=1;j<=Col;j++){
                if(!num[i][j])for(temp=j+1;temp<=Col;temp++)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;}
                if(!num[i][j])continue;
                for(temp=j+1;temp<=Col;temp++){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[i][temp])continue;      ///�հ״���
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        ///�����Ʒֲ���
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=j+1){
                        num[i][j+1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///��ͬʱ��ײ
                }
            }
        }
    }
    void Turn_right(){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=Col;j>=1;j--){
                if(!num[i][j])for(temp=j-1;temp>=1;temp--)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;}
                if(!num[i][j])continue;
                for(temp=j-1;temp>=1;temp--){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[i][temp])continue;      ///�հ״���
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        ///�����Ʒֲ���
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=j-1){
                        num[i][j-1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///��ͬʱ��ײ
                }
            }
        }
    }
    void Turn_up(){
        int i,j,temp;
        for(j=1;j<=Col;j++){
            for(i=1;i<=Line;i++){
                if(!num[i][j])for(temp=i+1;temp<=Line;temp++)if(num[temp][j]){num[i][j]=num[temp][j];num[temp][j]=0;}
                if(!num[i][j])continue;
                for(temp=i+1;temp<=Line;temp++){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[temp][j])continue;      ///�հ״���
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        ///�����Ʒֲ���
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=i+1){
                        num[i+1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///��ͬʱ��ײ
                }
            }
        }
    }
    void Turn_down(){
        int i,j,temp;
        for(j=1;j<=Col;j++){
            for(i=Line;i>=1;i--){
                if(!num[i][j])for(temp=i-1;temp>=1;temp--)if(num[temp][j]){num[i][j]=num[temp][j];num[temp][j]=0;}
                if(!num[i][j])continue;
                for(temp=i-1;temp>=1;temp--){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[i][temp])continue;      ///�հ״���
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        ///�����Ʒֲ���
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=i-1){
                        num[i-1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///��ͬʱ��ײ
                }
            }
        }
    }

