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


void Software::set( char* namef,char* typef,char* authorf) {
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



void Software::get(const Software &firstf) const  
{
	for (int i = 0; i < 5 - 1; i++) {
		m_name[i] = firstf.m_name[i];
		m_type[i] = firstf.m_type[i];
		m_author[i] = firstf.m_author[i];
	}
}


//конструкторы
Software::Software()
{
	m_value1 = 0;
	m_value2 = 5;
	m_name = new char[5]{ '?','?','?','?' };
	m_type = new char[5]{ '?','?','?','?'};
	m_author = new char[5]{ '?','?','?','?' };
}


Software::Software(char name[], char* type, char* author) 
{
	m_value1 = 0;
	m_value2 = 5;
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
	m_value1 = 0;
	m_value2 = 5;
	m_name = Software.m_name;
	m_type = Software.m_type;
	m_author=Software.m_author;
};
//перегрузка операторов сравнения

bool operator ==(const Software&value1_1, const Software&value1_2)
{
	return (value1_1.m_value1 == value1_2.m_value1
							  &&
			value1_1.m_value2 == value1_2.m_value2);
};

bool operator !=(const Software& value1_1, const Software& value1_2)
{
	return !(value1_1==value1_2);
};

bool operator<(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_value1 < value1_2.m_value1);
};

bool operator>(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_value1 > value1_2.m_value1);
};

bool operator<=(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_value1 <= value1_2.m_value1);
};
bool operator>=(const Software& value1_1, const Software& value1_2)
{

	return (value1_1.m_value1 >= value1_2.m_value1);
};
//перегрузка операторов ввода ввывода
std::ostream& operator <<(std::ostream& out, const Software& value1_1)
{
	out << value1_1.m_value1 << ", " << value1_1.m_value2 << endl;
	return out;
};

std::istream& operator >>(std::istream& in, Software& value1_1)
{
	in >> value1_1.m_value1;
	in >> value1_1.m_value2;
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
        m_value1 = value1_1.m_value1;
        m_value2 = value1_1.m_value2;
        this->kopir(m_name, value1_1.m_name);
        this->kopir(m_type, value1_1.m_type);
        this->kopir(m_author, value1_1.m_author);
        std::cout << "выполнение перегруженого оператора присваивания" << std::endl;
        return *this;
    };
