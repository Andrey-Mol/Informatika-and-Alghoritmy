#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;
class Person :
    public Object
{
	//конструктор без параметров
public:
	Person(void);
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
	void Show();//функция для просмотра атрибутов класса с помощью указателя 
protected:
	string name;
	int age;
};

