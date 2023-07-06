#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip> 
#include <string>

using namespace std;

template <typename T>
struct Element
{
	T data;
	Element<T>* next, * prev;
};
template <typename T>
class List_2X
{
	Element<T>* Head, * Tail;
	int Count;
public:
	List_2X();
	List_2X(const List_2X& L);
	~List_2X();
	int GetCount();
	Element<T>* GetElem(int pos);
	void DelAll_X2();
	void Del_X2(int pos = 0);
	void Insert_X2(int pos = 0);
	void AddTail(int n);
	void AddHead(int n);
	void Print_X2();
	void Print(int pos);
	List_2X& operator = (const List_2X&);
	List_2X operator + (const List_2X&);
	bool operator == (const List_2X&);
	bool operator != (const List_2X&);
	bool operator <= (const List_2X&);
	bool operator >= (const List_2X&);
	bool operator < (const List_2X&);
	bool operator > (const List_2X&);
	List_2X operator - ();
};


template<typename T>
inline List_2X<T>::List_2X()
{
	Head = Tail = NULL;
	Count = 0;
}

template<typename T>
inline List_2X<T>::List_2X(const List_2X& L)
{
	Head = Tail = NULL;
	Count = 0;
	Element<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

template<typename T>
inline List_2X<T>::~List_2X()
{
	DelAll_X2();
}

template<typename T>
inline int List_2X<T>::GetCount()
{
	return Count;
}

template<typename T>
inline Element<T>* List_2X<T>::GetElem(int pos)
{
	Element<T>* temp = Head;
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return 0;
	}
	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}


template<typename T>
inline void List_2X<T>::AddHead(int n)
{
	Element<T>* temp = new Element<T>;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}

template<typename T>
inline void List_2X<T>::Print_X2()
{
	if (Count != 0)
	{
		Element<T>* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}


template<typename T>
inline void List_2X<T>::AddTail(int n)
{
	Element<T>* temp = new Element<T>;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}


template<typename T>
inline void List_2X<T>::Insert_X2(int pos)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > Count + 1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	if (pos == Count + 1)
	{
		int data;
		cout << "Input new number: ";
		cin >> data;
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		int data;
		cout << "Input new number: ";
		cin >> data;
		AddHead(data);
		return;
	}
	int i = 1;
	Element<T>* Ins = Head;
	while (i < pos)
	{
		Ins = Ins->next;
		i++;
	}
	Element<T>* PrevIns = Ins->prev;
	Element<T>* temp = new Element<T>;
	cout << "Input new number: ";
	cin >> temp->data;
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	Count++;
}


template<typename T>
inline void List_2X<T>::Print(int pos)
{
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	Element<T>* temp;
	if (pos <= Count / 2)
	{
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = Tail;
		int i = 1;
		while (i <= Count - pos)
		{
			temp = temp->prev;
			i++;
		}
	}
	cout << pos << " Printer_Programm: ";
	cout << temp->data << endl;
}

template<typename T>
inline List_2X<T>& List_2X<T>::operator = (const List_2X<T>& L)
{
	if (this == &L)
		return *this;
	this->~List_2X(); // DelAll();
	Element<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

template<typename T>
inline List_2X<T> List_2X<T>::operator + (const List_2X<T>& L)
{
	List_2X Result(*this);
	Element<T>* temp = L.Head;
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}
	return Result;
}

template<typename T>
inline bool List_2X<T>::operator==(const List_2X& L)
{
	if (Count != L.Count)
		return false;
	Element<T>* t1, * t2;
	t1 = Head;
	t2 = L.Head;
	while (t1 != 0)
	{
		if (t1->data != t2->data)
			return false;
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}

template<typename T>
inline bool List_2X<T>::operator!=(const List_2X& L)
{
	return !(*this == L);
}

template<typename T>
inline bool List_2X<T>::operator<=(const List_2X& L)
{
	if (Count < L.Count)
		return true;
	if (*this == L)
		return true;
	return false;
}


template<typename T>
inline void List_2X<T>::Del_X2(int pos)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	int i = 1;
	Element<T>* Del = Head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}
	Element<T>* PrevDel = Del->prev;
	Element<T>* AfterDel = Del->next;
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;
	delete Del;
	Count--;
}


template<typename T>
inline void List_2X<T>::DelAll_X2()
{
	while (Count != 0)
		Del_X2(1);
}




template<typename T>
inline bool List_2X<T>::operator>=(const List_2X& L)
{
	if (Count > L.Count)
		return true;
	if (*this == L)
		return true;
	return false;
}

template<typename T>
inline bool List_2X<T>::operator<(const List_2X& L)
{
	if (Count < L.Count)
		return true;
	return false;
}



template<typename T>
inline bool List_2X<T>::operator>(const List_2X& L)
{
	if (Count > L.Count)
		return true;
	return false;
}

template<typename T>
inline List_2X<T> List_2X<T>::operator -()
{
	List_2X Result;
	Element<T>* temp = Head;

	while (temp != 0)
	{
		Result.AddHead(temp->data);
		temp = temp->next;
	}
	return Result;
}

template <typename T>
class Array_T
{
	T* data;
	int size, grow;
public:
	Array_T();
	~Array_T();
	int GetSize();
};

template<typename T>
inline Array_T<T>::Array_T()
{
	data = nullptr;
	size = 0;
	grow = 1;
}

template<typename T>
inline Array_T<T>::~Array_T()
{
	delete[] data;
}

template<typename T>
inline int Array_T<T>::GetSize()
{
	return this->size;
}


