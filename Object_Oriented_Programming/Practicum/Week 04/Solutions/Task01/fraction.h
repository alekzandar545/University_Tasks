#pragma once

class Fraction{
private:
    int numerator;
    int denominator;
public:
    //getters
    int getNumerator() const;
    int getDenomenator() const;
    //setters
    void setNumerator(int const value);
    void setDenomerator(int const value);
    //reduce
    void reduce();
    //methods
    double value() const;
    void add(const Fraction &other);
    void subtract(const Fraction &other);
    void divide(const Fraction &other);
    void mult(const Fraction &other);
    void reverse();
    bool compare(const Fraction &other) const;
    void print() const;
};