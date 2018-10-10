#pragma once
#include "Person.h"
#include<String>
#include<iostream>
using namespace std;

class QuanLy {
public:
	Person *data;
	int n; 
public:
	QuanLy(int);
	~QuanLy(void);
	void setPerson(int, Person);
	void show();
	void addFirst(Person);
	void addLast(Person);
	void addPosition(int, Person);
	void deleteFirst();
	void deleteLast();
	void deletePosition(int);
	void update(string);
	friend istream &operator >>(istream &, QuanLy&);
	friend ostream &operator <<(ostream&, QuanLy&);
	Person operator[](int);

	void merge(int, int, int);
	void mergeSort(int, int);
};

