#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip> 
#include <string>

using namespace std;

template <typename T>
struct Elem
{
	T data;
	Elem* next;
};
template <typename T>
class List_1X
{
	Elem<T>* Head, * Tail;
	int count;
public:
	List_1X();
	~List_1X();
	void Add(T data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
	void insert(T val, int pos);
	void remove(int pos);
    int search(T key);
};

template<typename T>
List_1X<T>::List_1X()
{
	Head = Tail = 0;
	count = 0;
}

template<typename T>
List_1X<T>::~List_1X()
{
	DelAll();
}

template<typename T>
void List_1X<T>::Add(T data)
{
	Elem<T>* temp = new Elem<T>;
	temp->data = data;
	temp->next = nullptr;
	if (Head != nullptr) {
		Tail->next = temp;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
	count++;
}

template<typename T>
void List_1X<T>::Del()
{
	Elem<T>* temp = Head;
	Head = Head->next;
	delete temp;
	count--;
}

template<typename T>
void List_1X<T>::DelAll()
{
	while (Head != 0)
		Del();
}

template<typename T>
void List_1X<T>::Print()
{
	Elem<T>* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n\n";
}

template<typename T>
int List_1X<T>::GetCount()
{
	return count;
}

template<typename T>
inline void List_1X<T>::insert(T val, int pos)
{
	if (pos < 0 ||
		pos > this->GetCount()) cout << "Error\n";
	Elem<T>* tmp = new Elem<T>;
	tmp->data = val;
	tmp->next = nullptr;

	if (!pos) {
		tmp->next = this->Head;
		this->Head = tmp;
	}
	else {
		Elem<T>* new_value = this->Head;
		int i = 0;
		while (i < pos - 1)
		{
			new_value = new_value->next;
			++i;
		}
		tmp->next = new_value->next;
		new_value->next = tmp;
	}
}

template<typename T>
inline void List_1X<T>::remove(int pos)
{
	if (!this->Head || pos < 0 ||
		pos > this->GetCount()) cout << "Error\n";
	else if (!pos)
	{
		this->Head = this->Head->next;
	}
	else
	{
		int i = 0;
		Elem<T>* tmp = this->Head;
		while (i < pos - 1)
		{
			tmp = tmp->next;
			++i;
		}
		tmp->next = tmp->next->next;
	}
}

template<typename T>
inline int List_1X<T>::search(T key)
{
	if (this->Head != nullptr) {
		Elem <T>* tmp = this->Head;
		int pos = 0;
		while (tmp != nullptr) {
			if (tmp->data == key) {
				return pos;
			}
			tmp = tmp->next;
			pos++;
		}
	}
	return NULL;
}