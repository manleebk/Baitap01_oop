#include "Person.h"
#include "QuanLy.h"
#include<iostream>
using namespace std;

int main() {
	/*Person ps01("Man Le",21,"DN",true);
	Person ps02("Van Man",22,"NN",true);
	Person ps03("Man",23,"QN",true);
	QuanLy ql01(5);
	ql01.setPerson(0,ps01);
	ql01.setPerson(2,ps02);
	ql01.setPerson(3,ps03);*/

	//ql01.show();
	//ql01.addFirst(ps01);
	//ql01.addLast(ps01);
	//ql01.addPosition(-10, ps01);

	//ql01.deleteFirst();
	//ql01.deleteLast();
	//ql01.deletePosition(2);
	//ql01.update("Man");
	//ql01.show();
	//cout <<ps01;

	/*QuanLy ql01(3);
	cin >>ql01;
	cout <<ql01;*/
	//cout <<ql01[1];

	QuanLy ql01(5);
	Person ps01("Aaa",11,"aaa",1);
	Person ps02("T",22,"fff",1);
	Person ps03("E",33,"ccc",1);
	Person ps04("D",44,"ggg",1);
	Person ps05("C",55,"ddd",1);

	ql01.setPerson(0,ps01);
	ql01.setPerson(1,ps02);
	ql01.setPerson(2,ps03);
	ql01.setPerson(3,ps04);
	ql01.setPerson(4,ps05);

	ql01.mergeSort(0,4);

	cout <<ql01;
	system("pause");
	return 0;
}