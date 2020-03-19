#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Software.h"
using namespace std;

void Software::Printsoft() const
{
	cout << m_name << '\n' << m_type << '\n' << m_author << endl;
}


void Software::set_n(char* name)
{
	int i = 0;
	cout << "посимвольно введите имя" << endl;
	while (*name) {
		cin >> *(name);
		this->m_name[i] = *(name);
		*name++;
		i++;
	}
};

void Software::set_t(char* type)
{
	int i = 0;
	cout << "посимвольно введите тип" << endl;
	while (*type) {
		cin >> *(type);
		this->m_type[i] = *(type);
		*type++;
		i++;
	}
};

void Software::set_a(char* author)
{
	int i = 0;
	cout << "посимвольно введите автора" << endl;
	while (*author) {
		cin >> *(author);
		this->m_author[i] = *(author);
		*author++;
		i++;
	}
};


void Software::set(char* namef, char* typef, char* authorf) {
	set_n(namef);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	set_t(typef);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	set_a(authorf);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

char Software::get_name(int i) const { return m_name[i]; };

char Software::get_type(int i) const { return m_type[i]; };

char Software::get_author(int i)const { return m_author[i]; };


void Software::get(const Software& firstf) const
{
	for (int i = 0; i < 5 - 1; i++) {
		m_name[i] = firstf.get_name(i);
		m_type[i] = firstf.get_type(i);
		m_author[i] = firstf.get_author(i);
	}
}


//конструкторы
Software::Software()
{
	m_name = new char[5]{ '?','?','?','?' };
	m_type = new char[5]{ '?','?','?','?' };
	m_author = new char[5]{ '?','?','?','?' };
}


Software::Software(char name[], char* type, char* author)
{
	m_name = new char[5];
	for (int i = 0; i < 5; i++) {
		this->m_name[i] = name[i];
	}
	m_type = new char[5];
	for (int i = 0; i < 5; i++) {
		this->m_type[i] = type[i];
	}
	m_author = new char[5];
	for (int i = 0; i < 5; i++) {
		this->m_author[i] = author[i];
	}
};



Software::Software(const Software& Software)
{
	m_name = new char[sizeof(Software.m_name)+1];
	strcpy(m_name, Software.m_name);
	m_type = new char[sizeof(Software.m_type)+1];
	strcpy(m_type, Software.m_type);
	m_author = new char[sizeof(Software.m_author)+1];
	strcpy(m_author, Software.m_author);
};
//перегрузка операторов сравнения

bool operator ==(const Software& value1_1, const Software& value1_2)
{
	return (value1_1.m_name[0] == value1_2.m_name[0]
		&&
		value1_1.m_type[0] == value1_2.m_type[0]
		&&
		value1_1.m_author[0] == value1_2.m_author[0]);
};

bool operator !=(const Software& value1_1, const Software& value1_2)
{
	return !(value1_1 == value1_2);
};

bool operator<(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_name[0] < value1_2.m_name[0]);
};

bool operator>(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_name[0] > value1_2.m_name[0]);
};

bool operator<=(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_name[0] <= value1_2.m_name[0]);
};
bool operator>=(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_name[0] >= value1_2.m_name[0]);
};
//перегрузка операторов ввода ввывода
std::ostream& operator <<(std::ostream& out, const Software& value1_1)
{
	out << value1_1.m_name << ", " << value1_1.m_type << endl;
	return out;
};

std::istream& operator >>(std::istream& in, Software& value1_1)
{
	in >> value1_1.m_name;
	in >> value1_1.m_type;
	return in;
};

//перегрузка оператора присваивания
void Software::kopir(char* first, char* second)
{
	while (*second) {
		*first++ = *second++;
	}
	*first = '\0';
}

Software& Software::operator=(const Software& value1_1)
{
	this->kopir(m_name, value1_1.m_name);
	this->kopir(m_type, value1_1.m_type);
	this->kopir(m_author, value1_1.m_author);
	std::cout << "выполнение перегруженого оператора присваивания" << std::endl;
	return *this;
};
