#pragma once
#ifndef CLIST_H
	#define CLIST_H
#endif // !CLIST_H
#include<iostream>
using namespace std;

template<typename T>
class ListNode {
	friend bool operator<(ListNode& a,ListNode& b);
public:
	ListNode(T* elem):element(elem),next(0) {

	}
	T* Element() {
		return element;
	}
	ListNode*& Next() { return next; }
	~ListNode() {
	}


private:
	T* element;
	ListNode* next;
};

template<typename T>

bool operator<(ListNode<T>& a, ListNode<T>& b) {
	return *(a.element)<*(b.element)
}


template<typename T>

class CList {
public:
	CList(){}
	CList(T elem):dCount(1),head(new ListNode<T>(elem)) {

	}
	//在链表末尾添加一个元素
	void Append(ListNode<T>*& node, T* tElem) {
		if (node == nullptr) {
			dCount++;
			node = new ListNode<T>(tElem);

		}
	}

	~CList() {
		delete head;
	}
protected:
	CList(const CList& list) {
		if (head->element != nullptr)
		{
			delete head->element;
		}
		if (list.head != nullptr) {
			head->element = new T(*list.head->element);
		}
		dCount = list.dCount;
	}
	CList& operator=(const CList& list) {
		if (this != &list) {
			if (head->element != nullptr)
			{
				delete head->element;
			}
			if (list.head != nullptr) {
				head->element = new T(*list.head->element);
			}
			dCount = list.dCount;
		}
		
		return *this;
	}
	CList(const CList&& list) noexcept {
		if (head->element != nullptr)
		{
			delete head->element;
		}
		if (list.head != nullptr) {
			head->element = new T(*list.head->element);
		}
		dCount = move(list.dCount);
		list.head = nullptr;
	}
	CList& operator=(const CList&& list) noexcept {
		if (this != &list) {
			if (head->element != nullptr)
			{
				delete head->element;
			}
			if (list.head != nullptr) {
				head->element = new T(*list.head->element);
			}
			dCount = move(list.dCount);

			list.head = nullptr;
		}
	}

private:
	int dCount;
	ListNode<T>* head;
};