#include <iostream>
#include <exception>
#include "IntArray.h"
#include <algorithm>

using namespace std;

int main()
{
	int L = 10;
	int resize = 8;
	int inBef = 20;
	int inBefIndex = 5;
	int removeIndex = 6;
	int insertEnd = 25;
	int insertBegin = 17;
	setlocale(LC_ALL, "");
	IntArray m(L);
	cout << "Длина массива: " << m.getLength() << ". Введите элементы:" << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cin >> m[i];
	}
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.resize(resize);
	cout << "После функции resize(" << resize << "). " << " Размер массива изменен до " << resize << " элементов." << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.insertBefore(inBef, inBefIndex);
	cout << "После функции insertBefore(" << inBef << ", " << inBefIndex << "). Вставка числа " << inBef << " перед элеметом с индексом " << inBefIndex << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.remove(removeIndex);
	cout << "После функции remove(" << removeIndex << "). Удаление элемента с индексом " << removeIndex << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.insertAtEnd(insertEnd);
	m.insertAtBegining(insertBegin);
	cout << "После функций insertAtEnd(" << insertEnd << ") и insertAtBegining(" << insertBegin << "). Вставка чисел " << insertBegin << " и " << insertEnd << " в начало и конец массива соответственно." << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	return 0;
}