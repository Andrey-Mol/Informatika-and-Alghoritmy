#include <iostream>
#include "fraction.h"
using namespace std;
void fraction::Init(double F, int S)//���������� ������ ��� ������������� ����� ��������� 
{
	first = F; second = S;
}
//���������� ������ ��� ������ �������� ����� ��������� 
void fraction::Read()
{
	cout << "\nfirst?"; cin >> first; cout << "\nsecond?"; cin >> second;
}
//���������� ������ ��� ������ �������� ����� ��������� 
void fraction::Show()
{
	cout << "\nfirst=" << first; cout << "\nsecond=" << second; cout << "\n";
}
double fraction::element(int j)//����� ��� ���������� � ������� 
{
	return first * pow(1.0, j);
}
