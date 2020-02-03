
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<Windows.h>

/*��ӡ����*/
void Print(int **num,int Line,int Col,int Target);

/*��ʼ������*/
void Initial(int **num,int Line,int Col);

/*���뷽���*/
int Control(int **num,int Line,int Col,int Target);
    void Turn_left(int **num,int Line,int Col,int Target);
    void Turn_right(int **num,int Line,int Col,int Target);
    void Turn_up(int **num,int Line,int Col,int Target);
    void Turn_down(int **num,int Line,int Col,int Target);

/*���������*/
///��rand()����
void New_random(int **num,int Line,int Col,int Target);

/*�ж���Ϸ�Ƿ����*/
int Is_over(int **num,int Line,int Col,int Target);

void difficulty_level();
void default_difficulty();

int Score;
int Choose_of_de_level;
int game2048;


void Game2048()
{
    system("title ��Ϸ2048");
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
        printf("\t\t\t������ҽ���������Ϊ4�ı���\n");
        printf("\t\t\t��Ŀ��ֵ��Ϊ����(Line)����4����������\n\t\t\t���� ����(Col)����4���������� �ٳ���512\n\n");
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

    //�˴����Ӷ�ά���������ڴ�
    int **num;
    int i;
    num=(int **)malloc(sizeof(*num)*(Line+1));
    for(i=0;i<Line+1;++i)    num[i]=(int *)malloc(sizeof(**num)*(Col+1));
    Initial(num,Line,Col);
    New_random(num,Line,Col,Target);
    New_random(num,Line,Col,Target);//�˴��հ�ԭ��Ϸ��ʹ��һ��ʼ����������������
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

///��ʼ������
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
///��ʼ�����
/*��ʵ��ȫ�ֱ������û����ʽ��ʼ���Ļ�����������ʱ�ᱻ�Զ���ʼ��Ϊ 0 */


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
	/* �������λ��
	�˴��б�Ҫ�����Ż����������λ�����ɵ�ʱ��  */
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
	operation=getch();  /*������� awsd;*/
	switch(operation){
		/*����*/
        case 75:
		case 'a':
		case 'A':
			Turn_left(num,Line,Col,Target);
			break;
		/*����*/
		case 77:
		case 'd':
		case 'D':
		    Turn_right(num,Line,Col,Target);
		    break;
		/*����*/
        case 72:
		case 'w':
		case 'W':
			Turn_up(num,Line,Col,Target);
			break;
		/*����*/
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
///�ƶ�����
    void Turn_left(int **num,int Line,int Col,int Target){
        int i,j,temp;
        for(i=1;i<=Line;i++){
            for(j=1;j<=Col;j++){
                if(!num[i][j])for(temp=j+1;temp<=Col;temp++)if(num[i][temp]){num[i][j]=num[i][temp];num[i][temp]=0;break;}
                if(!num[i][j])continue;
                for(temp=j+1;temp<=Col;temp++){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[i][temp])continue;      ///�հ״���
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        Score+=num[i][j];
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=j+1){
                        num[i][j+1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///��ͬʱ��ײ
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
                for(temp=j-1;temp>=1;temp--){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[i][temp])continue;      ///�հ״���
                    if(num[i][j]==num[i][temp]){
                        num[i][j]*=2;num[i][temp]=0;
                        Score+=num[i][j];
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=j-1){
                        num[i][j-1]=num[i][temp];num[i][temp]=0;
                    break;}                         ///��ͬʱ��ײ
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
                for(temp=i+1;temp<=Line;temp++){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[temp][j])continue;      ///�հ״���
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        Score+=num[i][j];
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=i+1){
                        num[i+1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///��ͬʱ��ײ
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
                for(temp=i-1;temp>=1;temp--){     ///����tempѭ�����ã����temp��j�Ƚ�
                    if(!num[temp][j])continue;      ///�հ״���
                    if(num[i][j]==num[temp][j]){
                        num[i][j]*=2;num[temp][j]=0;
                        Score+=num[i][j];
                    break;}                         ///��ͬʱ�ϲ�
                    else if(temp!=i-1){
                        num[i-1][j]=num[temp][j];num[temp][j]=0;
                    break;}                         ///��ͬʱ��ײ
		    break;
                }
            }
        }
    }


void Print(int **num,int Line,int Col,int Target){
    Goto(1,1);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
    printf("\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n\n\n");
    printf("\t\t��ķ����ǣ�%4d\n",Score);
    printf("\n\t\t����Ҫ�ϲ���%d\n",Target);
    int i,j;
    ///Head
    printf("\t\t�X");
    for(j=1;j<=Col;j++){
        printf("�T�T�T�T");
        if(Col-j)   printf("�j");
    }
    printf("�[\n");
    ///body
    for(i=1;i<=Line;i++){
        printf("\t\t");
        for(j=1;j<=Col;j++){
            if(!num[i][j])printf("�U    ");
            else {
                printf("�U");
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
        printf("�U\n\t\t");
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
    printf("�a\n\n\n");
    printf("\t\tw:��  s:��  a:��  d:��");
}


/*
function 'Is_over"
���� 0 ��ʾ�ո���������Ϸ������
���� 1 ��ʾδ��������Ϸ������
���� 2 ��ʾ�������ֵ2048����Ϸʤ��������
*/
int Is_over(int **num,int Line,int Col,int Target)
{
	int i,j;//i �����м�����j �����м���///͵͵����һ�䣬�⺯���Ŀ�����ô��ô�������������ҿ������ң�

	//��ɨ���ж�
	for(j=Col;j>=1;--j){
		for(i=Line;i>=1;--i){

			if(num[i][j]==Target){
				return 2;//����Target��ʤ������Ϸ����
			}

			else{

				if(num[i][j]==0){
					return 1;//û��2048�����пո���Ϸ������
				}

				else{
					if(num[i][j-1]==num[i][j]){
				    	return 1;//������δ�������������Ϸ����
				    }
				}

			}
		}
	}
	//��ɨ���жϽ���

	//��ɨ���жϲ��֣��ò���ֻ���ж���������Ƿ��ܺϲ�
	for(i=Line;i>=1;--i){
		for(j=Col;j>=1;--j){
			if(num[i-1][j]==num[i][j]){
				return 1;
			}
		}
	}
	 //��ɨ���жϽ������ֽ���

	//�����е��������û�пո�û�����ֵ����������
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
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
                 printf("%s Ĭ���Ѷ�\n\n","Default difficulty");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("%s Ĭ���Ѷ�\n\n","Default difficulty");
            }

            printf("\t\t\t\t\t");
            if(game2048==2){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
                 printf("%s �Զ����Ѷ�\n\n","Custom difficulty");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("%s �Զ����Ѷ�\n\n","Custom difficulty");
            }


            printf("\t\t\t\t\t");
            if(game2048==Choice_of_game2048+1){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
                 printf("�˳�2048��Ϸ\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("�˳�2048��Ϸ\n\n");
            }

            char choose=getch();
            switch(choose){
            /*����*/
            case 72:
            case 'w':
            case 'W':
                if(game2048>1)game2048--;
                break;
            /*����*/
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
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
                 printf("4��4��\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("4��4��\n\n");
            }

            printf("\t\t\t\t\t");
            if(Choose_of_de_level==2){
                 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨���
                 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);// ����Ϊ��ɫ
                 printf("8��8��\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else{
                printf("8��8��\n\n");
            }

            char choose=getch();
            switch(choose){
            /*����*/
            case 72:
            case 'w':
            case 'W':
                if(Choose_of_de_level>1)Choose_of_de_level--;
                break;
            /*����*/
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
