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
	//�вι���
	ListNode(T* elem):element(elem),next(0) {

	}

	//��������


	//������ֵ


	//�ƶ�����

	//�ƶ���ֵ



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
	//������ĳ���ڵ�ĩβ���һ��Ԫ��
	void Append(ListNode<T>*& node, T* tElem) {
		if (node == nullptr) {
			dCount++;
			node = new ListNode<T>(tElem);
			return;
		}
		Append(node->Next(), tElem);
	}
	//��ͷ������һ��Ԫ��
	void Insert(T* tElem) {
		dCount++;
		if (head == nullptr) {
			head = new ListNode<T>(tElem);
			return;
		}
		ListNode<T>* temp = head;
		head = new ListNode<T>(tElem);
		head->Next() = temp;
	}
	//�Ƴ�һ��Ԫ��
	bool Remove(T* tElem) {
		if (head == nullptr) {
			return nullptr;
		}
		if (head->Element() == tElem)
		{
			ListNode<T>* tmp = head;
			head = head->Next();
			delete tmp;
			dCount--;
			return true;
		}
		ListNode<T>* tmp = head;
		ListNode<T>* lst = head->Next();
		while (lst != nullptr) {
			if (lst->Element() == tElem) {
				tmp->Next() = lst->Next();
				delete lst;
				dCount--;
				return true;
			}
			tmp = lst;
			lst = lst->Next();
		}

	}
	//��ȡԪ�ظ���
	int Count() {
		return dCount;
	}
	//����ͷ�ڵ�
	ListNode<T>* Head() {
		return head;
	}

	//��ȡ��һ��Ԫ��
	T* GetFirst() {
		return head != nullptr ? head->Element() : nullptr;
	}

	//��ȡ���һ��Ԫ��
	T* GetLast() {
		if (head != nullptr) {
			ListNode<T>* tmp = head;
			while (tmp->Next() != nullptr) {
				tmp = tmp->Next();
			}
			return tmp->Element();
		}
		return nullptr;
	}

	//��ȡ��ǰԪ�ص���һ��Ԫ��
	T* GetNext(T* tElem) {
		if (head == nullptr) {
			return nullptr;
		}
		if (tElem == nullptr) {
			return GetFirst();
		}
		if (head->Element() == tElem) {
			return head->Next() != nullptr ? head->Next()->Element() : nullptr;
		}
		ListNode<T>* tmp = head->Next();
		while (tmp != nullptr) {
			if (tmp->Element() == tElem) {
				return tmp->Next() != nullptr ? tmp->Next()->Element() : nullptr;
			}
			tmp = tmp->Next();
		}
		return nullptr;

	}

	//���ҵ�ǰԪ��
	T* Find(int(*Func)(T* tElem), int dValue) {
		try {
			T* Elem = nullptr;
			while (Elem = GetNext(Elem))
			{
				if (Func(Elem) == dValue) {
					return Elem;
				}
			}
		}
		catch (...) {

		}
		return nullptr;

	}



	~CList() {
		delete head;
	}
protected:
	CList(const CList& lst) {
		dCount = lst.dCount;
		if (lst.head == nullptr) {
			head=nullptr;
		}
		else
		{
			ListNode<T>* node = new ListNode<T>();
			node->Element() = lst.head->Element();
			node->Next() = nullptr;
			head = node;
			ListNode<T>* cur = lst.head->Next();
			ListNode<T>* cal = head;
			while (cur != nullptr) {
				cal->Next = new ListNode<T>();
				cal->Next()->Element() = cur->Element();
				cal->Next()->Next() = nullptr;
				cal = cal->Next();
				cur = cur->Next();
			}
		}


	}
	CList& operator=(const CList& list) {
		if (this != &list) {
			dCount = list.dCount;
			if (list.head == nullptr) {
				head=nullptr;
			}
			else
			{
				ListNode<T>* node = new ListNode<T>();
				node->Element() = lst.head->Element();
				node->Next() = nullptr;
				head = node;
				ListNode<T>* cur = lst.head->Next();
				ListNode<T>* cal = head;
				while (cur != nullptr) {
					cal->Next = new ListNode<T>();
					cal->Next()->Element() = cur->Element();
					cal->Next()->Next() = nullptr;
					cal = cal->Next();
					cur = cur->Next();
				}
			}
		}
		
		return *this;
	}
	CList(const CList&& list) noexcept {
		if (list.head == nullptr) {
			head=nullptr;
		}
		if (list->head != nullptr) {



			dCount = move(list.dCount);
			list.head = nullptr;
		}
		
	}
	CList& operator=(const CList&& list) noexcept {
		/*if (this != &list) {
			if (head->element != nullptr)
			{
				delete head->element;
			}
			if (list.head != nullptr) {
				head->element = new T(*list.head->element);
			}
			dCount = move(list.dCount);

			list.head = nullptr;
			return *this
		}*/
	}

private:
	int dCount;
	ListNode<T>* head;
};