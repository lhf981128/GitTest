#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<numeric>
#include<functional>
#include<math.h>
#include "stdio.h"
#include "stdint.h"
using namespace std;

int main()
{
	/*
	a 一个位置的大小是2个字节，p指向的大小是4个字节，所以p++ 执行一次就会跳动4个字节。
	这样，他所指向的位置应该是0X0014,0X0013
	*/
	uint16_t a[12] = { 0x11,0x12,0x13,0x14,0x77,0x88 };
	uint32_t *p = (uint32_t*)&a[0];
	p++;
	cout << *p << endl;
	printf("%4X\n", *p);
	return 0;
}

//#pragma vtordisp(off)
//#include <iostream>
//using namespace std;
//
//class Base0 {
//public:
//	int age;
//	Base0(int a) :age(a) {}
//	virtual void func() { cout << "Base0::virtual"; }
//};
//class Base1 :virtual public Base0 {
//public:
//	int age;
//	virtual void func2() { cout << "Base1::virtual"; }
//	void func() { cout << "Base1::virtual"; }
//
//	Base1(int a) :age(a), Base0(1) {}
//};
//
//int main() {
//	Base0 b(1);
//	Base1 b1(2);
//	cout << sizeof(b) << endl;
//	cout << sizeof(b1) << endl;
//	return 0;
//}

//#pragma vtordisp(off)
//#include <iostream>
//using std::cout;
//using std::endl;
//
////测试一：单个虚继承，不带虚函数
//
//class A
//{
//public:
//	A() : _ia(10) {}
//
//	virtual
//	void f()
//	{
//		cout << "A::f()" << endl;
//	}
//private:
//	int _ia;
//};
//
//class  B
//	: virtual public A
//{
//public:
//	B() : _ib(20) {}
//
//	void fb()
//	{
//		cout << "B::fb()" << endl;
//	}
//	virtual
//	void f()
//	{
//		cout << "B::f()" << endl;
//	}
//
//	/*virtual
//	void fb2()
//	{
//		cout << "B::fb2()" << endl;
//	}*/
//
//private:
//	int _ib;
//};
//
//
//int main(void)
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	B b;
//	system("pause");
//	return 0;
//}
