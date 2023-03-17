#include<iostream>
#include<vector>
#include<map>
#include<string>

class MyAnimals {
public:
	const char* name;
	int age;
public:
	MyAnimals(const char* name, int age) {
		this->age = age;
		this->name = name;
	}
	~MyAnimals()
	{

	}

};

//int main(void) {
//	using namespace std;
//	MyAnimals* pDog = new MyAnimals("dog",1);
//	MyAnimals* pCat = new MyAnimals("cat",2);
//	MyAnimals* pPig = new MyAnimals("pig", 3);
//	MyAnimals* pSnake = new MyAnimals("snake", 4);
//	MyAnimals* pCow = new MyAnimals("cow", 5);
//
//	vector<MyAnimals*> v;
//	v.push_back(pDog);
//	v.push_back(pCat);
//	v.push_back(pPig);
//	v.push_back(pSnake);
//	v.push_back(pCow);
//
//	//delete pPig;//这个会让vector的迭代器失效
//	v.erase(v.begin() + 2);
//	for (vector<MyAnimals*>::iterator i = v.begin(); i != v.end(); i++)
//	{
//		cout << (*i)->name << " " << (*i)->age << endl;
//	}
//	while (cin) {
//		string a;
//		getline(cin, a);
//		cout << a << endl;
//	}
//
//	return 0;
//
//}