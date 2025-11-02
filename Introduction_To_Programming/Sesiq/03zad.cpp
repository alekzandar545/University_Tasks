#include <iostream>

struct Polynom{
    double* coefs;
    unsigned size;
};

void CheckSize(Polynom &a, Polynom &b){
    if(b.size > a.size){
        Polynom temp = a;
        a = b;
        b = temp;
    }
}

Polynom sum_poly(Polynom a, Polynom b){
    CheckSize(a, b);
    Polynom output = a;
    for (size_t i = 0; i < output.size; i++)
    {
        if(i >= a.size - b.size){
            output.coefs[i] += b.coefs[i -(a.size - b.size)];
        }
    }
    return output;
}

int main(){
    /*Задача 3. Да се дефинира подходяща структура Polynom, описваща полином с коефициенти от тип double от произволна степен.
    За така дефинираната функцията да се дефинира функция Polynom sum_poly(Polynom a, Polynom b), която по два такива полинома
    намира и връща тяхната сума.*/
    Polynom a;
    Polynom b;
    std::cin >> a.size >> b.size;
    a.coefs = new(std::nothrow) double[a.size];
    b.coefs = new(std::nothrow) double[b.size];
    if(!a.coefs || !b.coefs){
        std::cout << "Memory error!";
        return 0;
    }
    for (size_t i = 0; i < a.size; i++)
    {
        std::cin>> a.coefs[i];
    }
    for (size_t i = 0; i < b.size; i++)
    {
        std::cin >> b.coefs[i];
    }
    Polynom sum =sum_poly(a,b);
    for (size_t i = 0; i < sum.size - 1; i++)
    {
        //std::cout << "COCK";
        std::cout << sum.coefs[i]<<"x^"<<sum.size - i - 1<<" + ";
    }
    std::cout << sum.coefs[sum.size - 1];

    
    delete[] a.coefs;
    delete[] b.coefs;
    return 0;
}