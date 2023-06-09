#include "Money.h"

int main()
{
    srand(time(NULL));
    Money money, money_2(0,0); char menu{};
    Money mas_money[3];
    int rub{}, kop{}, percent{};
    bool flag = false;
    while (flag == false)
    {
        system("cls");
        cout << "\t\t\t\tMoney editor\n" <<
            "\t\t\Enter P(p) to show your balance\n" <<
            "\t\t\Enter D(d) to show additional balances accounts\n" <<
            "\t\t\Enter sign (+) to add money to your balance\n" <<
            "\t\tEnter sign (-) to deduct money from your balance\n" <<
            "\t\tEnter the (%) sign to see the percentage of your money on the balance\n" <<
            "\t\tEnter A(a) to add 1 unit to your amount of rubles and kopecks on the balance\n" <<
            "\t\tEnter E(e) to exit the editor\n\n" <<
            "\t\t\tEnter a command to select an action : ";
        cin >> menu;
        switch (menu)
        {
        case 'P':
        case 'p':
            system("cls");
            cout << money;
            money.show_info(money);
            system("pause");
            break;
        case 'D':
        case 'd':
            system("cls");
            cout << "Additional balances accounts\n";
            for (int i = 0; i < 3; ++i)
            {
                cout << i + 1 << ' ' << mas_money[i];
            }
            system("pause");
            break;
        case '+':
            cout << "\t\tEnter the amount of money you want to add to your balance\n" <<
                "\tThe limit of rubles to add = 100000\n" <<
                "\tThe limit of kopecks to add = 99\n";
            cin >> money_2;
            money + money_2;
            cout << "\t\t\tMoney successfully added\n";
            system("pause");
            break;
        case '-':
            system("cls");
            cout << money;;
            cout << "\tImportant! The money you want to withdraw" <<
                " must not exceed the amount of your balance\n" <<
                "\tThe limit of rubles to withdraw = 100000\n" <<
                "\tThe limit of kopecks to withdraw = 99\n";
            cin >> money_2;
            money - money_2;
            cout << "\t\t\tMoney successfully withdrawn\n";
            system("pause");
            break;
        case '%':
            cout << "Specify the percentage to be calculated" <<
                " from the amount of money on your balance\n" <<
                "Percent : "; cin >> percent;
            while (percent < 1 || percent > 100)
            {
                cout << "Error. Try again\n" <<
                    "Percent : "; cin >> percent;
            }
            money_2 = money.Percent(percent);
            cout << percent << " percent of the amount of money on your balance = ";
            cout << money_2;
            system("pause");
            break;
        case 'A':
        case 'a':
            system("cls");
            ++money;
            cout << "1 unit has been successfully added" <<
                " to the amount of rubles and kopecks on your balance\n";
            system("pause");
            break;
        case 'E':
        case'e':
            cout << "\t\tThe program exits\n";
            system("pause");
            flag = true;
            break;
        default:
            cout << "\t\tMistake. Wrong command\n";
            system("pause");
            break;
        }
    }
}