/*�������ĵĳ���*/

///��Ϸ2048
///1.��ӡ���棨ÿ�δ�ӡҪ��ˢ�£�2.��ʼ������3.���뷽���4.��Ӧ����5.���λ����������6.�Ƿ���7.�ж���Ϸ�Ƿ�������ǣ��������񣺻ص�3��

///��Ϸɨ��
///

///��ʤ����

///����

///����������������ɲ��ֺ�����ͳһ�������������Լ�ϲ������д�ģ��Ĳ���д
///�����������Ұٶȣ���ˢ��ͬѧҲ�У����Լ�Ҳ���ᣬ�������Է�����ȷ�ϣ���Ц��������

#include <stdio.h>
#include <stdlib.h>

#define Count_of_game 4

int game;


void Welcome();
void A_Control();

void Game2048();
void MineSweep();
void Sudoku_demo();


///main������Ϊ���壬��ͼҪһĿ��Ȼ����������Ҫ̫�࣬��Ҫ�����������Զ��庯��
int main()
{
    do{
    system("color 06");
    A_Control();
    if(game)
    switch(game){
        case 1:
            Game2048();
        break;
        case 2:
            MineSweep();
        break;
        case 3:
            General();
        break;
        case 4:
            Sudoku_demo();
        break;
    }
    else break;
    }while(1);
    return 0;
}


void Welcome(){
    printf("\n\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n"
    "\t~��ӭ����****��û��ã���Ϸ~��\n"
    "/*\n��Ϸ�Կ����У�����ĳЩȱ©��������1.2.3.�����ߣ�\n"
    "������bug��Ӱ����Ϸ����\n�뽫���ⷢ��a13288007769@163.com\n*/\n"
    "\t***************************\n"
    "\t��ѡ����Ϸ��\n\t");
    if(game==1)printf("***");
    printf("1. ��Ϸ2048\n\t");
    if(game==2)printf("***");
    printf("2. ɨ��\n\t");
    if(game==3)printf("***");
    printf("3. ��ʤ����\n\t");
    if(game==4)printf("***");
    printf("4. ����\n\t");


    if(game==Count_of_game+1)printf("***");
    printf("0. �˳���Ϸ\n"
    "\t***************************\n");
}


void A_Control(){
    game=1;
    while(1){
        system("cls");
        Welcome();
        char operation=getch();  /*������� awsd;*/
        switch(operation){
            /*����*/
            case 72:
            case 'w':
            case 'W':
                if(game>1)game--;
                break;
            /*����*/
            case 80:
            case 's':
            case 'S':
                if(game<=Count_of_game+1)game++;
                break;
            case 13:
                return ;
            default:
                continue;
        }//end switch
    }
	return;
}

