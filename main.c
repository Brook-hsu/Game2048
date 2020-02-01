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
#include<Windows.h>

#define Count_of_game 4

int game;


void Welcome();
void A_Control();
int Is_continue();
void Is_continue_print(int n);

void Game2048();
void MineSweep();
void Sudoku_demo();


///main������Ϊ���壬��ͼҪһĿ��Ȼ����������Ҫ̫�࣬��Ҫ�����������Զ��庯��
int main()
{
    do{
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
    }while(Is_continue());
    return 0;
}


void Welcome(){
    printf("\n\n\n\t\t\t\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n"
    "\t\t\t\t��ӭ����ʱ��ն���\n"
    "\n\t\t\t\t��Ϸ�Կ����У�����ĳЩȱ©��������1.2.3.�����ߣ�\n"
    "\t\t\t\t������bug��Ӱ����Ϸ����,��Ҳ����:)\n\n"
    "\t\t\t\tף����Ϸ��죡"
    "\n\n\n"
    "\t\t\t\t��ѡ����Ϸ :\n");
    printf("\t\t\t\t");
    if(game==0){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
        printf("0. ������Ϸ\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("0. ������Ϸ\n\t\t\t\t");
    }

    if(game==1){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
        printf("1. ��Ϸ2048\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("1. ��Ϸ2048\n\t\t\t\t");
    }

    if(game==2){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
        printf("2. ɨ��\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("2. ɨ��\n\t\t\t\t");
    }

    if(game==3){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
        printf("3. ��ʤ����\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("3. ��ʤ����\n\t\t\t\t");
    }

    if(game==4){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
        printf("4. ����\n\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else{
        printf("4. ����\n\t\t\t\t");
    }


}


void A_Control(){
    game=0;
    while(1){
        system("cls");
        Welcome();
        char operation=getch();  /*������� awsd;*/
        switch(operation){
            /*����*/
            case 72:
            case 'w':
            case 'W':
                if(game>0)game--;
                break;
            /*����*/
            case 80:
            case 's':
            case 'S':
                if(game<Count_of_game)game++;
                break;
            case 13:
                return ;
            default:
                continue;
        }//end switch
    }
	return;
}

int Is_continue(){
    int index=1;
    printf("\t����������Ϸ�ѽ������Ƿ�ص���ҳ�桪������\n\n");
    Is_continue_print(index);
    while(1){
        char operation=getch();  /*������� awsd;*/
        switch(operation){
            /*����*/
            case 77:
            case 'd':
            case 'D':
                if(index){index--;
                printf("\r");
                Is_continue_print(index);}
                break;
            /*����*/
            case 75:
            case 'a':
            case 'A':
                if(!index){index++;
                printf("\r");
                Is_continue_print(index);}
                break;
            case 13:
                return index;
            default:
                continue;
        }//end switch
    }
}

void Is_continue_print(int n){
    if(n){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle,BACKGROUND_GREEN );// ����Ϊ��ɫ
        printf("\t          ��          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else    printf("\t          ��          ");
    if(!n){
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
        SetConsoleTextAttribute(handle,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED| FOREGROUND_RED );// ����Ϊ��ɫ
        printf("          ��          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else    printf("          ��          ");
}
