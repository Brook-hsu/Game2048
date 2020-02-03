#include<stdio.h>
#include<conio.h>
#include<windows.h>

int drawmain();
int tuidong();
int winshu();
void Select_game_level();
int s_Is_next_level();
void s_Is_next_level_print(int n);

int game_level=1;
int map[9][11];
///��ͼ��
/// 0 �����ſհ׵ĵط��� 1 ������ǽ��2 �������ˣ� 3 ���������ӣ�4 ���������ӵ��յ�λ�á�
///��ѹ����д��һ�У��ĵ�ͼ������һ���ʡ�ռ䣬�����͵���룬������߱Ƹ�
int level1[8][8]={{0,0,1,1,1,0,0,0},{0,0,1,4,1,0,0,0},{0,0,1,0,1,1,1,1},{1,1,1,3,0,3,4,1},{1,4,0,3,2,1,1,1},{1,1,1,1,3,1,0,0},{0,0,0,1,4,1,0,0},{0,0,0,1,1,1,0,0}};
int level2[9][9]={{1,1,1,1,1,0,0,0,0},{1,2,0,0,1,0,0,0,0},{1,0,3,3,1,0,1,1,1},{1,0,3,0,1,0,1,4,1},{1,1,1,0,1,1,1,4,1},{0,1,1,0,0,0,0,4,1},{0,1,0,0,0,1,0,0,1},{0,1,0,0,0,1,1,1,1},{0,1,1,1,1,0,0,0,0}};
int level3[7][10]={{0,1,1,1,1,1,1,1,0,0},{0,1,0,0,0,0,0,1,1,1},{1,1,3,1,1,1,0,0,0,1},{1,0,2,0,3,0,0,3,0,1},{1,0,4,4,1,0,3,0,1,1},{1,0,4,4,1,0,0,0,1,1},{0,1,1,1,1,1,1,1,1,0}};
int level4[8][6]={{0,1,1,1,1,0},{1,1,0,0,1,0},{1,2,3,0,1,0},{1,1,3,0,1,1},{1,1,0,3,1,1},{1,4,3,0,0,1},{1,4,4,0,4,1},{1,1,1,1,1,1},};




void Sokoban(){
    system("title ���ĵ�������");
    do{
        system("cls");
        Select_game_level();
        while(1){
            Goto(1,1);
            drawmain();
            tuidong();
            if(winshu())    break;
        }
    }while(s_Is_next_level());
    printf("\n");
	return;
}

void Select_game_level(){
    int i,j;
    ///�ȹ��㣬�൱��Initial
    for(i=0;i<9;i++)    for(j=0;j<11;j++)   map[i][j]=0;
    ///��ֵ��ͼ����
    switch(game_level){
    case 1:
        for(i=0;i<8;i++)    for(j=0;j<8;j++)   map[i][j]=level1[i][j];
        break;
    case 2:
        for(i=0;i<9;i++)    for(j=0;j<9;j++)   map[i][j]=level2[i][j];
        break;
    case 3:
        for(i=0;i<7;i++)    for(j=0;j<10;j++)   map[i][j]=level3[i][j];
        break;
    case 4:
        for(i=0;i<8;i++)    for(j=0;j<6;j++)    map[i][j]=level4[i][j];
        break;
    default:
        printf("�ٺ�\n\n����BUG�˰ɣ���ʵ�Ǻ���ĵ�ͼ��û�����������ľ͹ص������ٴ򿪰�\n");
        system("pause");
    }

    if(game_level==9){
        int levelx[9][11]={
            {0,1,1,1,1,1,1,1,1,1,0},{0,1,0,0,0,1,0,0,0,1,0},{0,1,0,0,3,0,0,0,0,1,0},{0,1,0,3,0,3,3,3,0,1,1},{0,1,0,0,0,2,0,0,0,0,1},{1,1,0,0,1,1,1,0,3,0,1},{1,0,4,4,0,4,0,0,0,0,1},{1,0,4,4,0,4,4,3,0,1,1},{1,1,1,1,1,1,1,1,1,1,0}
                        };
        ///��level��ֵ��map
        for(i=0;i<9;i++)    for(j=0;j<11;j++)   map[i][j]=levelx[i][j];
    }
}


