#include <iostream>
#include "Software.h"
using namespace std;

void List()
{
	cout << "1)ввести значение в 1 конст\n2)скопировать значения из 1 конст во второй\n" <<
		"3)показать конст по ум\n4)показать конст с парам\n" <<
		"5)показать конст коп\n" << "6)закрыть программу\n" << endl;
}
void Software::Printsoft() const
{
	cout << m_name << '\n' << m_type << '\n' << m_author << endl;
}

void Software::set_n(char* name, int length)
{
	cout << "посимвольно введите имя" << endl;
	for (int i = 0; i < length-1; i++) {
		cin >> name[i];
		static_cast<char>(name[i]);
		this->m_name[i] = name[i];
	}
	this->m_name[length - 1] = '\n';
};

void Software::set_t(char* type, int length)
{
	cout << "посимвольно введите тип" << endl;
	for (int i = 0; i < length-1; i++) {
		cin >> type[i];
		this->m_type[i] = type[i];
	}
	this->m_name[length - 1] = '\n';
};

void Software::set_a(char* author, int length)
{
	cout << "посимвольно введите автора" << endl;
	for (int i = 0; i < length-1; i++) {
		cin >> author[i];
		this->m_author[i] = author[i];
	}
	this->m_name[length - 1] = '\n';
};


void Software::set( char* namef,char* typef,char* authorf, int length) {
	set_n(namef,length);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	set_t(typef, length);
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	set_a(authorf, length);
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//int getx() { return x; };


void Software::get(const Software &firstf) const  
{
	for (int i = 0; i < 5 - 1; i++) {
		m_name[i] = firstf.m_name[i];
		m_type[i] = firstf.m_type[i];
		m_author[i] = firstf.m_author[i];
	}
}



Software::Software()
{
	m_name = new char[5]{ '?','?','?','?' };
	m_type = new char[5]{ '?','?','?','?'};
	m_author = new char[5]{ '?','?','?','?' };
}


Software::Software(char name[], char* type, char* author) 
{
	m_name = new char[5];
	for (int i = 0; i < 5; i++) {
		this->m_name[i] = name[i];
	}
	m_type = new char[5];
	for (int i = 0; i < 5 ; i++) {
		this->m_type[i] = type[i];
	}
	m_author = new char[5];
	for (int i = 0; i < 5 ; i++) {
		this->m_author[i] = author[i];
	}
};

Software::Software(const Software& Software)
{
	m_name = Software.m_name;
	m_type = Software.m_type;
	m_author=Software.m_author;
};
//перегрузка операторов сравнения

bool operator ==(const Math &value1_1, const Math &value1_2)
{
	return (value1_1.m_value1 == value1_2.m_value1
							  &&
			value1_1.m_value2 == value1_2.m_value2);
};

bool operator !=(const Math& value1_1, const Math& value1_2)
{
	return !(value1_1==value1_2);
};

bool operator<(const Math& value1_1, const Math& value1_2)
{

	return (value1_1.m_value1 < value1_2.m_value1);
};

bool operator>(const Math& value1_1, const Math& value1_2)
{

	return (value1_1.m_value1 > value1_2.m_value1);
};

bool operator<=(const Math& value1_1, const Math& value1_2)
{

	return (value1_1.m_value1 <= value1_2.m_value1);
};
bool operator>=(const Math& value1_1, const Math& value1_2)
{

	return (value1_1.m_value1 >= value1_2.m_value1);
};

std::ostream& operator <<(std::ostream& out, const Math& value1_1)
{
	out << value1_1.m_value1 << ", " << value1_1.m_value2 << endl;
	return out;
};

std::istream& operator >>(std::istream& in, Math& value1_1)
{
	in >> value1_1.m_value1;
	in >> value1_1.m_value2;
	return in;
};
