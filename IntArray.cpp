#include <iostream>
#include <exception>
#include "IntArray.h"
#include <algorithm>

using namespace std;

void NoBadLength()
{
	cout << "Длина массива должна быть положительной и ненулевой" << endl;
}

IntArray::IntArray(int length) : m_length{ length }
{
	if (length < 0)
	{
		try
		{
			throw Bad_length();
		}
		catch(Bad_length &bl)
		{
			cout << bl.what() << endl;
			atexit(NoBadLength);
			exit(5);
		}
	}
	if (length > 0)
	{
		m_data = new int[length] {};
	}
}

void IntArray::earase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntArray :: operator[] (int index)
{
	if (index < 0 || index >= m_length)
	{
		try
		{
			throw Bad_range();
		}
		catch(exception &br)
		{
			cout << br.what() << endl;
			exit(5);
		}
	}
	return m_data[index];

}

void IntArray::reallocate(int newLength)
{
	earase();
	if (newLength <= 0)
		return;

	m_data = new int[newLength];
	m_length = newLength;
}

void IntArray :: resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength < 0)
	{
		earase();
		return;
	}

	int* data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
		std::copy_n(m_data, elementsToCopy, data);
	}
	delete[] m_data;
	m_data = data;
	m_length = newLength;
}

IntArray::IntArray(const IntArray& a) : m_length(a.getLength())
{
	std::copy_n(a.m_data, m_length, m_data);
}

IntArray& IntArray :: operator=(const IntArray& a)
{
	if (&a == this)
		return *this;

	reallocate(a.getLength());
	std::copy_n(a.m_data, m_length, m_data);

	return *this;
}

void IntArray::insertBefore(int value, int index)
{
	if (index < 0 || index > m_length)
	{
		try
		{
			throw Bad_range();
		}
		catch (Bad_range& br)
		{
			cout << br.what() << " Неверный индекс. Индекс больше длины массива." << endl;
			exit(5);
		}
	}
	int* data{ new int[m_length + 1] };
	std::copy_n(m_data, index, data);
	data[index] = value;
	std::copy_n(m_data + index, m_length - index, data + index + 1);
	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index)
{
	if (index < 0 || index >= m_length)
	{
		try
		{
			throw Bad_range();
		}
		catch (Bad_range& br)
		{
			cout << br.what() << endl;
			exit(5);
		}
	}
	if (m_length == 1)
	{
		earase();
		return;
	}
	int* data{ new int[m_length - 1] };
	std::copy_n(m_data, index, data);
	std::copy_n(m_data + index + 1, m_length - index - 1, data + index);
	delete[] m_data;
	m_data = data;
	--m_length;
}