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
///地图库
/// 0 代表着空白的地方； 1 代表着墙；2 代表着人； 3 代表着箱子；4 代表着箱子的终点位置。
///被压缩（写成一行）的地图参数，一则节省空间，二则防偷代码，三则提高逼格
int level1[8][8]={{0,0,1,1,1,0,0,0},{0,0,1,4,1,0,0,0},{0,0,1,0,1,1,1,1},{1,1,1,3,0,3,4,1},{1,4,0,3,2,1,1,1},{1,1,1,1,3,1,0,0},{0,0,0,1,4,1,0,0},{0,0,0,1,1,1,0,0}};
int level2[9][9]={{1,1,1,1,1,0,0,0,0},{1,2,0,0,1,0,0,0,0},{1,0,3,3,1,0,1,1,1},{1,0,3,0,1,0,1,4,1},{1,1,1,0,1,1,1,4,1},{0,1,1,0,0,0,0,4,1},{0,1,0,0,0,1,0,0,1},{0,1,0,0,0,1,1,1,1},{0,1,1,1,1,0,0,0,0}};
int level3[7][10]={{0,1,1,1,1,1,1,1,0,0},{0,1,0,0,0,0,0,1,1,1},{1,1,3,1,1,1,0,0,0,1},{1,0,2,0,3,0,0,3,0,1},{1,0,4,4,1,0,3,0,1,1},{1,0,4,4,1,0,0,0,1,1},{0,1,1,1,1,1,1,1,1,0}};
int level4[8][6]={{0,1,1,1,1,0},{1,1,0,0,1,0},{1,2,3,0,1,0},{1,1,3,0,1,1},{1,1,0,3,1,1},{1,4,3,0,0,1},{1,4,4,0,4,1},{1,1,1,1,1,1},};




void Sokoban(){
    system("title 无聊的推箱子");
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
    ///先归零，相当于Initial
    for(i=0;i<9;i++)    for(j=0;j<11;j++)   map[i][j]=0;
    ///赋值地图参数
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
        printf("嘿嘿\n\n遇到BUG了吧（其实是后面的地图还没做），想玩别的就关掉窗口再打开吧\n");
        system("pause");
    }

    if(game_level==9){
        int levelx[9][11]={
            {0,1,1,1,1,1,1,1,1,1,0},{0,1,0,0,0,1,0,0,0,1,0},{0,1,0,0,3,0,0,0,0,1,0},{0,1,0,3,0,3,3,3,0,1,1},{0,1,0,0,0,2,0,0,0,0,1},{1,1,0,0,1,1,1,0,3,0,1},{1,0,4,4,0,4,0,0,0,0,1},{1,0,4,4,0,4,4,3,0,1,1},{1,1,1,1,1,1,1,1,1,1,0}
                        };
        ///将level赋值给map
        for(i=0;i<9;i++)    for(j=0;j<11;j++)   map[i][j]=levelx[i][j];
    }
}


int drawmain(){
  int i,j;
    printf("\n\n\t\t\t\t第%d关\n\n\n\n",game_level);
	for(i=0;i<9;i++){
	    printf("\t\t\t");
	   for(j=0;j<11;j++){
           switch(map[i][j]){
                case 0:
                    printf("  "); //空白的地方
                    break;
                case 1:
                    printf("■"); //墙
                    break;
                case 2:
                    printf("♀"); //人
                    break;
                case 3:
                    printf("□"); //箱子
                    break;
                case 4:
                    printf("◎"); //终点地方
                     break;
                case 6:
                    printf("♂");//人加终点位置
                    break;
                case 7:
                    printf("★") ;//箱子加终点位置
                    break;
                 }
          }
        printf("\n");
	}

    printf("\n\t\t■--墙 ♀--人 □--箱子 ◎--终点\n\n");
}

///进行小人的移动，整个移动的过程就是数组变化的过程
int tuidong(){
	int count,caw=0;//行和列
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
			// 1.人的前面是空地；
		    // 2.人的前面是终点位置；
			// 3.人的前面是箱子
		    //3.1.箱子的前面是空地；
			//3.2.箱子的前面是终点位置。
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
        case 's':case 'S':case 80://键值
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
	int k = 0;//初始化
	int j,i;
	///判断箱子是否都归位
	for(i=0;i<9;i++)    for (j=0;j<11;j++)  if(map[i][j]==3)    k++;
    ///过关
	if(!k){
        Goto(1,1);
        drawmain();
        color(111);
		printf("\t\t恭喜你，你赢了！\n");
		color(7);
        return 1;
	}
	else    return 0;
}

int s_Is_next_level(){
    int index=1;
    printf("\n\t——————是否进入下一关——————\n\n");
    s_Is_next_level_print(index);
    while(1){
        char operation=getch();  /*键入操作 awsd;*/
        switch(operation){
            /*向右*/
            case 77:
            case 'd':
            case 'D':
                if(index){index--;
                printf("\r");
                s_Is_next_level_print(index);}
                break;
            /*向左*/
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
    printf("\t          是          ");
    color(7);
    if(!n)  color(244);
    printf("          否          ");
    color(7);
}
