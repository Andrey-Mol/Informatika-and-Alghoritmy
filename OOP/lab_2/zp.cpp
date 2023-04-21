#include "zp.h"
#include <iostream>
using namespace std;
zp::zp()
{
	fio = "";
	premiya = 0;
	oklad = 0;
	cout << "Constructor bez parametrov dlia objecta" << this << endl;
}
//конструктор с параметрами
zp::zp(string N, int K, double S)
{
	fio = N;
	premiya = K;
	oklad = S;
	cout << "Constructor s parametrami dlia objecta" << this << endl;
}
//конструктор копирования
zp::zp(const zp& t)
{
	fio = t.fio;
	premiya = t.premiya;
	oklad = t.oklad;
	cout << "Constructor copirovania dlia objecta" << this << endl;
}
//деструктор
zp::~zp()
{
	cout << "Destructor dlia objecta" << this << endl;
}
//селекторы
string zp::get_s()
{
	return fio;
}
int zp::get_i()
{
	return premiya;
}
double zp::get_d()
{
	return oklad;
}
//модификаторы
void zp::set_s(string N)
{
	fio = N;
}
void zp::set_i(int K)
{
	premiya = K;
}
void zp::set_d(double S)
{
	oklad = S;
}
//метод для просмотра атрибутов
void zp::show()
{
	cout << "fio :" << fio << endl;
	cout << "premiya :" << premiya << endl;
	cout << "oklad :" << oklad << endl;
}
