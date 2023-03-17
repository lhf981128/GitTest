#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<numeric>
#include<functional>
#include<math.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
  };
 

class Solution {
public:
	/**
	 *
	 * @param head ListNode类
	 * @param m int整型
	 * @param n int整型
	 * @return ListNode类
	 */
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// write code here
		if (m == n) return head;
		int gap = n - m;
		int flag = m;
		m = m - 1;
		ListNode* pre = nullptr;//记录第m个节点的前一个节点
		ListNode* cur = nullptr;//记录第n个节点的后一个节点
		ListNode* begin = head;

		//循环找到第m个节点
		while (true) {
			if (m == 1) pre = begin;
			if (m == 0) break;
			--m;
			begin = begin->next;
		}
		ListNode* end = begin;
		//循环找到第n个节点
		while (true)
		{
			if (gap == 0) break;
			--gap;
			end = end->next;
		}
		cur = end->next;

		ListNode* temp1 = nullptr;//反转时用于记录前一个节点
		ListNode* temp2 = begin;//反转时用于往前走一步的节点
		ListNode* temp3 = begin;//用于记录住begin，使得反转后易于拼接链表
		if (cur != nullptr)//这里要做一个判断，否则会报段错误
		{
			while (temp2 != cur)
			{
				temp2 = temp2->next;
				begin->next = temp1;
				temp1 = begin;
				begin = temp2;
			}
		}
		else {
			while (temp2 != nullptr)
			{
				temp2 = temp2->next;
				begin->next = temp1;
				temp1 = begin;
				begin = temp2;
			}
		}

		/*
		这里要注意，如果m=1，则在第一个while循环里，pre是没有被重新赋值的，还是为nullptr，所以是没有next成员指针的
		需要做判断
		*/
		if (pre != nullptr)
			pre->next = temp1;//反转结束后，temp1指向的是end的位置
		else
			pre = temp1;
		temp3->next = temp2;//temp3记录的是begin的位置，反转结束后temp2指向cur的位置，即end后一位

		/*
		如下：m=2,n=4
		反转前：
		temp1=nullptr

			  temp3
			  temp2
		pre   begin         end    cur

		1       2      3     4      5     null

		反转后：
								   begin

				end                temp2
		pre    temp1         temp3  cur

		1        4      3      2     5    null

		所以要拼接起来的话，pre应该指向temp1，temp3应该指向temp2

		*/
		if (flag > 1)
			return head;
		else
			return pre;

	}
};

class ClassA
{
public:
	ClassA() { cout << "ClassA::ClassA()" << endl; }
	virtual ~ClassA() { cout << "ClassA::~ClassA()" << endl; }

	void func1() { cout << "ClassA::func1()" << endl; }
	void func2() { cout << "ClassA::func2()" << endl; }

	virtual void vfunc1() { cout << "ClassA::vfunc1()" << endl; }
	virtual void vfunc2() { cout << "ClassA::vfunc2()" << endl; }
private:
	int aData;
};

class ClassB : public ClassA
{
public:
	ClassB() { cout << "ClassB::ClassB()" << endl; }
	virtual ~ClassB() { cout << "ClassB::~ClassB()" << endl; }

	void func1() { cout << "ClassB::func1()" << endl; }
	virtual void vfunc1() { cout << "ClassB::vfunc1()" << endl; }
private:
	int bData;
};

class ClassC : public ClassB
{
public:
	ClassC() { cout << "ClassC::ClassC()" << endl; }
	virtual ~ClassC() { cout << "ClassC::~ClassC()" << endl; }

	void func2() { cout << "ClassC::func2()" << endl; }
	virtual void vfunc2() { cout << "ClassC::vfunc2()" << endl; }
private:
	int cData;
};





//int main() {
//	int N;
//	cin >> N;//链表个数
//	ListNode *head = new ListNode();
//	ListNode *cur = head;
//	for (int i = 0; i < N; i++) {
//		int num;
//		cin >> num;
//		ListNode* temp = new ListNode();
//		temp->val = num;
//		cur->next = temp;
//		cur = cur->next;
//	}
//	int start, end;
//	cin >> start;
//	cin >> end;
//	Solution s;
//
//	ListNode* res= s.reverseBetween(head->next,start,end);//如果在main函数返回，那main函数返回类型就要变成ListNode*
//
//	while (res != nullptr) {
//		if (res->next != nullptr) {
//			cout << res->val << " ";
//
//		}
//		else {
//			cout << res->val;
//		}
//		res = res->next;
//	}
//	delete head;
//	delete cur;
//
//	return 0;
//}