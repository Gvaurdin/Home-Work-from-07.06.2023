#include "List_2X.h"

int main()
{
	List_2X <int> L;
	const int n = 10;
	int b[n] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			L.AddHead(b[i]);
		else
			L.AddTail(b[i]);
	cout << "List_2X L:\n";
	L.Print_X2();
	cout << endl;
	L.Insert_X2();
	cout << "List_2X L:\n"; L.Print_X2();
	L.Print(2);
	L.Print(8);
	List_2X <int> T;
	T = L;
	cout << "List_2X T:\n";
	T.Print_X2();
	cout << "List_2X Sum:\n";
	List_2X <int> Sum = -L + T;
	Sum.Print_X2();
}