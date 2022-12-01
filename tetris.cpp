#include <iostream>
#include <windows.h>
#include "Klocki.h"
#include "functions.h"
#include <cstdlib>
#include "tests.h"
#include "ScreenFunc.h"
using namespace std;


TStudnia s = {
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
    {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},

};

int main()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
    srand(time(NULL));
    Klocki klocek1("klocek1.txt");
    Klocki klocek2("klocek2.txt");
    Klocki klocek3("klocek3.txt");
    Klocki klocek4("klocek4.txt");
    Klocki klocek5("klocek5.txt");
    Klocki klocek6("klocek6.txt");
    int punkty = 0;
    EnterScreen();
    menu();
    wyswietl(s, punkty);
    int los1;
    int los2 = rand() % 6 + 1;
    while (true) {
        int row = 0, col = 7;
        int los1 = los2;
        los2 = rand() % 6 + 1;
        ShowNextK(los2 , out);
        switch (los1) {
        case 1: start(s, row, col, klocek1, punkty); break;
        case 2: start(s, row, col, klocek2, punkty); break;
        case 3: start(s, row, col, klocek3, punkty); break;
        case 4: start(s, row, col, klocek4, punkty); break;
        case 5: start(s, row, col, klocek5, punkty); break;
        case 6: start(s, row, col, klocek6, punkty); break;
        }
        Sleep(400);
        wyswietl(s, punkty);
    }
}


