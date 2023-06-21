#include "One_Armed_Bandit.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iomanip> 
#include <string>
#include <MMSystem.h>
#pragma comment (lib, "winmm")

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
    HANDLE hConsole;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

Queue::Queue(Game_Drum& drum)
{
    MaxLeng = drum.c.length() * 2;
    Wait = new char[MaxLeng];
    Leng = 0;
}

Queue::~Queue()
{
    delete[]Wait;
}

void Queue::Add(char c)
{
    if (!IsFull())
    {
        Wait[Leng++] = c;
    }
}

bool Queue::IsFull()
{
    return Leng == MaxLeng;
}

int Queue::Extract()
{
    if (!IsEmpty())
    {
        char tmp = Wait[0];
        for (int i = 1; i < Leng; ++i)
        {
            Wait[i - 1] = Wait[i];
        }
        //Leng--; при обычной очереди ( фифо) первый элемент излекается а остальные сдвигаются вправо к нулевому
        Wait[Leng - 1] = tmp; // при кольцевой очереди 1 элемент становится последним а все другие сдвигаеются вправо к нулевому

        //return tmp; 
        return 1;
    }
    else return -1; // - нет элементов в очереди для извлечения
}

bool Queue::IsEmpty()
{
    return Leng == 0;
}

void Queue::Clear()
{
    Leng = 0;
}

void Queue::Show()
{
    for (int i = 0; i < Leng; ++i)
    {
        cout << Wait[i];
    }
    cout << endl;

}

int Queue::GetCount()
{

    return Leng;
}

int Game_Drum::balance = 100;

Game_Drum::Game_Drum()
{
    c = "$$$XXX%%%KKK";
}

Game_Drum::Game_Drum(string c)
{
    this->c = c;
}


ostream& operator<<(ostream& os, Game_Drum& drum)
{
    cout << drum;
    return os;
}

void Add_Drum_to_Queue(Queue& q, Game_Drum& drum)
{
    for (int i = 0; i < drum.c.length() * 2; ++i)
    {
        int tmp = rand() % drum.c.length();
        q.Add(drum.c[tmp]);
    }
}


ostream& operator <<(ostream& os, Queue& q)
{
    cout << q.Wait[0];
    return os;
}

void Show_Balance()
{
    GotoXY(0, 10);
    cout << "Your balance : " << Game_Drum::balance << endl;
}

bool Check_Balance()
{
    if (Game_Drum::balance < 0)
    {
        system("cls");
        GotoXY(35, 10);
        cout << "Your balance is empty. Add to balance!!!!\n";
        return true;
    }
    else return false;
}

void Add_Balance(int cash)
{
    if (cash == 0)
    {
        int tmp = 12;
        GotoXY(30, 9);
        cout << "You can only add a round sum. Minimum $100, maximum $1000\n";
        GotoXY(35, 10);
        cout << "Enter the amount you want to add : ";
        cin >> cash;
        while (cash < 100 || cash > 1000 || cash % 10 != 0)
        {
            GotoXY(35, tmp);
            cout << "Error!!! Try again : ";
            ++tmp;
            cin >> cash;
        }

    }
    else if (cash < 100 || cash > 1000)
    {
        GotoXY(35, 10);
        cout << "Error when adding funds to the balance\n";
    }
    system("cls");
    GotoXY(35, 10);
    cout << "Money has been successfully added!!!\n";
    Game_Drum::balance += cash;

}

