#pragma once
#include "mathExpression.h"

template <typename T>
class Constant : public MathExpression{
protected: 
    T num;
    MathExpression* Clone() const override{
        Constant* ptr = new Constant(*this);
        return ptr;
    }
public:
    Constant(T value){
        num = value;
    }
    ~Constant() = default;

    //we use a random type but value of every expression is double
    double value() const override{
        return (double)num;
    }
    void print() const override{
        std::cout << (double)num;
    }
};