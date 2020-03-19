#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "Software.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	//char a[5] = { "name" };
	char* a;
	a= new char[5] { '?', 'z', '?', '?' };
	List();
	Software firstl; //поумолчанию
	Software secondl = Software(a, a, a); //с переменными
	Software trel(a, a, a); // копирование
	/*int toggle=1;
	while (true)
	{
		cin >> toggle;
		switch (toggle)
		{
		case 1:	firstl.set(a, a, a, 5); List(); break;
		case 2: secondl.get(firstl); break;
		case 3: firstl.Printsoft(); break;
		case 4: secondl.Printsoft(); break;
		case 5: trel.Printsoft(); break;
		case 6: delete[]a;
			a = 0;
			return 0;
		default: List();
		}
	}
	*/
	Math first;
	Math second;
	if (first > second) { cout << "yes" << endl; }
	else { cout << "no" << endl; }
	cin >> first;
	cout << first;
	first = second; //оператор присваивания переопределён изначально, для любого класса
	cout << first;
	firstl.Printsoft(); //операция присваивания для массива данных типа char*
	secondl.Printsoft();
	secondl = firstl;
	secondl.Printsoft();
	delete[]a;
	return 0;
}

