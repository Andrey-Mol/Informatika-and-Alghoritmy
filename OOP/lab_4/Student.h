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
	Student(void);//����������� ��� ����������
	~Student(void);//����������
	Student(string, int, string, int);//����������� � �����������
	Student(const Student&);//����������� �����������
	Student& operator=(const Student&);//�������� ������������
	friend istream& operator>>(istream& in, Student& l);//�������� �����
	friend ostream& operator<<(ostream& out, const Student& l); //�������� ������
};

