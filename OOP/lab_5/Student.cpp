#include "Student.h"
using namespace std;
//конструктор без параметров
Student::Student(void) :Person()
{
	subject = "";
	ocenka = 0;
}
//дестрктор
Student::~Student(void)
{
}
//конструктор с параметрами
Student::Student(string M, int C, string P, int G) :Person(M, C)
{
	subject = P;
	ocenka = G;
}
//конструктор копирования
Student::Student(const Student& L)
{
	name = L.name;
	age = L.age;
	subject = L.subject;
	ocenka = L.ocenka;
}
//модификатор
void Student::set_i2(int G)
{
	ocenka = G;
}
void Student::set_s2(string P)
{
	subject = P;
}
//оперция присваивания
Student& Student::operator=(const Student& l)
{
	if (&l == this)return *this;
	name = l.name;
	age = l.age;
	subject = l.subject;
	ocenka = l.ocenka;
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Student& l)
{
	cout << "\nname:"; in >> l.name;
	cout << "\nage:"; in >> l.age;
	cout << "\nsubject:"; in >> l.subject;
	cout << "\nocenka:"; in >> l.ocenka;
	return in;
}
//операция вывода
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