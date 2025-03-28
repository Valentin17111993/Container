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
	cout << "����� �������: " << m.getLength() << ". ������� ��������:" << endl;
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
	cout << "����� ������� resize(" << resize << "). " << " ������ ������� ������� �� " << resize << " ���������." << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.insertBefore(inBef, inBefIndex);
	cout << "����� ������� insertBefore(" << inBef << ", " << inBefIndex << "). ������� ����� " << inBef << " ����� �������� � �������� " << inBefIndex << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.remove(removeIndex);
	cout << "����� ������� remove(" << removeIndex << "). �������� �������� � �������� " << removeIndex << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
	m.insertAtEnd(insertEnd);
	m.insertAtBegining(insertBegin);
	cout << "����� ������� insertAtEnd(" << insertEnd << ") � insertAtBegining(" << insertBegin << "). ������� ����� " << insertBegin << " � " << insertEnd << " � ������ � ����� ������� ��������������." << endl;
	for (int i = 0; i < m.getLength(); i++)
	{
		cout << m[i] << " ";
	}
	return 0;
}