#include <stdio.h>
void General()
{
    system("cls");
    int computer, people, spare = 21;
    printf("\t�������������������������ϳ�Ʒ��������ҵ�á���������������������\n");
    printf(" \t\t-----------------------------------------\n");
    printf(" \t\t--------  �㲻��սʤ��,��������  --------\n");
    printf(" \t\t-----------------------------------------\n\n");
    printf("��Ϸ����:\n\t���ﹲ��21����񣬵��Ժ�������ȡ��ÿ��ÿ��ֻ��ȡ��1~4�������ܶ�ȡ��Ҳ���ܲ�ȡ��˭ȡ�����һ�����˭�䡣\n\n");
    while(1)
    {
        printf("\t-------------  Ŀǰ���л�� %d �� ------------\n", spare);
        printf("\t��Ҫȡ:   ��\b\b\b\b");
        scanf("%d", &people);
        if(people<1 || people>4 || people>spare)
        {
            printf("��Υ���ˣ���ȡ�Ļ����������!\n\n");
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
        printf("\t\t\t\t\t����ȡ����:%d �� \n", computer);
        if( spare==0 )
        {
            printf("\nPeople win! Game Over!\n");
            break;
        }
    }
    return;
}
