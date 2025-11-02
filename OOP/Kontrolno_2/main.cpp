#include <iostream>
#include "const.h"
#include "sum.h"
#include "min.h"

int main(){
    Constant<double>* c1 = new Constant<double>(5);
    Constant<double>* c2 = new Constant<double>(6);
    Constant<double>* c3 = new Constant<double>(7);
    Sum* sum = new Sum();
    sum->addExpression(c1);
    sum->addExpression(c2);
    sum->addExpression(c3);
    Min* min = new Min(sum,c1);
    min->print();
    std::cout << sum->value();
    sum->print();
}
