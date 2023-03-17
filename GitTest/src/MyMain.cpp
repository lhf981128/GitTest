#include<iostream>
#include<fstream>
#include<chrono>
#include<thread>
#include<string>
#include"MyVector.h"
using namespace std;

template<typename S,int N>

//普通模板类
class Array {
private:
	S m_array[N];
public:
	int getSize()const {
		return N;
	}
};

struct Vector3 {
	float x = 0.0f, y = 0.0f, z = 0.0f;
	int* m_MemoryBlock = nullptr;
	Vector3()
	{
		m_MemoryBlock = new int[5];
	}
	Vector3(float sca):x(sca),y(sca),z(sca) {
		m_MemoryBlock = new int[5];
	}
	Vector3(float x, float y, float z) :x(x), y(y), z(z) {
		m_MemoryBlock = new int[5];
	}

	Vector3(const Vector3& other) = delete;

	//移动
	Vector3(Vector3&& other)noexcept :x(other.x), y(other.y), z(other.z)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		cout << "Move"<<"1" << endl;
	}

	Vector3& operator=(const Vector3& other) = delete;

	Vector3& operator=(Vector3&& other)noexcept {
		cout << other.x<< "Move"<<"2\n";
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	~Vector3()
	{
		cout << "destroy" << endl;
		delete[] m_MemoryBlock;
	}


};



//正常类，用于学习常成员函数
class Entity {
public:
	int x;
	int y;
	Entity(int x,int y) {
		this->x = x;
		this->y = y;
	}
	int getX() const//const修饰this指针，在该函数里，this指针指向的是一个常Entity对象，
	{
		const Entity& e= *this;//解引用该函数里的this函数，得到的是一个常对象的引用
	}
	void Print() {
		cout << this->x << " " << this->y << endl;
	}
	~Entity()
	{

	}
};

//简单的unique_ptr智能指针
class SmartPtr {

public:
	SmartPtr* m_ptr;
	SmartPtr(SmartPtr* ptr):m_ptr(ptr) {

	}
	~SmartPtr()
	{
		delete m_ptr;
	}
};


//字符串类
class String {
public:
public:
	friend ostream& operator <<(ostream& st, const String& str);
	char& operator[](unsigned int index) {
		return m_buffer[index];
	}
	String(const char* str) {//有参构造
		cout << "有参" << endl;
		m_size = strlen(str);
		m_buffer = new char[m_size + 1];//加1是为了把char*字符串最后的\0加进去，否则会出现随机字符
		memcpy(m_buffer, str, m_size);
		m_buffer[m_size] = 0;
	}
	//默认提供的拷贝构造是浅拷贝，这样使得两个String的m_buffer指向同一块地址，当执行析构函数时，会使得同一块内存地址被析构两次，导致程序崩溃
	//String(String& other):m_buffer(other.m_buffer),m_size(other.m_size){}这是默认拷贝构造函数，这里可以看出，m_buffer与other.m_buffer指向同一块地址
	String(String& other) :m_size(other.m_size) {
		cout << "Copy Func" << endl;
		m_buffer = new char[m_size + 1];//新new了一块地址，与other.m_buffer不同。
		memcpy(m_buffer, other.m_buffer, m_size + 1);
	}
	~String()
	{
		delete[] m_buffer;
	}
private:
	char* m_buffer;//里面存储传进来的字符串
	unsigned int m_size;

};

//输出流操作符重载
ostream& operator <<(ostream& st, const String& str) {
	st << str.m_buffer;
	return st;
}

void PrintString(String a) {
	cout << a << endl;
}

void PrintStringConst(const String& a) {
	cout << a << endl;
}

struct MyStr {
	int x = 0;
	int y = 1;
	int z = 2;
};

struct MyStruct
{
public:
	int x = 0;
	int y = 1;
	int z = 2;
public:
	virtual void speak() {
		cout << "爸爸在说话!!!!" << endl;
	}

};

//结构体继承
struct vert:public MyStruct{
	void speak() {
		cout << "儿子在说话!!!!" << endl;
	}
};

//结构体也可以有构造函数、析构函数、多态
struct Timer {
         chrono::time_point<chrono::steady_clock> start, end;
		 chrono::duration<float> duration;

