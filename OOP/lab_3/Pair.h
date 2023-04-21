#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int a;
	double b;
public:
	Pair() { a = 0; b = 0; };
	Pair(int m, double s) { a = m; b = s; }
	Pair(const Pair& t) { a = t.a; b = t.b; }
	~Pair() {};
	int get_a() { return a; }
	double get_b() { return b; }
	void set_a(int m) { a = m; }
	void set_b(double s) { b = s; }
	//перегруженные операции
	Pair& operator=(const Pair&);
	Pair operator+(const Pair&);
	Pair operator+(const int);
	Pair operator+(const double);
	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
};


