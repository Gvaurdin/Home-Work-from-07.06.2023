#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};


class Point
{
    int x;
    int y;
public:
    static string color;
    static int i_color;
    Point() { x = y  = 0; }
    void SetP(int x, int y);
    friend ostream& operator << (ostream& os, Point& p);
    friend void Set_User_Color(int color);
};

class Figure
{
    Point* obj;
    int count;
public:
    Figure() { count = 0; obj = nullptr;}
    Figure(int count,int color);
    friend ostream& operator << (ostream& os, Figure& p);
    friend istream& operator >> (istream& is, Figure& p);
    friend void Create_User_Figure(Figure& p);
    ~Figure();
};

void SetColor(int text, int background);
void GotoXY(int X, int Y);
double RootNumber(int n, int i);
void func_menu();