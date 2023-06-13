#include "Money.h"


int Money::count = 0;
int Money::count_money = 0;
int Money::C_USD_Cent = 50;
int Money::C_USD_Dollar = 85;
bool Money::block = false;
Money::Money()
{
    rub = 10000;
    kop = 0;
    count_money++;
}

Money::~Money()
{
    count_money--;
}

Money::Money(int _rub, int _kop)
{
    if (_rub >= 0) rub = _rub;
    else cout << "Error\n";
    if (_kop >= 0) kop = _kop;
    else cout << "Error\n";
}

void Money::Set_Money(int _rub, int _kop)
{
    if (_rub >= 0) rub = _rub;
    else cout << "Error\n";
    if (_kop >= 0 && kop < 100) kop = _kop;
    else cout << "Error\n";
}

void Money::Convert_Kopecks()
{
    if (kop > 99) {
        ++rub;
        kop %= 100;
    }
}


Money Money::Addition(int _rub, int _kop)
{
    if (_rub < 0) cout << "Error\n";
    else
    {
        rub += _rub;
    }
    if (_kop < 0) cout << "Error\n";
    else
    {
        kop += _kop;
    }
    Convert_Kopecks();
    return Money();
}

Money Money::operator +(const Money& money)

{
    rub = rub + money.rub;
    kop = kop + money.kop;
    Convert_Kopecks();
    count++;
    return Money();
}

Money Money::operator - (const Money& money)
{

    if (rub < money.rub) cout << "Error\n";
    else rub = rub - money.rub;
    if (kop < money.kop && rub > 0) {
        --rub;
        kop += 100 - money.kop;
    }
    else if (kop < money.kop && rub == 0) cout << "Error";
    else kop -= money.kop;
    count++;
    return Money();
}

Money Money::Percent(int percent)
{
    Money tmp;
    tmp.rub = rub * (float)percent / 100;
    tmp.kop = kop * (float)percent / 100;
    if (tmp.rub % percent > 0) tmp.kop += rub % percent;
    tmp.Convert_Kopecks();
    count++;
    return tmp;
}

Money Money::operator++()

{
    ++rub, ++kop;
    if (kop > 99) {
        ++rub;
        kop %= 100;
    }
    count++;
    return Money();
}

void Money::Convert_to_USD(Money& money)
{
    float total_RUB = (float)money.rub + (money.kop / 100);
    float total_USD = (float)C_USD_Dollar + (C_USD_Cent / 100);
    float RUB_USD = total_RUB / total_USD;
    cout << "The amount of your ruble money balance is equal to " <<
        (int)RUB_USD << " dollars. " << (int)RUB_USD % 100 << " cents.\n";
}

void Money::Show_Info(Money& m)
{
    char c{};
    cout << "Enter Y(y), if you want to see more information, " <<
        "enter N(n) to finish the operation\n" <<
        "Select an action : ";
    cin >> c;
    while (c != (char)78 && c != (char)110 &&
        c != (char)89 && c != (char)121)
    {
        cout << "Error\n" <<
            "Select an action again :";
        cin >> c;
    }
    if (c == 'N' || c == 'n') cout << "Finish the operation\n";
    else
    {
        if (!Money::block)
        {
            cout << "\n=============================================\n" <<
                "Ruble to dollar exchange rate : " << Money::C_USD_Dollar <<
                " rubles. " << Money::C_USD_Cent << " kopecks.\n";
            m.Convert_to_USD(m);
            cout << "\n=============================================\n" <<
                "The number of successfully completed operations during the current session :" <<
                Money::count << endl << "The number of accounts created (the system account doesn`t count) : " <<
                Money::count_money << endl;
        }
        else cout << "Need to unlock your balance accounts\n";
    }


}

bool Money::Money_Block(bool block)
{
    Money::block = block;
    return Money::block;
}




