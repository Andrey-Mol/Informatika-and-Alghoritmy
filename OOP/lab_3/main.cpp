#include "Pair.h"
#include <iostream>
using namespace std;
void main()
{
	Pair a;//����������� ��� ����������
	Pair b; //����������� ��� ����������
	Pair c; //����������� ��� ����������
	cin >> a;//���� ����������
	cin >> b;//���� ����������
	int n;
	double v;
	cout << "pibavit int?";
	cin >> n;
	cout << "pibavit double?";
	cin >> v;
	c = a + b;
	cout << "a=" << a << endl; //����� ����������
	cout << "b=" << b << endl; //����� ����������
	cout << "c=" << c << endl; //����� ����������
	cout << "c+int=" << c+n << endl; //����� ����������
	cout << "c+double=" << c + v << endl; //����� ����������
}