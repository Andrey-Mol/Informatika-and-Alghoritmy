#include "Pair.h"
#include <iostream>
using namespace std;
//���������� �������� ������������
Pair& Pair::operator=(const Pair& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	a = t.a;
	b = t.b;
	return *this;
}

//���������� �������� �������� ��������
Pair Pair::operator+(const Pair& t)
{
	Pair p;
	p.a = this->a + t.a;
	p.b = this->b + t.b;
	return p;
}
Pair Pair::operator+(const int t)
{
	Pair p(*this);
	p.a+=t;
	return p;
}
Pair Pair::operator+(const double t)
{
	Pair p(*this);
	p.b+=t;
	return p;
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Pair& t)
{
	cout << "a?"; in >> t.a;
	cout << "b?"; in >> t.b;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Pair& t)
{
	return (out << t.a << " : " << t.b);
}
