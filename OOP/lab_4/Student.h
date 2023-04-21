#pragma once
#include "Person.h"

class Student :
    public Person
{
protected:
    string subject;
    int ocenka;
public:
	int get_i2() { return ocenka; }
    void set_i2(int);
	string get_s2() { return subject; }
    void set_s2(string);
    void bad();
	Student(void);//конструктор без параметров
	~Student(void);//деструктор
	Student(string, int, string, int);//конструктор с параметрами
	Student(const Student&);//конструктор копирования
	Student& operator=(const Student&);//операция присваивания
	friend istream& operator>>(istream& in, Student& l);//операция ввода
	friend ostream& operator<<(ostream& out, const Student& l); //операция вывода
};

