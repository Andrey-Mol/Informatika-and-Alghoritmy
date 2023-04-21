#include <iostream>
#include "fraction.h"
using namespace std;
void fraction::Init(double F, int S)//реализация метода для инициализации полей структуры 
{
	first = F; second = S;
}
//реализация метода для чтения значений полей структуры 
void fraction::Read()
{
	cout << "\nfirst?"; cin >> first; cout << "\nsecond?"; cin >> second;
}
//реализация метода для вывода значений полей структуры 
void fraction::Show()
{
	cout << "\nfirst=" << first; cout << "\nsecond=" << second; cout << "\n";
}
double fraction::element(int j)//метод для возведения в степень 
{
	return first * pow(1.0, j);
}
