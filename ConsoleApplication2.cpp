// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <windows.h>
#include <conio.h>
#include<string>
using namespace std;
#define   VK_A	0x41 
#define   VK_B	0x42 
#define   VK_C	0x43 
#define   VK_D	0x44 
#define   VK_E	0x45 
#define   VK_F	0x46 
#define   VK_G	0x47 
#define   VK_H	0x48 
#define   VK_I	0x49 
#define   VK_J	0x4A 
#define   VK_K	0x4B 
#define   VK_L	0x4C 
#define   VK_M	0x4D 
#define   VK_N	0x4E 
#define   VK_O	0x4F 
#define   VK_P	0x50 
#define   VK_Q	0x51 
#define   VK_R	0x52 
#define   VK_S	0x53 
#define   VK_T	0x54 
#define   VK_U	0x55 
#define   VK_V	0x56 
#define   VK_W	0x57 
#define   VK_X	0x58 
#define   VK_Y	0x59 
#define   VK_Z	0x5A 
#define KEY_DOWN(vKey) ((GetAsyncKeyState(vKey) & 0x8000) ? 1:0)





void down(int vk)
{
    keybd_event(vk, 0, 0, 0);
}
void up(int vk)
{
    keybd_event(vk, 0, KEYEVENTF_KEYUP, 0);
}
void press(int vk)
{
    down(vk);
    up(vk);
}


void ctrl_v()
{
    down(VK_CONTROL);//按下Ctrl键
    press(VK_V);//按下V键，并放开
    up(VK_CONTROL);//放开ctrl键
}

void alts()
{
    down(VK_MENU);//按下alt键
    press(VK_S);//按下s键，并放开
    up(VK_MENU);//放开alt键
}
int main()
{
    cout << "先复制一段话，再打开聊天框，运行程序，即可轰炸"<<endl;
    while (true) {
        cout << "本程序仅供学习使用！" << endl << "按esc键结束,多按几下" << endl << "请输入轰炸次数：";
        int n = 0;
        cin >> n;
        cout << "输入每次轰炸间隔时间，单位ms：";
        int m;
        cin >> m;
        cout << "1s后开始轰炸！" << endl;
        Sleep(1000);
        int a = 0;
        while (!KEY_DOWN(27)&&n>0)
        {

            
            a = a + 1;
            ctrl_v();
            
            alts();
            cout << "已经轰炸"<<a<<"次数"<<endl;
            Sleep(m);
            n = n - 1;


        }
        cout << "轰炸手动结束！" << endl;

    }

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
