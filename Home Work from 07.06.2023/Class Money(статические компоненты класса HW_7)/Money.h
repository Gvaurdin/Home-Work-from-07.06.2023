
#include <iomanip> 
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

class Money
{
private:
    int rub, kop;
    static int C_USD_Dollar;
    static int C_USD_Cent;
    static int count;
    static int count_money;
public:
    Money();
    Money(int _rub, int _kop);
    void Set_Money(int _rub, int _kop);
    friend ostream& operator << (ostream& os, Money& m);
    friend istream& operator >> (istream& is, Money& m);
    void Convert_Kopecks();
    Money Addition(int _rub, int _kop);
    Money operator +(const Money& money);
    Money operator -(const Money& money);
    Money Percent(int percent);
    Money operator ++();
    static void convert_to_USD(Money& money);
    void show_info(Money& m);
};