int drawmain(){
  int i,j;
    printf("\n\n\t\t\t\t��%d��\n\n\n\n",game_level);
	for(i=0;i<9;i++){
	    printf("\t\t\t");
	   for(j=0;j<11;j++){
           switch(map[i][j]){
                case 0:
                    printf("  "); //�հ׵ĵط�
                    break;
                case 1:
                    printf("��"); //ǽ
                    break;
                case 2:
                    printf("��"); //��
                    break;
                case 3:
                    printf("��"); //����
                    break;
                case 4:
                    printf("��"); //�յ�ط�
                     break;
                case 6:
                    printf("��");//�˼��յ�λ��
                    break;
                case 7:
                    printf("��") ;//���Ӽ��յ�λ��
                    break;
                 }
          }
        printf("\n");
	}

    printf("\n\t\t��--ǽ ��--�� ��--���� ��--�յ�\n\n");
}

///����С�˵��ƶ��������ƶ��Ĺ��̾�������仯�Ĺ���
int tuidong(){
	int count,caw=0;//�к���
	int i,j,tui;
	for(i=0;i<9;i++)
		for (j=0;j<11;j++)
			if(map[i][j]==2||map[i][j]==6)
			{
				count=i;
				caw=j;
			}
	tui=getch();
    switch(tui)
	{
	    case 'w':case 'W':case 72:
			// 1.�˵�ǰ���ǿյأ�
		    // 2.�˵�ǰ�����յ�λ�ã�
			// 3.�˵�ǰ��������
		    //3.1.���ӵ�ǰ���ǿյأ�
			//3.2.���ӵ�ǰ�����յ�λ�á�
		 if(map[count-1][caw]==0||map[count-1][caw]==4)
			{
				map[count][caw]-=2;
				map[count-1][caw]+=2;
			}
		 else if(map[count-1][caw]==3||map[count-1][caw]==7)
			{
				if(map[count-2][caw]==0||map[count-2][caw]==4)
				{
			      map[count][caw]-=2;
				  map[count-1][caw]-=1;
				  map[count-2][caw]+=3;
				}
			}
		break;
        case 's':case 'S':case 80://��ֵ
	    	 if(map[count+1][caw]==0||map[count+1][caw]==4)
			{
				map[count][caw]-=2;
				map[count+1][caw]+=2;
			}
			 else if(map[count+2][caw]==0||map[count+2][caw]==4)
			{
			   	if(map[count+1][caw]==3||map[count+1][caw]==7)
				{
			      map[count][caw]-=2;
				  map[count+1][caw]-=1;
				  map[count+2][caw]+=3;
				}
			}
			break;
        case 'a':case 'A':case 75:
	    		 if(map[count][caw-1]==0||map[count][caw-1]==4)
			{
				map[count][caw]-=2;
				map[count][caw-1]+=2;
			}
			  else if(map[count][caw-2]==0||map[count][caw-2]==4)
			{
			   	if(map[count][caw-1]==3||map[count][caw-1]==7)
				{
			      map[count][caw]-=2;
				  map[count][caw-1]-=1;
				  map[count][caw-2]+=3;
				}
			}
        	break;
        case 'd':case 'D':case 77:
		    	 if(map[count][caw+1]==0||map[count][caw+1]==4)
			{
				map[count][caw]-=2;
				map[count][caw+1]+=2;
			}
			  else if(map[count][caw+2]==0||map[count][caw+2]==4)
			{
			     if(map[count][caw+1]==3||map[count][caw+1]==7)
				{
			      map[count][caw]-=2;
				  map[count][caw+1]-=1;
				  map[count][caw+2]+=3;
				}
			}
		    break;
    }
}

int winshu(){
	int k = 0;//��ʼ��
	int j,i;
	///�ж������Ƿ񶼹�λ
	for(i=0;i<9;i++)    for (j=0;j<11;j++)  if(map[i][j]==3)    k++;
    ///����
	if(!k){
        Goto(1,1);
        drawmain();
        color(111);
		printf("\t\t��ϲ�㣬��Ӯ�ˣ�\n");
		color(7);
        return 1;
	}
	else    return 0;
}

int s_Is_next_level(){
    int index=1;
    printf("\n\t�������������Ƿ������һ�ء�����������\n\n");
    s_Is_next_level_print(index);
    while(1){
        char operation=getch();  /*������� awsd;*/
        switch(operation){
            /*����*/
            case 77:
            case 'd':
            case 'D':
                if(index){index--;
                printf("\r");
                s_Is_next_level_print(index);}
                break;
            /*����*/
            case 75:
            case 'a':
            case 'A':
                if(!index){index++;
                printf("\r");
                s_Is_next_level_print(index);}
                break;
            case 13:
                if(index)   game_level++;
                return index;
            default:
                continue;
        }///end switch
    }
}

void s_Is_next_level_print(int n){
    if(n)   color(47);
    printf("\t          ��          ");
    color(7);
    if(!n)  color(244);
    printf("          ��          ");
    color(7);
}
