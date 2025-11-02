#pragma once
#include <string>
#include "employee.h"

class Manager : Employee{
protected:
    unsigned peopleManaged;
public:
    Manager(std::string name, unsigned exp, unsigned peopleManaged){
        this->name = name;
        this->exp = exp;
        this->peopleManaged = peopleManaged;
    }
    Employee* clone() const override{
        Manager* res = new Manager(*this);
        return (Employee*)res;
    }
    void Print() const override{
        std::cout << name << ' ' << exp << ' ' << peopleManaged;
    }
};