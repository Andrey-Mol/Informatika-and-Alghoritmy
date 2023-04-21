#include "Person.h"
//конструктор без параметров
Person::Person(void)
{
	name = "";
	age = 0;
}
//деструктор
Person::~Person(void)
{
}
//конструктор с параметрами
Person::Person(string M, int C)
{
	name = M;
	age = C;
}
//конструктор копирования
Person::Person(const Person& Person)
{
	name = Person.name;
	age = Person.age;
}
//модификаторы
void Person::Set_age(int C)
{
	age = C;
}
void Person::Set_name(string M)
{
	name = M;
}
//перегрузка операции присваивания
Person& Person::operator=(const Person& c)
{
	if (&c == this)return *this;
	name = c.name;
	age = c.age;
	return *this;
}
//глобальная функция для ввода
istream& operator>>(istream& in, Person& c)
{
	cout << "\nname:"; in >> c.name;
	cout << "\nage:"; in >> c.age;
	return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Person& c)
{
	out << "\nname : " << c.name;
	out << "\nage : " << c.age;
	out << "\n";
	return out;
}