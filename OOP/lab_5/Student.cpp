#include "Student.h"
using namespace std;
//����������� ��� ����������
Student::Student(void) :Person()
{
	subject = "";
	ocenka = 0;
}
//���������
Student::~Student(void)
{
}
//����������� � �����������
Student::Student(string M, int C, string P, int G) :Person(M, C)
{
	subject = P;
	ocenka = G;
}
//����������� �����������
Student::Student(const Student& L)
{
	name = L.name;
	age = L.age;
	subject = L.subject;
	ocenka = L.ocenka;
}
//�����������
void Student::set_i2(int G)
{
	ocenka = G;
}
void Student::set_s2(string P)
{
	subject = P;
}
//������� ������������
Student& Student::operator=(const Student& l)
{
	if (&l == this)return *this;
	name = l.name;
	age = l.age;
	subject = l.subject;
	ocenka = l.ocenka;
	return *this;
}
//�������� �����
istream& operator>>(istream& in, Student& l)
{
	cout << "\nname:"; in >> l.name;
	cout << "\nage:"; in >> l.age;
	cout << "\nsubject:"; in >> l.subject;
	cout << "\nocenka:"; in >> l.ocenka;
	return in;
}
//�������� ������
ostream& operator<<(ostream& out, const Student& l)
{
	out << "\nname : " << l.name;
	out << "\nage : " << l.age;
	out << "\nsubject : " << l.subject;
	out << "\nocenka : " << l.ocenka;
	out << "\n";
	return out;
}
void Student::bad()
{
	if (ocenka < 4)
		cout << "plohaya ocenka!!!" << endl << endl;
}
void Student::Show()
{
	cout << "\nname: " << name;
	cout << "\nage: " << age;
	cout << "\nsubject : " << subject;
	cout << "\nocenka : " << ocenka;
	cout << "\n";
}