#pragma once
#include "mathExpression.h"
#include <iostream>

class Min : public MathExpression{
private:
    MathExpression* elements[2];
    MathExpression* Clone() const override{
        Min* ptr = new Min(*this);
        return ptr;
    }
public:
    Min(MathExpression* exp1, MathExpression* exp2){
        elements[0] = exp1;
        elements[1] = exp2;
    }
    void setExpressions(MathExpression* exp1, MathExpression* exp2){
        elements[0] = exp1;
        elements[1] = exp2;
    }
    double value() const override{
        double v1 = elements[0]->value();
        double v2 = elements[1]->value();
        if(v1 < v2)
            return v1;
        return v2;
    }
    void print() const override{
        std::cout << "min(";
        elements[0]->print();
        std::cout << ',';
        elements[1]->print();
        std::cout << ')';
    }
};