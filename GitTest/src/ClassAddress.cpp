#include <iostream>
#include <memory>
using namespace std;


typedef void(*func)(void);
class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};


//int main()
//{
//	Base base;
//	/*
//	对于有虚函数、没有属性的空类对象，无论虚函数的数量为多少，空间长度都为4字节，这是因为它包含一个指向虚表的指针，指针内存放的是虚表的地址
//
//	有虚函数的类的每个对象的前四个字节，被用来存放虚表指针，而这个指针的内容是虚表的地址，虚表相当于一个指针数组，里面存放着虚函数的地址，每个虚函数地址也占4个字节
//
//	注意：注释里说的4个字节都是相对于32位系统
//	*/
//
//
//	//获取vptr的地址，运行在visual studio  x86环境下，所以将指针按int*大小处理
//	//另外基于C++的编译器应该是保证虚函数表的指针存在于对象实例中最前面的位置
//	int* vPtr = (int*)(&base);//int *表示强制获取4个字节的内容，即虚表指针的地址
//	//获取vTable 首个函数的地址
//	func vTable_f = (func)*(int*)(*vPtr);//*vPtr:解引用虚表指针获得虚表的地址。(int*)(*vPtr):强制取这个地址里的前4个字节，这4个字节里存放着第一个虚函数的地址。
//										//*(int*)(*vPtr)：解引用得到函数地址。（func)*(int*)(*vPtr):强转为func类型
//	//获取vTable 第二个函数的地址
//	func vTable_g = (func)*((int*)(*vPtr) + 1);//加1 ，走4个字节到存放第二个函数的位置
//	func vTable_h = (func)*((int*)(*vPtr) + 2);//加2，走8个字节到存放第三个函数的位置
//
//	vTable_f();
//	vTable_g();
//	vTable_h();
//
//	return 0;
//}

