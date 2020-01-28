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
#include<time.h>

///����ȫ�ֱ���4*4������num[1][1]��ʼ
int num[5][5];
int Line=5;
int Col=4;
int Score;
///�Զ��庯�� ,�������庯����Ϊvoid�����ܺ�����ЩҪ��Ϊint

/*��ӡ����*/
void Print();

/*��ʼ������*/
void Initial();

/*���뷽���*/
int Control();
    void Turn_left();
    void Turn_right();
    void Turn_up();
    void Turn_down();

/*���������*/
///��rand()����
void New_random();

/*�ж���Ϸ�Ƿ����*/
int Is_over();


///main������Ϊ���壬��ͼҪһĿ��Ȼ����������Ҫ̫�࣬��Ҫ�����������Զ��庯��
int main()
{
	Initial();
	New_random();//�˴��հ�ԭ��Ϸ��ʹ��һ��ʼ����������������

	int judge=1;

	while(judge==1){

		Print();
		judge=Is_over();
		if(judge==2||judge==0){
			break;
		}
        if(!Control())continue;
        New_random();
	}
	if(judge==2)
		printf("%s","WIN");
	else
		printf("%s","LOSE");
    return 0;
}

void Print(){
    system("cls");
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
    printf("�a");
}


///��ʼ������
void Initial()
{
    Score=0;
	int i,j;
	for(i=0;i<=Line;++i){
		for(j=0;j<Col;++j){
			num[i][j]=0;
		}
	}
}
///��ʼ�����
/*��ʵ��ȫ�ֱ������û����ʽ��ʼ���Ļ�����������ʱ�ᱻ�Զ���ʼ��Ϊ 0 */


///function 'Control':
int Control()
{
	char operation;
	operation=getch();  /*������� awsd;*/
	switch(operation){
		/*����*/
		case 'a':
		case 'A':
        case 75:
			Turn_left();
			break;
		/*����*/
		case 'd':
		case 'D':
        case 77:
		    Turn_right();
		    break;
		/*����*/
		case 'w':
		case 'W':
        case 72:
			Turn_up();
			break;
		/*����*/
		case 's':
		case 'S':
        case 80:
			Turn_down();
			break;
		default:
			return 0;
	}//end switch
	return 1;
}
///end function 'Control';
///�ƶ�����
    void Turn_left(){
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
    void Turn_right(){
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
    void Turn_up(){
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
    void Turn_down(){
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

///function 'New_random'
void New_random()
{
	srand(time(NULL));
    int index=rand()%16;
	while(num[index/4+1][index%4+1])    index=(index+3)%16;
	/* �������λ��
	�˴��б�Ҫ�����Ż����������λ�����ɵ�ʱ��  */
	int a=rand()%2;
	if(a)
		num[index/4+1][index%4+1]=2;
	else
		num[index/4+1][index%4+1]=4;
	return;
}
///end function 'New_random'

/*
function 'Is_over"
���� 0 ��ʾ�ո���������Ϸ������
���� 1 ��ʾδ��������Ϸ������
���� 2 ��ʾ�������ֵ2048����Ϸʤ��������
*/
int Is_over()
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
