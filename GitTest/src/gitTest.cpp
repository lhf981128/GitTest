#include"gitTest.h"


Person::Person() {
	cout <<"��Ĭ�Ϲ���"<< endl;
	a = 0;
	b = 0;
}
Person::Person(int k, int j) {
	cout << "���вι���" << endl;
	a = k;
	b = j;
}
Person::~Person(){
	cout << "���������" << endl;
}