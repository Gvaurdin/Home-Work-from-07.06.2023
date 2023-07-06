#include "List_1X.h"

int main()
{
	List_1X <char> l;
	const int n = 10;
	char a[n] = { "elloo"};
	//Добавляем элементы, стоящие на четных 
	//индексах, в голову, на нечетных - в хвост
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			l.Add(a[i]);
		else
			l.Add(a[i]);
	//Распечатка списка
	cout << "List_2X L:\n";
	l.Print();
	cout << l.GetCount();
	cout << "\n\n";
	l.insert('H', 0);
	l.remove(5);
	l.Print();
	int c = l.search('o');
	cout << c;
}