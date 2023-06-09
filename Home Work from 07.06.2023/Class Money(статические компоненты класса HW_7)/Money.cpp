#include "Money.h"

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

void Money::convert_to_USD(Money& money)
{
    float total_RUB = (float)money.rub + (money.kop / 100);
    float total_USD = (float)C_USD_Dollar + (C_USD_Cent / 100);
    float RUB_USD = total_RUB / total_USD;
    cout << "The amount of your ruble money balance is equal to " <<
        (int)RUB_USD << " dollars. " << (int)RUB_USD % 100 << " cents.\n";
}

void Money::show_info(Money& m)
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
        cout << "\n=============================================\n" <<
            "Ruble to dollar exchange rate : " << Money::C_USD_Dollar <<
            " rubles. " << Money::C_USD_Cent << " kopecks.\n";
        m.convert_to_USD(m);
        cout << "\n=============================================\n" <<
            "The number of successfully completed operations during the current session :" <<
            Money::count << endl << "The number of accounts created (the system account doesn`t count) : " <<
            Money::count_money << endl;
    }


}



ostream& operator<<(ostream& os, Money& m)
{
    cout << Money::currency << endl <<
        m.rub << " rubles. " << m.kop << " kopecks.\n" <<
        "\n=========================\n";

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

int Money::C_USD_Dollar = 82;
int Money::C_USD_Cent = 60;
int Money::count = 0;
int Money :: count_money = 0;
string Money::currency = "Ruble account";


