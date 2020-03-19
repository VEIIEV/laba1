#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "Software.h"

using namespace std;
void List();

int main()
{
	setlocale(LC_ALL, "Russian");

	char a[5]{ '?', 'z', '?', '?' };
	List();
	Software firstl; //поумолчанию
	Software secondl = Software(a, a, a); //с переменными
	Software trel(firstl); // копирование
	int toggle = 1;
	int z = 1; while (z == 1)
	{
		cin >> toggle;
		switch (toggle)
		{
		case 1:	firstl.set(a, a, a); List(); break;
		case 2: secondl.get(firstl); break;
		case 3: firstl.Printsoft(); break;
		case 4: secondl.Printsoft(); break;
		case 5: trel.Printsoft(); break;
		case 6:
			z = 0;
			break;
		default: List();
		}
	}
	//////////////////////////////////////////
	Software first;
	Software second;
	if (first > second) { cout << "yes" << endl; }
	else if (first == second) { cout << "=" << endl; }
	else { cout << "no" << endl; }
	cin >> first; //ввод в класс
	cout << first; //вывод из класса
	first = second; //оператор присваивания переопределён изначально, для любого класса
	cout << first;
	firstl.Printsoft();
	secondl.Printsoft();
	secondl = firstl;//операция присваивания для массива данных типа char*
	secondl.Printsoft();
	return 0;
}


void List()
{
	cout << "1)ввести значение в 1 конст\n2)скопировать значения из 1 конст во второй\n" <<
		"3)показать конст по ум\n4)показать конст с парам\n" <<
		"5)показать конст коп\n" << "6)закрыть программу\n" << endl;
};


