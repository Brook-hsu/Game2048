#include <stdio.h>
#include <stdlib.h>

///ɨ����Ϸģ�飬��MineSweep()�൱��Դ�ļ���main()����������������Ϸ����
///Ϊ��ֹ��2048��ͻ�����ﺯ������ͳһ��ǰ׺  m_  ��������������
///��Ϸ˼·��
///1.��10��10�����������ʮ����
///2.��һ��С�ˣ�����û���׵ĵط�Ϲ��
///3.���ܱ������ֱ���
///4.ʤ��������С�˰�����ȷ������߹��������׵���
///����������

short loc[11][11];///���ױ�1�����ױ�0

void m_Print();
void m_Initial();///�����������initial������
void m_Control();
    void m_Turn_left();
    void m_Turn_right();
    void m_Turn_up();
    void m_Turn_down();
void m_Is_over();

void MineSweep(){
    Initial();


}
