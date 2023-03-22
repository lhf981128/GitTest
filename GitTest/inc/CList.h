#pragma once
#ifndef CLIST_H
	#define CLIST_H

#include<iostream>
using namespace std;

template<typename T>
class ListNode {
	friend bool operator<(ListNode& a,ListNode& b);
public:
	//�вι���
	ListNode(T* elem):element(new T(*elem)),next(nullptr) {

	}

	//��������
	ListNode(const ListNode& lis){
		delete element;//���ͷű����ٵ��ڴ�

		if (lis.element != nullptr) {
			element = new T(*lis.element);
		}
		if (lis.next != nullptr) {
			next = new ListNode(*lis.next);
		}

	}

	//������ֵ
	ListNode& operator=(const ListNode& lis) {
		if (this != lis) {
			delete element;//���ͷű����ٵ��ڴ�
			if (lis.element != nullptr) {
				element = new T(*lis.element);
			}
			if (lis.next != nullptr) {
				next = new ListNode(*lis.next);
			}
		}
		return *this;
	}

	//�ƶ�����
	ListNode(ListNode&& lis)noexcept:element(lis.element), next(lis.next) {
		lis.element = nullptr;
		lis.next = nullptr;
	}

	//�ƶ���ֵ
	LsitNode& operator=(ListNode&& lis)noexcept {

		element = lis.element;
		next = lis.next;
		lis.element = nullptr;
		lis.next = nullptr;
	}


	T* Element() {
		return element;
	}
	ListNode*& Next() { return next; }

	~ListNode() {
		delete element;
		delete next;
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
	int Count()const {
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



	virtual ~CList() {
		//��Ҫѭ��ɾ���ڵ���ڴ�
		ListNode<T>* cur = head;
		while (cur != nullptr) {
			ListNode<T>* net = cur->Next();
			delete cur;
			cur = net;
		}
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
	CList(CList&& list) noexcept {
		head = list.head;
		dCount = list.dCount;
		list.head = nullptr;
		
	}
	CList& operator=(CList&& list) noexcept {
		head = list.head;
		dCount = list.dCount;
		list.head = nullptr;
	}

private:
	int dCount;
	ListNode<T>* head;
};

#endif // !CLIST_H