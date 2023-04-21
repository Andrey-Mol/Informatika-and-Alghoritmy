#include "Pair.h"
#include <iostream>
using namespace std;
void main()
{
	Pair a;//конструктор без параметров
	Pair b; //конструктор без параметров
	Pair c; //конструктор без параметров
	cin >> a;//ввод переменной
	cin >> b;//ввод переменной
	int n;
	double v;
	cout << "pibavit int?";
	cin >> n;
	cout << "pibavit double?";
	cin >> v;
	c = a + b;
	cout << "a=" << a << endl; //вывод переменной
	cout << "b=" << b << endl; //вывод переменной
	cout << "c=" << c << endl; //вывод переменной
	cout << "c+int=" << c+n << endl; //вывод переменной
	cout << "c+double=" << c + v << endl; //вывод переменной
}