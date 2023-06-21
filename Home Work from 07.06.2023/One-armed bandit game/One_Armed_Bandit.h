#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iomanip> 
#include <string>
#include <MMSystem.h>
#pragma comment (lib, "winmm")
using namespace std;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

class Queue;

class Game_Drum
{
    string c;
    static int balance;
public:
    friend Queue;
    Game_Drum();
    Game_Drum(string c);
    ~Game_Drum() {  }
    friend ostream& operator << (ostream& os, Game_Drum& t);
    friend void Add_Drum_to_Queue(Queue& q, Game_Drum& drum);
    friend void Show_Balance();
    friend bool Check_Balance();
    friend void Add_Balance(int cash);
    friend void Accrual_of_Win(Queue& q1, Queue& q2, Queue& q3);


};

class Queue
{
    char* Wait;// smart pointer on queue
    int Leng; // current size queue
    int MaxLeng; // Max size queue
public:
    friend Game_Drum;
    Queue(Game_Drum& drum);
    ~Queue();
    void Add(char c);
    bool IsFull();
    int Extract();
    bool IsEmpty();
    void Clear();
    void Show();
    int GetCount(); // контроль кол-ва элементов в очереди
    friend ostream& operator << (ostream& os, Queue& q);
    friend int Check_Win(Queue& q1, Queue& q2, Queue& q3);
    friend void Scrolling_Drum(Queue& q1, Queue& q2, Queue& q3, Game_Drum drum);
};

void func_Menu();
void Running_Line();
void SetColor(int text, int background);
void GotoXY(int X, int Y);
