#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
// ���������� �������
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
	//������ � ������� Person
	Person a;
	cin >> a;
	cout << a;
	Person b("Maxim", 4);
	cout << b;
	a = b;
	cout << a;
	//������ � ������� Student
	Student c;
	cin >> c;
	cout << c;
	c.bad();
	//������� �����������
	f1(c);//�������� ������ ������ Student
	a = f2();//������� � ������� ������ ������ Student
	cout << a;
	return 0;
}