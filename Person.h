#pragma once
#include <string>
#include<iostream>
using namespace std;
class Person {
public:
	string ten;
	int tuoi;
	string diaChi;
	bool gioiTinh;

public:
	Person();
	Person(string, int, string, bool);
	Person(const Person&);
	~Person();
	void showPerson();
	friend istream &operator >>(istream&, Person&);
	friend ostream &operator <<(ostream&, Person);
};