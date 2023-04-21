#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
	//конструктор без параметров
public:
	Person(void);
public:
	//деструктор
	virtual ~Person(void);
	//констрктор с параметрами
	Person(string, int);
	//конструктор копирования
	Person(const Person&);
	//селекторы
	string Get_name() { return name; }
	int Get_age() { return age; }
	//модификаторы
	void Set_name(string);
	void Set_age(int);
	//перегрузка операции присваивания
	Person& operator=(const Person&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Person& c);
	friend ostream& operator<<(ostream& out, const Person& c);
	//атрибуты
protected:
	string name;
	int age;
};