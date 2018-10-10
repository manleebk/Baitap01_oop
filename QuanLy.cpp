#include "QuanLy.h"
#include<iostream>
using namespace std;

QuanLy::QuanLy(int n) {
	this->n = n;
	this->data = new Person[this->n];
}
QuanLy::~QuanLy(void) {
	delete[] this->data;
}
//Show
void QuanLy::show() {
	for (int i = 0; i < this->n; i++) {
		cout <<i+1<<" ";
		(*(this->data+i)).showPerson();
	}
}
//Da nang hoa Nhap
istream &operator >>(istream&i, QuanLy&ql) {
	ql.data = new Person[ql.n];
	for (int i = 0; i < ql.n; i++)
	{
		cin >>*(ql.data+i);
	}
	return i;
}
//Da nang hoa Xuat
ostream &operator <<(ostream &o, QuanLy &ql) {
	for (int i = 0; i < ql.n; i++) {
		cout <<i+1<<" ";
		o <<*(ql.data+i);
	}
	return o;
}
//Da nang hoa phan tu thu k
Person QuanLy::operator [](int k) {
	Person ps001;
	ps001 = *(this->data + k);
	return ps001;
}
//them vao dau danh sach
void QuanLy::addFirst(Person ps01) {
	Person *p;
	p = new Person[this->n+1];
	*(p) = ps01;
	for (int i = 0; i < this->n; i++) {
		*(p+i+1) = *(this->data+i);
	}
	delete [] this->data;
	this->n++;
	this->data = new Person[this->n];
	for (int i = 0; i < this->n; i++) {
		*(this->data+i) = *(p+i);
	}
	delete [] p;
}
//them vao cuoi danh sach
void QuanLy::addLast(Person ps) {
	Person *p;
	p = new Person[this->n+1];
	for (int i = 0; i < this->n; i++) {
		*(p+i) = *(this->data+i);
	}
	*(p+n) = ps;
	this->n++;
	delete[] this->data;
	this->data = new Person[this->n];
	for (int i = 0; i < this->n; i++) {
		*(this->data+i) = *(p+i);
	}
	delete[] p;
}
//them vao vi tri bat ki
void QuanLy::addPosition(int k, Person ps) {
	if(k>this->n ||k<0) {
		cout <<"Khong hop le"<<endl;
	} else if (k==1) {
		addFirst(ps);
	}  else if(k==n) {
		addLast(ps);
	} else {
		Person *p;
		p = new Person[this->n+1];
		for (int i = 0; i < k; i++) {
			*(p+i) = *(this->data+i);
		}
		*(p+k)= ps;
		for (int i = k+1; i < this->n; i++) {
			*(p+i) = *(this->data+i);
		}
		delete[] this->data;
		this->n++;
		this->data = new Person[this->n];
		for (int i = 0; i < this->n; i++)
		{
			*(this->data+i)= *(p+i);
		}
		delete[] p;
	}
}
//Xoa vi tri dau tien
void QuanLy::deleteFirst() {
	Person *p;
	p = new Person[this->n-1];
	for (int i = 1; i < this->n; i++) {
		*(p+i-1)= *(this->data+i);
	}
	delete [] this->data;
	this->n--;
	this->data = new Person[this->n];
	for (int i = 0; i < this->n; i++) {
		*(this->data+i) = *(p+i);
	}
	delete [] p;
}
//Xoa vi tri cuoi
void QuanLy::deleteLast() {
	Person *p;
	p = new Person[this->n-1];
	for (int i = 0; i < this->n-1; i++) {
		*(p+i) = *(this->data+i);
	}
	delete[] this->data;
	this->n--;
	this->data = new Person[this->n];
	for (int i = 0; i < this->n; i++)
	{
		*(this->data+i) = *(p+i);
	}
	delete [] p;
}
//Xoa vi tri k
void QuanLy::deletePosition(int k) {
	Person *p;
	p = new Person[this->n-1];
	for(int i=0; i<k; i++) {
		*(p+i) = *(this->data+i);
	}
	for(int i = k+1; i<n; i++) {
		*(p+i-1) = *(this->data+i);
	}
	delete[] this->data;
	this->n--;
	this->data = new Person[this->n];
	for (int i = 0; i < n; i++) {
		*(this->data+i) = *(p+i);
	}
	delete [] p;
}

//cap nhat theo ten
void QuanLy::update(string ten) {
	int tuoi;
	string diachi;
	string gioiTinh;
	cout << "tuoi: ";
	cin >> tuoi;
	cout << "Dia chi: " ;
	cin >> diachi;
	cout << "gioi tinh: ";
	cin >> gioiTinh;
	for (int i = 0; i < this->n; i++){
		if((this->data+i)->ten == ten) {

			(this->data+i)->ten = ten;
			(this->data+i)->tuoi = tuoi;
			(this->data+i)->diaChi = diachi;
			if(gioiTinh == "true") {
				(this->data+i)->gioiTinh = true;
			} else {
				(this->data+i)->gioiTinh = false;
			}
		}
	}
}
//thiet lap vi tri k co gia tri Person- modify
void QuanLy::setPerson(int k, Person ps) {
	*(this->data+k) = ps;
}

//Sap xep mergeSort
void QuanLy::merge(int l, int m, int r) {
	int i, j, k; 
	int n1 = m - l + 1; 
    int n2 =  r - m; 
	Person *dataL, *dataR;
	dataL = new Person[n1];
	dataR = new Person[n2];
	for (int i = 0; i < n1; i++) {
		*(dataL+i) = *(this->data+l+i);
	}
	for (int j = 0; j < n2; j++) {
		*(dataR+j) = *(this->data+m+1+j);
	}

	i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if((dataL+i)->ten.compare((dataR+j)->ten) <0) {
			*(this->data+k) = *(dataL+i);
			i++;
		} else {
			*(this->data+k) = *(dataR+j);
			j++;
		}
		k++;
	}
	while (i < n1) 
	{ 
		//arr[k] = L[i]; 
		*(this->data+k)= *(dataL+i);
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		//arr[k] = R[j]; 
		*(this->data+k) = *(dataR+j);
		j++; 
		k++; 
	} 
}
void QuanLy::mergeSort(int l, int r) {
	if (l < r) { 

		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(l, m); 
		mergeSort(m+1, r); 
		merge(l, m, r); 
	} 
}