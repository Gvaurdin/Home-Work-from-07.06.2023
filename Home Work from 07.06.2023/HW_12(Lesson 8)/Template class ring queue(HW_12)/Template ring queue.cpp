#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;


template <typename T> class Queue
{
	T* Wait;
	int Leng;
	int MaxLeng;
public:
	Queue(int m);
	~Queue();
	void Add(T n);
	bool IsFull();
	int Extract();
	bool IsEmpty();
	void Clear();
	void Show();
	int GetCount();
};

int main()
{
	cout << "\n===========Queue type int=============\n";
	Queue <int> q_int(10);
	for (int i = 0; i < 4; i++)
	{
		q_int.Add(rand() % 40 + 1 + rand() % 100 / 100.0);
	}
	q_int.Show();
	cout << "\n=================================\n";
	q_int.Extract();
	q_int.Show();
	cout << "\n=================================\n";
	q_int.Extract();
	q_int.Show();
	cout << "\n=================================\n";
	q_int.Extract();
	q_int.Show();
	cout << "\n===========Queue type float=============\n";

	Queue <float> q_float(10);
	for (int i = 0; i < 4; i++)
	{
		q_float.Add(rand() % 40 + 20 + rand() % 100 / 100.0);
	}
	q_float.Show();
	cout << "\n=================================\n";
	q_float.Extract();
	q_float.Show();
	cout << "\n=================================\n";
	q_float.Extract();
	q_float.Show();
	cout << "\n=================================\n";
	q_float.Extract();
	q_float.Show();

	cout << "\n===========Queue type char=============\n";

	Queue <char> q_char(10);
	for (int i = 0; i < 4; i++)
	{
		q_char.Add(rand() % 40 + 20 + rand() % 100 / 100.0);
	}
	q_char.Show();
	cout << "\n=================================\n";
	q_char.Extract();
	q_char.Show();
	cout << "\n=================================\n";
	q_char.Extract();
	q_char.Show();
	cout << "\n=================================\n";
	q_char.Extract();
	q_char.Show();
}

template<typename T>
Queue<T>::Queue(int m)
{
	MaxLeng = m;
	Wait = new T[MaxLeng];
	Leng = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[]Wait;
}

template<typename T>
void Queue<T>::Add(T n)
{
	Wait[Leng++] = n;
}

template<typename T>
bool Queue<T>::IsFull()
{
	return Leng == MaxLeng;
}

template<typename T>
int Queue<T>::Extract()
{
	if (!IsEmpty())
	{
		T tmp = Wait[0];
		for (int i = 1; i < Leng; ++i)
		{
			Wait[i - 1] = Wait[i];
		}
		Wait[Leng - 1] = tmp;
		return 1;
	}
	else return -1;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	return Leng == 0;
}

template<typename T>
void Queue<T>::Clear()
{
	Leng = 0;
}

template<typename T>
void Queue<T>::Show()
{
	for (int i = 0; i < Leng; ++i)
	{
		cout << Wait[i] << ' ';
	}
	cout << endl;
}

template<typename T>
int Queue<T>::GetCount()
{
	return Leng;
}
