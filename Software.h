#pragma once
#include <iostream>
class Software 
{
private:
    int m_value1;
    int m_value2;
    char* m_name;
    char* m_type;
    char* m_author;
public:
    Software() ;
    Software(char* name, char* type, char* author) ;
    Software(const Software& Software) ;

    ~Software()
    {
        delete[] m_name;
        delete[]  m_type;
        delete[] m_author;
    };
    
    void set(char* namef, char* typef, char* authorf);
    void get(const Software& firstf) const;
    void set_n(char* name);
    void set_t(char* type);
    void set_a(char* author);
    //перегрузка оператора присваивания 
    void kopir(char* first, char* second);
    Software& operator=(const Software& value1_1);
    //перегрузка операторов сравнения
    friend bool operator==(const Software& value1_1, const Software& value1_2);
    friend bool operator!=(const Software& value1_1, const Software& value1_2);
    friend bool operator<(const Software& value1, const Software& value2);
    friend bool operator>(const Software& value1_1, const Software& value1_2);
    friend bool operator<=(const Software& value1_1, const Software& value1_2);
    friend bool operator>=(const Software& value1_1, const Software& value1_2);
    // перегрузка операторов ввода ввывода
    friend std::ostream& operator <<(std::ostream& out, const Software& value1_1);
    friend std::istream& operator >>(std::istream& in, Software& value1_1);

    void Printsoft() const;
};

void List();
