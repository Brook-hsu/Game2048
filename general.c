#include <stdio.h>
void General()
{
    system("cls");
    int computer, people, spare = 21;
    printf("\t———————————联合出品，不作商业用———————————\n");
    printf(" \t\t-----------------------------------------\n");
    printf(" \t\t--------  你不能战胜我,不信试试  --------\n");
    printf(" \t\t-----------------------------------------\n\n");
    printf("游戏规则:\n\t这里共有21根火柴，电脑和你依次取，每次每人只可取走1~4根，不能多取，也不能不取，谁取到最后一根火柴谁输。\n\n");
    while(1)
    {
        printf("\t-------------  目前还有火柴 %d 根 ------------\n", spare);
        printf("\t我要取:   根\b\b\b\b");
        scanf("%d", &people);
        if(people<1 || people>4 || people>spare)
        {
            printf("你违规了，你取的火柴数有问题!\n\n");
            continue;
        }
        spare = spare - people;
        if( spare==0 )
        {
            printf("\n\tComputer win! Game Over!\n");
            break;
        }
        computer = 5 - people;
        spare = spare - computer;
        printf("\t\t\t\t\t电脑取走了:%d 根 \n", computer);
        if( spare==0 )
        {
            printf("\nPeople win! Game Over!\n");
            break;
        }
    }
    return;
}
