#include "Person.h"
#include<iostream>
using namespace std;

Person::Person() {
	this->ten = "no Name";
	this->tuoi = 0;
	this->diaChi = "no address";
	this->gioiTinh = false;
}
Person::Person(string name, int age, string add, bool gender) {
	this->ten = name;
	this->tuoi = age;
	this->diaChi = add;
	this->gioiTinh = gender;
}
Person::Person(const Person&ps) {
	this->ten = ps.ten;
	this->tuoi = ps.tuoi;
	this->diaChi = ps.diaChi;
	this->gioiTinh = ps.gioiTinh;
}
Person::~Person() {

}
void Person::showPerson() {
	cout <<"Ten: "<<this->ten<<endl;
	cout <<"Tuoi: "<<this->tuoi<<endl;
	cout <<"dia chi: " <<this->diaChi <<endl;
	cout <<"gioi tinh: " <<this->gioiTinh<<endl;
}
istream &operator >>(istream &i, Person &ps) {
	cout <<"Ten: ";
	cin >>ps.ten;
	cout <<"Tuoi: ";
	cin >>ps.tuoi;
	cout << "Dia chi: ";
	cin >>ps.diaChi;
	cout <<"Gioi tinh: ";
	cin >>ps.gioiTinh;
	return i;
}
ostream &operator <<(ostream &o, Person ps) {
	o <<"Ten: "<<ps.ten<<endl;
	o <<"Tuoi: "<<ps.tuoi<<endl;
	o <<"dia chi: " <<ps.diaChi <<endl;
	o <<"gioi tinh: " <<ps.gioiTinh<<endl;
	return o;
}