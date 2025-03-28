#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <exception>
#include <algorithm>

using namespace std;

class Bad_range : public exception
{
public:
	virtual const char* what() const noexcept override { return "Выход за пределы массива"; }
};

class Bad_length : public exception
{
public:
	virtual const char* what() const noexcept override { return "Неправильная длина массива"; }
};

class IntArray
{
private:
	int m_length{};
	int* m_data{};
public:
	IntArray() = default;
	IntArray(int length);
	~IntArray()
	{
		delete[] m_data;
		cout << "Destructed" << endl;
	}
	void earase();
	int& operator[](int index);
	void reallocate(int newLength);
	void resize(int newLength);
	IntArray(const IntArray& a);
	IntArray& operator=(const IntArray& a);
	void insertBefore(int value, int index);
	void remove(int index);

	void insertAtBegining(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }

	int getLength() const { return m_length; }
};

#endif
