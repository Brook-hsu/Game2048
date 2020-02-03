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

void s_Print(int status,int m,int n);
void s_Initial();
void s_Control();
    int s_Turn_left(int index);
    int s_Turn_right(int index);
    int s_Turn_up(int index);
    int s_Turn_down(int index);
void s_Input(int m,int n);///�����ͺ���������������
int s_Scan(int m,int n);
int s_Is_over();

void Sudoku_demo(){
    system("title ����");
    system("cls");

    int i,j;

    s_Initial();
    s_Control();


    do{
        for(i=1;i<10;i++){
            for(j=1;j<10;j++){
                su[i][j]=s_Scan(i,j);
            }
        }
    }while(s_Is_over());
    s_Print(0,0,0);
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
    if(store)   count++;
    return store;

}
int s_Is_over(){
    if(count==81)return 0;
    else return 1;
}

void s_Initial(){
    int i,j;
    for(i=1;i<10;i++){
        for(j=1;j<10;j++){
            su[i][j]=0;
        }
    }
    count=0;
}

void s_Print(int status,int m,int n){
    system("cls");
    printf("\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n\n\n");
    int i,j;
    ///Head
    printf("\t\t�X");
    for(j=1;j<10;j++){
        printf("�T�T�T�T");
        if(9-j)   printf("�j");
    }
    printf("�[\n");
    ///body
    for(i=1;i<10;i++){
        printf("\t\t");
        for(j=1;j<10;j++){
            if(!su[i][j])
                if(i==m&&j==n)
                    if(status)printf("�U  ��");
                    else printf("�U    ");
                else printf("�U    ");
            else printf("�U%4d",su[i][j]);
        }
        printf("�U\n\t\t");
        if(9-i){
        for(j=1;j<10;j++){
            printf("�U�T�T�T�T");
        }
        printf("�U\n");}
    }
    ///foot
    printf("�^");
    for(j=1;j<10;j++){
        printf("�T�T�T�T");
        if(9-j)   printf("�m");
    }
    printf("�a\n\n\n");
    printf("count is %d",count);
}

void s_Input(int m,int n){


}

void s_Control(){
    int cursor_i=1,cursor_j=1;
    do{
    s_Print(1,cursor_i,cursor_j);

    char operation=getch();  /*������� awsd;*/
	switch(operation){
		/*����*/
        case 75:
		case 'a':
		case 'A':
			cursor_j=s_Turn_left(cursor_j);
			break;
		/*����*/
		case 77:
		case 'd':
		case 'D':
            cursor_j=s_Turn_right(cursor_j);
		    break;
		/*����*/
        case 72:
		case 'w':
		case 'W':
			cursor_i=s_Turn_up(cursor_i);
			break;
		/*����*/
        case 80:
		case 's':
		case 'S':
			cursor_i=s_Turn_down(cursor_i);
			break;
        case 32:
            Goto(15+5*cursor_j,2+2*cursor_i);
            scanf("%d",&su[cursor_i][cursor_j]);
            getchar();
            count++;
            break;
        case 13:
            return;
		default:
		    continue;
	}//end switch
    }while(1);





}
int s_Turn_left(int index){
    if(index>1)index--;
    return index;
}
int s_Turn_right(int index){
    if(index<9)index++;
    return index;
}
int s_Turn_up(int index){
    if(index>1)index--;
    return index;
}
int s_Turn_down(int index){
    if(index<9)index++;
    return index;
}
