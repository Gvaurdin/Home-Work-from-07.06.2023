#include "Time.h"


int main()
{
    Time t, t2;
    char menu{};
    bool flag = false;
    while (flag == false)
    {
        system("cls");
        cout << "\t\t\t\tTimer and Stopwatch\n" <<
            "\t\t\Enter P(p) to show your set time\n" <<
            "\t\tEnter H(h) to turn on the stopwatch\n" <<
            "\t\tEnter A(a) to turn on the timer\n" <<
            "\t\tEnter D(d) to set the time\n" <<
            "\t\tEnter E(e) to exit the editor\n\n" <<
            "\t\t\tEnter a command to select an action : ";
        cin >> menu;
        switch (menu)
        {
        case 'P':
        case 'p':
            system("cls");
            cout << "\n\n\t\tYour set time : " << t;
            system("pause");
            break;
        case 'H':
        case 'h':
            system("cls");
            StopWatch(t2);
            cout << "Stopwatch OFF\n";
            system("pause");
            break;
        case 'A':
        case 'a':
            system("cls");
            Timer(t2);
            system("pause");
            break;
        case 'D':
        case 'd':
            system("cls");
            cout << "\n\tSet the time\n";
            cin >> t;
            cout << "Time successfully set\n";
            system("pause");
            break;
        case 'E':
        case 'e':
            system("cls");
            cout << "\t\tThe program exits\n";
            flag = true;
            break;
        default:
            cout << "\t\tMistake. Wrong command\n";
            system("pause");
            break;
        }
    }
}