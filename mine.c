#include <stdio.h>
#include <stdlib.h>

///扫雷游戏模块，这MineSweep()相当于源文件的main()函数，控制整个游戏节奏
///为防止与2048冲突，这里函数命名统一加前缀  m_  ，其他函数待想
///游戏思路：
///1.在10×10方阵随机生成十个雷
///2.有一个小人￥，在没有雷的地方瞎逛
///3.雷周边有数字标明
///4.胜利条件：小人把雷正确标完或走过所有无雷地区
///其他待构想

short loc[11][11];///有雷标1，无雷标0

void m_Print();
void m_Initial();///产生随机数在initial里面了
void m_Control();
    void m_Turn_left();
    void m_Turn_right();
    void m_Turn_up();
    void m_Turn_down();
void m_Is_over();

void MineSweep(){
    Initial();


}
