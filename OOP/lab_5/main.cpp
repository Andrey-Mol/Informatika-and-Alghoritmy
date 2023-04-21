#include "Object.h" 
#include "Person.h" 
#include "Student.h" 
#include "Vector.h" 
#include <string> 
#include <iostream> 
using namespace std; 
void main()
{
	 
	int n;
	cin >> n;
	Vector v(n);//вектор из 5 элементов
	for (int i = 0; i < n; i++)
	{
		Person f;
		cin >> f;
		Object* p = &f;
		v.Add(p);
	}


	cout<<v;//вывод вектора
}
