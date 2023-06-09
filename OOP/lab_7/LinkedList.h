#pragma once
#include <iostream>
#include <algorithm>			// ��� min/max
using namespace std;

//-------------------------//
//	num � ����� Point,
//  ���� ����� <Pair>
//-------------------------//
struct Pair
{
	Pair() {}														
	Pair(int a, double b)
	{
		numINT = a;
		numDOUBLE = b;
	}		

	int numINT = 0;
	double numDOUBLE = 0;

	// ��� ���������� ������ Pair ��� ������ ����� ��� ����.
	Pair& operator =(const Pair& pair)
	{
		this->numINT = pair.numINT;
		this->numDOUBLE = pair.numDOUBLE;
		return *this;
	};
	Pair& operator =(const int& k)
	{
		this->numINT = k;
		this->numDOUBLE = k;
		return *this;
	}
	// �����
	friend ostream& operator<<(ostream& out, const Pair& pair)
	{
		out << pair.numINT << " : " << pair.numDOUBLE << " |";
		return out;
	}
	friend istream& operator>>(istream& in, Pair& pair)
	{
		in >> pair.numINT >> pair.numDOUBLE;
		return in;
	}
	// ��������� ���� ��� �����
	Pair operator * (Pair& pair)
	{
		Pair new_pair;
		new_pair.numINT = this->numINT * pair.numINT;
		new_pair.numDOUBLE = this->numDOUBLE * pair.numDOUBLE;
		return new_pair;
	}
};
//-------------------------//
//	����� ������
//-------------------------//
template<typename T>
struct Point
{
	T num;							// int, float, double, Pair
	Point* next = nullptr;			// ��������� �� ��������� ������� ������
};
//-------------------------//
//	�������� ������
//-------------------------//
template <typename T>
class Iterator
{
private:
	Point<T>* elem = nullptr;		// ��������� �� �����
public:
	Iterator() { elem = nullptr; }
	Iterator(Point<T>* point) { elem = point; }
	Iterator(const Iterator& it) { elem = it.elem; };
	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }
	void operator ++ () { elem = elem->next; };			// ++i - �������� ������ �� 1
	void operator ++ (int) { elem = elem->next; };		// i++ - �������� ������ �� 1
	//---------// i+n - �������� ������ �� n
	Iterator& operator + (int n)
	{
		for (int i = 0; i < n && elem->next != nullptr; i++)
			elem = elem->next;
		return *this;
	}
	T operator * () const { return elem->num; };      // ������������� ��������� (�����)
};

//-------------------------//
//	��������� ������
//-------------------------//
template <typename T>
class LinkedList
{
private:
	size_t size = 0;									// ������ ������
	Point<T>* head = nullptr;							// ��������� �� ������ �������
	Point<T>* top = nullptr;							// ��������� �� ���� �������
	//-------------------------------�����----------------------------------------//
	
	void output(Point<T>* obj) const;
	void show() const;
	//---------------------------------------------------------------------------//
public:
	friend ostream& operator<<(ostream& out, const LinkedList<T>& list)
	{
		list.show();
		return out;
	}
	friend istream& operator>>(istream& in, LinkedList<T>& list)
	{
		T k;
		in >> k;
		list.push(k);
		return in;
	}
	LinkedList();										// �����������
	LinkedList(size_t s, T k);							// ����������: s - ������, k - �������� �� ���������
	~LinkedList();										// ����������
	LinkedList(const LinkedList<T>& list);				// ����������� �����������
	T& operator [](int index) const;					// ������ �� �������
	LinkedList& operator =(const LinkedList<T>& list);	// �������� ������������
	LinkedList operator * (LinkedList<T>& list);		// ��������� ������ �� ������
	int operator ()() { return size; };					// ����������� ����� ������
	void push(T k);										// ���������� � ����� ������
	T pop();											// �������� ������� ��������
	Iterator<T> first() { return Iterator<T>(head); }	// ���������� ��������� �� ������ �������
	Iterator<T> last() { return Iterator<T>(top); }		// ���������� ��������� �� ��������� �������

};


// �����������
template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	top = nullptr;
	size = 0;
}
// ����������� � �����������
template <typename T>
LinkedList<T>::LinkedList(size_t s, T k)
{
	size = s;
	if (size != 0) {
		//---------������� ������ � �������� �� �������� k---------//
		Point<T>* obj = new Point<T>;
		obj->num = k;
		head = obj;
		//--------------------------------------------------------//

		//-------������� ��������� size - 1 ��������--------------//
		Point<T>* temp = head;
		for (int i = size - 1; i != 0; i--)
		{
			obj = new Point<T>;
			temp->next = obj;
			obj->num = k;
			temp = obj;
		}
		// ������� + ���������
		top = obj;

	}
}
// ���������� � �����
template <typename T>
void LinkedList<T>::push(T k)
{
	//------------------------------------------//
	//	���� ������ 0, �� ������ ������ = ������
	//------------------------------------------//
	if (size == 0)
	{
		head = new Point<T>;
		head->num = k;
		top = head;

	}
	//------------------------------------------//
	//	����� ����� ����� ��������� ����� �������
	//------------------------------------------//
	else {
		Point<T>* obj = new Point<T>;
		top->next = obj;
		obj->num = k;
		top = obj;
	}
	// ����������� ������, �������� �� �����
	size++;
}
// �������� ���������� ��������
template <typename T>
T LinkedList<T>::pop()
{
	// ������� ������������� �����, ������� ������, ���������� ������
	T k = head->num;
	Point<T>* temp = head;
	head = head->next;
	size--;
	delete temp;
	return k;
}
// ����������
template <typename T>
LinkedList<T>::~LinkedList()
{
	cout << endl << "������ ����������!" << endl << endl;
	while (head != nullptr)
	{
		pop();
	}
}
//----------------------------�����----------------------------------//
template <typename T>
void LinkedList<T>::output(Point<T>* obj) const
{
	cout << obj->num << " ";
	if (obj == top) return;
	output(obj->next);
}
template <typename T>
void LinkedList<T>::show() const
{
	if (size == 0) cout << "������ ����" << endl;
	else output(head);
}
//-------------------------------------------------------------------//
// ������
template <typename T>
T& LinkedList<T>::operator[](int index) const
{
	if (index < size && index >= 0)
	{
		Point<T>* temp = head;
		int count = 0;
		while (temp != nullptr)
		{
			if (count == index)
				return temp->num;
			temp = temp->next;
			++count;
		}
	}
	cout << endl << endl;
	perror("������ ��������������");
	cout << endl;
	exit(1);
}
// ����������� �����������
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
}
// ������������
template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& list)
{
	// ������� size_temp, �.�. pop ��������� size, ����� ���������
	int size_temp = size;
	// ������� ��� ��������
	for (int i = 0; i < size_temp; i++)
	{
		this->pop();
	}
	// �������� ����� push()
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
	return *this;
}
// ���������
template <typename T>
LinkedList<T> LinkedList<T>::operator * (LinkedList<T>& list)
{
	// ������� ����� ������ �� ���� �������, �������� ����� ������ ��������
	T nulik;
	nulik = 0;
	LinkedList<T> new_list;
	for (int i = 0; i < min((int)size, list()); i++)
	{
		new_list.push((*this)[i] * list[i]);
	}
	for (int i = 0; i < max((int)size, list()) - min((int)size, list()); i++)
	{
		new_list.push(nulik);
	}
	return new_list;
}