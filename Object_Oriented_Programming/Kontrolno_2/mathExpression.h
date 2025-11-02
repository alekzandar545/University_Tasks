#pragma once
#include <vector>

class MathExpression{
private:

public:
    virtual double value() const = 0;
    virtual void print() const = 0;

    MathExpression() = default;
    ~MathExpression() = default;
    virtual MathExpression* Clone() const = 0;
};