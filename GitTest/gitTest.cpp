#include"gitTest.h"


Person::Person() {
	cout <<"类默认构造"<< endl;
	a = 0;
	b = 0;
}
Person::Person(int k, int j) {
	cout << "类有参构造" << endl;
	a = k;
	b = j;
}
Person::~Person(){
	cout << "类对象析构" << endl;
}