ostream& operator<<(ostream& os, Money& m)
{
    if (!Money::block)
        cout << m.rub << " rubles. " << m.kop << " kopecks.\n" <<
        "\n=========================\n";
    else cout << "Your balance accounts blocked\n";

    return os;
}

istream& operator>>(istream& is, Money& m)
{
    cout << "\t\tEnter the number of rubles : "; cin >> m.rub;
    cout << "\t\tEnter the number of kopecks : "; cin >> m.kop;
    while (m.rub < 0 || m.rub > 100000 ||
        m.kop < 0 || m.kop > 99)
    {
        cout << "\tInput error. Try again\n";
        cout << "\t\tEnter the number of rubles : "; cin >> m.rub;
        cout << "\t\tEnter the number of kopecks : "; cin >> m.kop;
    }
    return is;
}

void Set_Purchases_Price(double* m, Money money)
{
    char c{};
    cout << "\n\tEnter Y(y), if you want to set the values manually, " <<
        "enter N(n) if you want to set values automatically\n" <<
        "Select an action : ";
    cin >> c;
    while (c != (char)78 && c != (char)110 &&
        c != (char)89 && c != (char)121)
    {
        cout << "Error\n" <<
            "Select an action again :";
        cin >> c;
    }
    if (c == 'N' || c == 'n')
    {
        for (int i = 0; i < 5; ++i)
        {
            money.rub = 1000 + rand() % (100000 - 1000);
            money.kop = 1 + rand() % (99 - 1);
            m[i] += (double)money.rub + ((double)money.kop / 100);
        }
    }
    else
    {
        cout << "\n\tAttention. Maximum of 100,000 rubles for 1 purchase\n";
        for (int i = 0; i < 5; ++i)
        {
            cout << "\n\t\tEnter sum purchases of " << i + 1 << " day\n";
            cin >> money;
            m[i] += (double)money.rub + ((double)money.kop / 100);
        }
    }
}

void Set_Count_Pursh(int* p)
{
    char c{};
    cout << "\n\tEnter Y(y), if you want to set the values manually, " <<
        "enter N(n) if you want to set values automatically\n" <<
        "\n\t\tSelect an action : ";
    cin >> c;
    while (c != (char)78 && c != (char)110 &&
        c != (char)89 && c != (char)121)
    {
        cout << "\n\t\tError\n" <<
            "\n\t\tSelect an action again :";
        cin >> c;
    }
    if (c == 'N' || c == 'n')
    {
        for (int i = 0; i < 7; ++i)
        {
            p[i] = rand() % 11;
        }
    }
    else
    {
        cout << "\n\tAttention. Maximum of 10 purchases for 7 day\n";
        for (int i = 0; i < 7; ++i)
        {
            cout << "\n\t\tEnter count purchases of " << i + 1 << " day : ";
            cin >> p[i];
            while (p[i] < 1 || p[i] > 10)
            {
                cout << "\n\t\tError\n" <<
                    "\n\t\tEnter count purchases again :";
                cin >> p[i];
            }
        }
    }
}

void Calculator_of_Purchases_and_Sum_Count_Purchases(int count, bool typeof, ...)
{
    int count_purchase = 0;
    double d_sum = 0.0;
    va_list arg_ptr;
    va_start(arg_ptr, count);
    va_arg(arg_ptr, bool);
    while (count--)
    {
        if (typeof == true)
        {
            d_sum += va_arg(arg_ptr, double);
        }
        else
        {
            count_purchase += va_arg(arg_ptr, int);
        }
    }
    va_end(arg_ptr);
    if (typeof == true)
    {
        Money m, tmp;
        m.Set_Money((int)d_sum, (int)d_sum % 100);
        cout << "\n\t\tThe amount of purchases in 5 days = " << m << endl;
        tmp = m.Percent(5);
        cout << "\n\t\tCashback from purchases in 5 days = " << tmp << endl;
    }
    else
    {
        cout << "\n\t\tNumber of purchases in 7 days = " << count_purchase << endl;
    }
}