void Accrual_of_Win(Queue& q1, Queue& q2, Queue& q3)
{
    if (Check_Win(q1, q2, q3) == 1)
    {
        PlaySound(TEXT("PWWAW.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GotoXY(35, 13);
        cout << "Jackpot!!!!!!!!!!!!!!!!! You have earned $50!!!!\n";
        Game_Drum::balance += 50;
    }
    else if (Check_Win(q1, q2, q3) == 2)
    {
        PlaySound(TEXT("VSWAW.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GotoXY(35, 13);
        cout << "You have earned $10!!!!\n";
        Game_Drum::balance += 10;
    }
    else
    {
        PlaySound(TEXT("PLWWAW.wav"), NULL, SND_FILENAME | SND_ASYNC);
        GotoXY(35, 13);
        cout << "You lose!!!!!!!!!!!!!\n";
        Game_Drum::balance -= 20;
    }
}

void Scrolling_Drum(Queue& q1, Queue& q2, Queue& q3, Game_Drum drum)
{
    int i = 0; short random = 0; char action{};
    while (action != 27)
    {
        if (Check_Balance() == true)
        {
            system("pause");
            break;
        }
        PlaySound(TEXT("CDWAW.wav"), NULL, SND_FILENAME | SND_ASYNC);
        while (i < 12)
        {
            system("cls");
            if (i <= 4)
            {
                SetColor(rand() % 7, 7);
                GotoXY(5, 5);
                cout << q1;
                q1.Extract();
            }
            else
            {
                GotoXY(5, 5);
                cout << "[" << q1 << "]";
            }
            if (i <= 8)
            {
                SetColor(rand() % 7, 7);
                GotoXY(10, 5);
                cout << q2;
                q2.Extract();
            }
            else
            {
                GotoXY(10, 5);
                cout << "[" << q2 << "]";
            }
            if (i < 11)
            {
                SetColor(rand() % 7, 7);
                GotoXY(15, 5);
                cout << q3;
                q3.Extract();
            }
            else
            {
                GotoXY(15, 5);
                cout << "[" << q3 << "]";
            }
            SetColor(0, 7);
            Show_Balance();
            ++i;
            Sleep(500);
        }
        i = 0;
        random = rand() % 2 + 1;
        Accrual_of_Win(q1, q2, q3);
        GotoXY(20, 15);
        cout << "Press the backspace key to open the current game\n";
        GotoXY(20, 16);
        cout << "Press the enter key to continue spinning the drum\n";
        action = _getch();
        if (action == 13) {
            system("cls");
            GotoXY(5, 15);
            cout << "Continue....\n";
            Sleep(200);
        }
        else if (action != 27 && action != 13)
        {
            system("cls");
            GotoXY(5, 15);
            cout << "Error!!!!!\n";
            break;
        }
        if (random == 1) Add_Drum_to_Queue(q1, drum);
        else if (random == 2) Add_Drum_to_Queue(q2, drum);
        else Add_Drum_to_Queue(q3, drum);

    }
}

void Running_Line()
{
    system("color 71");
    SetColor(1, 7);
    const int WINDOW = 50;//размер ограниченного окошка
    char run_line[] = { "<<<< Hello people! Welcome to game ONE-ARMED BANDIT >>>>" };
    int text_pointer = 0, empty = WINDOW;//позиция в тексте, ширина пустого пространства
    for (int i = 0; i < 100; ++i)//общий цикл для повторения программы
    {
        system("cls");//очистка экрана пред новым кадром
        cout << '\t';
        //выводит ограниченное окном кол-во символов. Сперва идут пропуски, затем текст
        //образуя "бегущую" строку
        for (int display = 0; display <= WINDOW;)
        {
            //1часть - пустая строка
            for (int i = empty; i >= 0; i--, display++)
                cout << " ";
            empty--;// уменьшение пробелов для следующего кадра
            if (display > WINDOW) continue;
            //2 часть - текст
            for (int j = text_pointer; display <= WINDOW; display++)
            {
                //как только встречается в массиве строк спецсимвол - до конца цикла печатает пустые символы
                if (run_line[j] == '\0')
                    cout << " ";
                else
                    cout << run_line[j++];

            }
            //изменяем переменную только тогда, когда закончили печатать пустые строки
            //для того, чтобы строка в массиве печаталась на экране со сдвигом - нгачинаем изменять указатель на букву
            if (empty < 0)
                text_pointer++;
        }
        GotoXY(20, 5);
        cout << "Loading...........";
        //по завершению цикла, обнуляем параметры, чтобы строчка наала выводиться заново
        if (run_line[text_pointer] == '\0')
        {
            text_pointer = 0;
            empty = WINDOW;
        }
        Sleep(80);

    }
    system("cls");
}

void func_Menu()
{
    PlaySound(TEXT("PFWAW.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Running_Line();
    bool flag = true; char num = 0;
    Game_Drum symbols_drum;
    Queue drum1(symbols_drum), drum2(symbols_drum), drum3(symbols_drum);
    Add_Drum_to_Queue(drum1, symbols_drum);
    Add_Drum_to_Queue(drum2, symbols_drum);
    Add_Drum_to_Queue(drum3, symbols_drum);
    do
    {
        system("cls");
        cout << setw(20) << "Game Menu\n" <<
            setw(10) << "Enter 1 -  to start the game\n" <<
            setw(10) << "Enter 2 - show balance \n" <<
            setw(10) << "Enter 3 - add balance \n" <<
            setw(10) << "Enter 4 - exit the game\n" <<
            setw(15) << "Enter to command : ";
        cin >> num;
        while (num != '1' && num != '2' && num != '3' && num != '4')
        {
            cout << setw(15) << "Error\n" <<
                setw(15) << "Try again : ";
            cin >> num;
        }
        switch (num)
        {
        case '1':
        {
            system("cls");
            system("color 70");
            Scrolling_Drum(drum1, drum2, drum3, symbols_drum);
        }
        break;
        case '2':
        {
            system("cls");
            Show_Balance();
            Sleep(1000);
        }
        break;
        case '3':
        {
            system("cls");
            Add_Balance(0);
            Sleep(1000);
        }
        break;
        case '4':
        {
            system("cls");
            cout << "\t\tThe program exits\n";
            system("pause");
            flag = false;
        }
        break;
        default:
            system("cls");
            cout << "Error!!!\n";
            break;
        }
    } while (flag == true);
}




int Check_Win(Queue& q1, Queue& q2, Queue& q3)
{
    if (q1.Wait[0] == q2.Wait[0] && q1.Wait[0] == q3.Wait[0])
    {
        return 1;
    }

    if (q1.Wait[0] == q2.Wait[0] && q1.Wait[0] != q3.Wait[0] ||
        q1.Wait[0] != q2.Wait[0] && q1.Wait[0] == q3.Wait[0] ||
        q2.Wait[0] != q1.Wait[0] && q2.Wait[0] == q3.Wait[0] ||
        q2.Wait[0] == q1.Wait[0] && q2.Wait[0] != q3.Wait[0])
    {
        return 2;
    }

    if (q1.Wait[0] != q2.Wait[0] != q3.Wait[0])
    {
        return 3;
    }
}
