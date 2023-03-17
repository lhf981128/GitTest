#pragma once
#include<iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	MyVector() {
		ReAlloc(2);
	}

	void PushBack(const T& value)//接收左值常引用的PushBack函数
	{
		if (m_Size >= m_Cap) {
			ReAlloc(m_Cap + m_Cap / 2);
		}
		m_Data[m_Size] = value;
		m_Size++;
	}

	void PushBack(T&& value) //接收右值引用的PushBack函数
	{
		if (m_Size >= m_Cap) {
			ReAlloc(m_Cap + m_Cap / 2);
		}
		m_Data[m_Size] = move(value);
		m_Size++;
	}
	template<typename...Args>
	T& EmplaceBack(Args&&...args) {
		if (m_Size >= m_Cap) {
			ReAlloc(m_Cap + m_Cap / 2);
		}
		//new(&m_Data[m_Size]) T(forward<Args>(args)...);//该处是定位new表达式
		m_Data[m_Size] = T(forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	const T& operator[](size_t index) const {
		if (index >= m_Size)
		{
			cout << "索引出界，无法操作" << endl;
		}
		return m_Data[index];
	}

	T& operator[](size_t index) {
		if (index >= m_Size)
		{
			cout << "索引出界，无法操作" << endl;
		}
		return m_Data[index];
	}

	size_t Size()const {
		return m_Size;
	}
	void PopBack() {
		if (m_Size > 0) {
			m_Size--;
			m_Data[m_Size].~T();
		}
	}
	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++) {
			m_Data[i].~T();
		}
		m_Size = 0;
	}
	~MyVector()
	{
		Clear();
		//delete[] m_Data;//直接delete会再次调用对象的析构函数，可能会导致重复析构堆内存,因为存储的对象里可能有指针数据成员
		::operator delete(m_Data, m_Cap * sizeof(T));
	}

private:
	T* m_Data=nullptr;
	size_t m_Size = 0;
	size_t m_Cap = 0;

	void ReAlloc(size_t newCap)
	{
		//1.新建一块内存
		//2.拷贝或者移动元素到新内存里
		//3.删除旧内存
		T* newBlock = (T*)::operator new(newCap*sizeof(T));

		if (newCap < m_Size) {
			m_Size = newCap;
		}
		for (size_t i = 0; i < m_Size; i++) {
			newBlock[i] =move(m_Data[i]);
		}
		for (size_t i = 0; i < m_Size; i++) {
			m_Data[i].~T();
		}
		::operator delete(m_Data, m_Cap * sizeof(T));
		m_Data = newBlock;
		m_Cap = newCap;
	}

};