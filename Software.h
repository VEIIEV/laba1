#pragma once
#include <iostream>
class Software 
{
private:
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
    
    Software& operator=(const Software& value1_1)
    {
        this->kopir(m_name, value1_1.m_name);
        this->kopir(m_type, value1_1.m_type);
        this->kopir(m_author, value1_1.m_author);
        return *this;
    }
    void kopir(char* first, char* second)
    {
        while (*second) {
            *first++ = *second++;
        }
        *first = '\0';
    }



    void set(char* namef, char* typef, char* authorf, int length);
    void get(const Software& firstf) const;
    void set_n(char* name, int length);
    void set_t(char* type, int length);
    void set_a(char* author, int length);

    void Printsoft() const;
};


class Math {
private:
    int m_value1;
    int m_value2;
public:
    Math() {
        m_value1 = 0;
        m_value2 = 5;
    }
    //если его закоментить, всё равно будет работать
    Math& operator=(const Math& value1_1)
    {
        m_value1 = value1_1.m_value1;
        m_value2 = value1_1.m_value2;
        std::cout << "выполнение перегруженого оператора присваивания"<<std::endl;
        return *this;
    };
    //
    friend bool operator==(const Math& value1_1, const Math& value1_2);
    friend bool operator!=(const Math& value1_1, const Math& value1_2);
    friend bool operator<(const Math & value1, const Math & value2);
    friend bool operator>(const Math& value1_1, const Math& value1_2);
    friend bool operator<=(const Math& value1_1, const Math& value1_2);
    friend bool operator>=(const Math& value1_1, const Math& value1_2);
    friend std::ostream& operator <<(std::ostream &out,const Math &value1_1);
    friend std::istream& operator >>(std::istream& in,  Math& value1_1);

};

void List();


/*
Stroka& Stroka::operator=(const Stroka& s)
{
    strcpy(str, s.str);
    return *this;
}

void Stroka::kopir(char *first, char *second)
{
    while (*second) {
        *first++ = *second++;
    }
    *first = '\0';


    Stroka& Stroka::operator=(const Stroka& s)
{
    this->kopir(str, s.str);
    return *this;
}
*/
