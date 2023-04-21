#pragma once
#include <iostream>
using namespace std;
class zp
{
	string fio;
	double oklad;
	int premiya;
public:
	zp();
	zp(string,int, double);
	zp(const zp&);
	~zp();
	string get_s();
	void set_s(string);
	double get_d();
	void set_d(double);
	int get_i();
	void set_i(int);
	void show();
};

