#pragma once
#include<iostream>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& os, const Person& p);
public:
	Person();
	Person(int k, int j);


private:
	int a;
	int b;
};
ostream& operator<<(ostream& os, const Person& p) {
	os << p.a << endl;
}