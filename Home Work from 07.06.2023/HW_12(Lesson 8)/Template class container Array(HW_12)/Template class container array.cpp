#include <iostream>

using namespace std;

template<typename T>
class Array
{
	T* data;
	int size;
	int capacity;
	int grow;
	int count;
public:
	Array();
	Array(int set_size, int grow = 1);
	~Array();
	int GetSize();
	void SetSize(int _size, int _grow = 1);
	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra();
	void removeAll();
	const T& GetAt(int index);
	void SetAt(int index, const T& value);
	void operator []( int index);
	void Add(const T& value);
	void Append(Array<T>& obj);
	void operator = (const Array<T>& obj);
	T* GetData();
	void InsertAt(int index, const T& value);
	void RemoveAt(int index);
	void Print();
};

int main()
{
	Array<int> int_arr;
	int_arr.SetSize(5, 5);
	for (int i = 0; i < 5; i++)
	{
		int_arr.Add(i * i);
	}
	int_arr.Print();
	cout << "\n===========================\n";
	int_arr[3];
	int_arr.SetAt(4, 34);
	int_arr.Print();
	cout << "\n=============================\n";
	int_arr.Add(23);
	int_arr.Add(77);
	int_arr.Add(89);
	int_arr.Add(42);
	int_arr.Add(56);
	int_arr.Add(54);
	int_arr.Add(58);
	int_arr.Print();
	cout << "\n===============================\n";
	cout << "Is intArray empty? " << (int_arr.IsEmpty() ? "Yes" : "No") << endl;
	Array<int> int2_arr(5, 5);
	for (int i = 0; i < 5; i++)
	{
		int2_arr.Add(i * 5);
	}
	int_arr.Append(int2_arr);
	int_arr.Print();
	cout << "\n===================================\n";
	int_arr = int2_arr;
	int_arr.Print();
	cout << "\n===================================\n";
	cout << "Address int_arr : " << int_arr.GetData() << endl;
	int_arr.InsertAt(3, 134);
	int_arr.Print();
}

template<typename T>
Array<T>::Array()
{
	data = nullptr;
	size = 0;
	capacity = 0;
	count = 0;
	grow = 1;
}

template<typename T>
Array<T>::Array(int set_size, int grow)
{
	SetSize(set_size);
}

template<typename T>
Array<T>::~Array()
{
	delete[] data;
	data = nullptr;
}

template<typename T>
int Array<T>::GetSize()
{
	return size;
}

template<typename T>
void Array<T>::SetSize(int _size, int _grow)
{
	if (_size <= capacity) {
		size = _size;
	}
	else {
		int _capacity = _size + (_grow - (_size % _grow));
		T* _data = new T[_capacity];
		if (data) {
			for (int i = 0; i < size; i++) {
				_data[i] = data[i];
			}
			delete[] data;
		}
		data = _data;
		size = _size;
		capacity = _capacity;
	}
}

template<typename T>
int Array<T>::GetUpperBound()
{
	if (size > 0) return size - 1;
	else return 0;
}

template<typename T>
bool Array<T>::IsEmpty()
{
	return size == 0;
}

template<typename T>
void Array<T>::FreeExtra()
{
	if (size < capacity) {
		T* _data = new T[size];
		for (int i = 0; i < size; i++) {
			_data[i] = data[i];
		}
		delete[] data;
		data = _data;
		capacity = size;
		count = 0;
	}
}

template<typename T>
void Array<T>::removeAll()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
	count = 0;
}

template<typename T>
const T& Array<T>::GetAt(int index)
{
	if (index >= 0 && index <= size) {
		return data[index];
	}
	else cout << "Error.Invalid index\n";
}

template<typename T>
void Array<T>::SetAt(int index, const T& value)
{
	if (index >= 0 && index <= size) {
		data[index] = value;
	}
	else cout << "Error.Invalid index\n";
}

template<typename T>
void Array<T>::operator [](int index)
{
	if (GetAt(index))
	{
		cout << "Current value for index = " << this->GetAt(index) << endl;;
	}
	cout << "If you want to change the value for this index, enter 1 , enter 2 to cancel.";
	char choise{};
	cout << "Select an action : "; cin >> choise;
	while (choise != '1' && choise != '2')
	{
		cout << "Error input\n" <<
			"Try select an action again : ";
		cin >> choise;
	}
	if (choise == '1')
	{
		T value{};
		cout << "Enter to new value : ";
		cin >> value;
		this->SetAt(index, value);
	}
	else return;
}

template<typename T>
void Array<T>::Add(const T& value)
{
	if (size == capacity) {
		SetSize(size + grow);
	}
	data[count] = value;
	count++;
	if (count == size) size++;
}

template<typename T>
void Array<T>::Append(Array<T>& obj)
{
	if (!obj.IsEmpty())
	{
		int _size = size + obj.size;
		count += obj.count;
		if (_size > capacity) {
			int _capacity = _size + (grow - (_size % grow));
			T* _data = new T[_capacity];
			for (int i = 0; i < size; i++) {
				_data[i] = data[i];
			}
			delete[] data;
			data = _data;
			capacity = _capacity;
		}
		for (int i = 0; i <= obj.size-1; i++) {
			data[size - 1 + i] = obj.data[i];
		}
		size = _size;
	}
	else cout << "Error. Array is empty\n";
}

template<typename T>
void Array<T>::operator=(const Array<T>& obj)
{
	if (this != &obj) {
		delete[] data;
		size = obj.size;
		capacity = obj.capacity;
		count = obj.count;
		data = new T[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = obj.data[i];
		}
	}
}

template<typename T>
T* Array<T>::GetData()
{
	return data;
}

template<typename T>
void Array<T>::InsertAt(int index, const T& value)
{
	if (index >= 0 && index <= size) {
		if (size == capacity) {
			SetSize(size + grow);
		}
		for (int i = size; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}
	else cout << "Error.Invalid index\n";
}

template<typename T>
void Array<T>::RemoveAt(int index)
{
	if (index >= 0 && index < size) {
		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}
	else cout << "Error.Invalid index\n";
}

template<typename T>
void Array<T>::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i] << ' ';
	}
	cout << endl;
}
