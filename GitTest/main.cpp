#include<stdio.h>
#include"inc/MyVector.h"
#include"inc/CSatck.h"


int main(int argc, char* argv[]) {
	CStack<int>* sta = new CStack<int>();
	for (int i = 0; i < 10; i++) {
		sta->Push(new int(i));
	}

	cout << "stack-int collection" << endl;
	for (; sta->Count();) {
		cout<<*sta->Peek()<<endl;
		sta->Pop();
	}
	delete sta;

	system("pause");  // NOLINT(concurrency-mt-unsafe)
	return 0;
}