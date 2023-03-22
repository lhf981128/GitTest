#pragma once
#ifndef CSTACK_H
#define CSTACK_H


#include"inc/CList.h"

template<typename T>

class CStack :CList<T> {
public:
	CStack() :CList<T>() {

	}
	CStack(T* tElem) :CList<T>(tElem) {

	}
	virtual ~CStack() {

	}
	virtual void Push(T* Elem) {
		Insert(Elem);
	}
	virtual void Pop() {
		T* temp = CList<T>::GetFirst();  // NOLINT(clang-diagnostic-microsoft-template)
		Remove(temp);
	}
	int Size()
	{
		return CList<T>::Count();
	}
	virtual T* Peek() {
		return CList<T>::GetFirst();
	}

};
#endif // !CSTACK_H