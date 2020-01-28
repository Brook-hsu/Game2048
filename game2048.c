#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/*��ӡ����*/
void Print(int **num,int Line,int Col);

/*��ʼ������*/
void Initial(int **num,int Line,int Col);

/*���뷽���*/
int Control(int **num,int Line,int Col);
    void Turn_left(int **num,int Line,int Col);
    void Turn_right(int **num,int Line,int Col);
    void Turn_up(int **num,int Line,int Col);
    void Turn_down(int **num,int Line,int Col);

/*���������*/
///��rand()����
void New_random(int **num,int Line,int Col);

/*�ж���Ϸ�Ƿ����*/
int Is_over(int **num,int Line,int Col);
    void Lose();
    void Win();

int Score;

void Game2048(){
    system("cls");
    system("color 03");
    int Line,Col;
    printf("\n\n\n\n\n\t\t\t%s\n","input the number of Line and Column you want");
    printf("\t\t\t%s\t","Line:");
    scanf("%d",&Line);
    printf("\t\t\t%s\t","Columm:");
    scanf("%d",&Col);
    //�˴����Ӷ�ά���������ڴ�
    int **num;
    int i;
    num=(int **)malloc(sizeof(*num)*(Line+1));
    for(i=0;i<Line+1;++i)    num[i]=(int *)malloc(sizeof(**num)*(Col+1));
    Initial(num,Line,Col);
    New_random(num,Line,Col);
    New_random(num,Line,Col);//�˴��հ�ԭ��Ϸ��ʹ��һ��ʼ����������������
    int judge=1;
    while(judge==1){
        Print(num,Line,Col);
        judge=Is_over(num,Line,Col);
        if(judge==2||judge==0)			break;
        if(!Control(num,Line,Col))  continue;
        New_random(num,Line,Col);
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
void New_random(int **num,int Line,int Col)
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
int Control(int **num,int Line,int Col)
{
	char operation;
	operation=getch();  /*������� awsd;*/
	switch(operation){
		/*����*/
        case 75:
		case 'a':
		case 'A':
			Turn_left(num,Line,Col);
			break;
		/*����*/
		case 77:
		case 'd':
		case 'D':
		    Turn_right(num,Line,Col);
		    break;
		/*����*/
        case 72:
		case 'w':
		case 'W':
			Turn_up(num,Line,Col);
			break;
		/*����*/
        case 80:
		case 's':
		case 'S':
			Turn_down(num,Line,Col);
			break;
		default:
			return 0;
	}//end switch
	return 1;
}
///end function 'Control';
///�ƶ�����
    void Turn_left(int **num,int Line,int Col){
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
    void Turn_right(int **num,int Line,int Col){
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
    void Turn_up(int **num,int Line,int Col){
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
    void Turn_down(int **num,int Line,int Col){
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


void Print(int **num,int Line,int Col){
    system("cls");
    printf("\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n\n\n");
    printf("\t\t��ķ����ǣ�%4d\n",Score);
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
            if(!num[i][j]){printf("�U    ");continue;}
            printf("�U%4d",num[i][j]);
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
int Is_over(int **num,int Line,int Col)
{
	int i,j;//i �����м�����j �����м���///͵͵����һ�䣬�⺯���Ŀ�����ô��ô�������������ҿ������ң�

	//��ɨ���ж�
	for(j=Col;j>=1;--j){
		for(i=Line;i>=1;--i){

			if(num[i][j]==2048){
				return 2;//����2048��ʤ������Ϸ����
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

void Lose(){
    printf("\n\n\t\t YOU LOSE !\n\n");
}
void Win(){
    printf("\n\n\t\t YOU WIN !\n\n");
}

