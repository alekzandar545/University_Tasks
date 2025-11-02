#pragma once
#include <string>

class Employee{
protected:
    std::string name;
    unsigned exp;
public:
    virtual ~Employee() = default;
    virtual Employee* clone() const = 0;
    virtual void Print() const = 0;
};