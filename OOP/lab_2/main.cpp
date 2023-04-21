#include "zp.h"
#include <iostream>
#include <string>
using namespace std;
//функция для возврата объекта как результата
zp make_zp()
{
	string s;
	int i;
	double d;
	cout << "Vvedite fio: ";
	cin >> s;
	cout << "Vvedite premiya: ";
	cin >> i;
	cout << "Vvedite oklad: ";
	cin >> d;
	zp t(s, i, d);
	return t;
}
//функция для передачи объекта как параметра
void print_zp(zp t)
{
	t.show();
}
void main()
{
	//конструктор без параметров
	zp t1;
	t1.show();
	//коструктор с параметрами
	zp t2("Computer", 1, 15000);
	t2.show();
	//конструктор копирования
	zp t3 = t2;
	t3.set_s("Telephon");
	t3.set_i(2);
	t3.set_d(5000.0);
	//конструктор копирования
	print_zp(t3);
	//конструктор копирования
	t1 = make_zp();
	t1.show();
}