		 Timer() {
			 start = chrono::high_resolution_clock::now();
		 }
		 ~Timer()
		 {
			 end = chrono::high_resolution_clock::now();
			 duration = end-start;

			 float ms = duration.count()*1000.0f;
			 cout <<"time took"<< ms << "ms" << endl;
		 }
};
template<typename T>
void PrintVector(const MyVector<T> & a)//打印自制vector的元素
{
	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a[i] << endl;
	}
	cout << "____________________\n";
}


void PrintVector3(const MyVector<Vector3>& ve) {
	for (size_t i = 0; i < ve.Size(); i++)
	{
		cout << ve[i].x << " " << ve[i].y << " " << ve[i].z << endl;
	}
}

void PrintT(int &t)
{
	cout << "lvalue" << endl;
}

void PrintT(int &&t)
{
	cout << "rvalue" << endl;
}

template<typename D>
void TestForward(D && v)
{
	PrintT(v);
	PrintT(std::forward<int>(v));
	PrintT(std::move(v));
	cout << endl;
}


//int main() {
//	//自写vector测试
//	/*MyVector<string> myv;
//	myv.PushBack("C++");
//	myv.PushBack("Java");
//	myv.PushBack("C#");
//	myv.PushBack("Python");
//	myv.PushBack("C");
//	PrintVector(myv);*/
//
//	/*MyVector<Vector3> ve;
//	ve.EmplaceBack(1.0f);
//	ve.EmplaceBack(2,3,4);
//	ve.EmplaceBack();
//	PrintVector3(ve);
//	cout << "-----------" << endl;
//	ve.PopBack();
//	PrintVector3(ve);
//	cout << "----------" << endl;
//	ve.Clear();
//	PrintVector3(ve);*/
//
//
//	//测试forward保证完美转发与引用折叠
//	TestForward(1);//传入字面值1时，D被推断为int ,v的类型是int &&，但是v本身是个左值，因为它是变量，只不过它作为引用绑定到了一个右值上，
//					//所以Print(v)会调用接收左值引用参数的Print，毕竟右值引用不能绑定左值
//	int x = 1;
//	TestForward(x);//TestForward的参数类型是T&&,当传入一个左值时，由于c++新标准提出了引用折叠，所以T会被折叠推断为int &
//	TestForward(std::forward<int>(x));
//
//
//
//	//Timer timer;
//	//auto start = chrono::high_resolution_clock::now();
//
//	//Array<int, 64> a;
//	//cout << a.getSize() << endl;
//	//unique_ptr<Entity> pr = make_unique<Entity>(5,8);
//	//pr->Print();
//	//String first = "LiuHongFei";//直接调用有参构造，相当于String first("LiuHongFei");
//	//String second = first;//调用拷贝构造
//	//first[0] = 'K';
//
//	////PrintString(first);//因为PrintString的参数传递是值传递，所以这里也会调用拷贝构造；可以将PrintString的形参改为const String&，来避免拷贝,如PrintStringConst函数；
//	////PrintString(second);
//
//	//PrintStringConst(first);
//	//PrintStringConst(second);
//
//	////一个类对象的地址就是类所包含的这一片内存空间的首地址，这个首地址也就对应具体某一个成员变量的地址
//	////定义一个指向空的MyStruct指针，则他的第一个数据成员地址是从0开始的，就可计算其成员的地址偏移量
//	//int offset = (int)&((MyStr*)nullptr)->y;
//
//	//cout << offset << endl;
//
//	//MyStr temp;
//	//int* position = (int*)&temp;
//	//cout << position[0] << "," << position[1] << "," << position[2] << endl;
//
//	//int y1 = *(int*)((char*)&temp + 4);//转为char*指针，+1相当于走一字节，所以要走一个int的长度，要加4
//	//cout << "y:" << y1 << endl;
//	//int z1 = *(int*)((char*)&temp + 8);
//	//cout << "z:" << z1 << endl;
//
//
//	//int y2 = *((int*)&temp + 1);//转为int*指针，+1相当于走四个字节，所以走一个int的长度，只加1
//	//cout << "y2:" << y2 << endl;
//	//int z2 = *((int*)&temp + 2);
//	//cout << "z2:" << z2 << endl;
//
//
//	//auto end = chrono::high_resolution_clock::now();
//	//chrono::duration<float> duration = end - start;
//	//float ms = duration.count()*1000.0f;
//	//cout <<"time took"<<ms<< "ms" << endl;
//
//	//MyStruct* far = new MyStruct();
//	//far->speak();
//	//MyStruct* far1 = new vert();
//	//far1->speak();
//
//	//delete far;
//	//delete far1;
//
//
//	return 0;
//}