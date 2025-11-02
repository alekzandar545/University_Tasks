#pragma once
#include <string>
#include "employee.h"

class Programmer : Employee{
protected:
    bool knowsC;
    bool knowsCSh;
public:
    Programmer(std::string name, unsigned exp, bool C, bool CSh){
        this->name = name;
        this->exp = exp;
        this->knowsC = C;
        this->knowsCSh = CSh;
    }
    Employee* clone() const override{
        Programmer* res = new Programmer(*this);
        return (Employee*)res;
    }
    void Print() const override{
        std::cout << name << ' ' << exp << ' ' << knowsC << ' ' << knowsCSh;
    }
};