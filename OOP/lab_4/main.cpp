#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
// глобальные функции
void f1(Person& c)
{
	c.Set_name("Mihail");
	cout << c;
}
Person f2()
{
	Student l("Natalia", 3, "Math", 5);
	return l;
}
int main()
{
	//работа с классом Person
	Person a;
	cin >> a;
	cout << a;
	Person b("Maxim", 4);
	cout << b;
	a = b;
	cout << a;
	//работа с классом Student
	Student c;
	cin >> c;
	cout << c;
	c.bad();
	//принцип подстановки
	f1(c);//передаем объект класса Student
	a = f2();//создаем в функции объект класса Student
	cout << a;
	return 0;
}