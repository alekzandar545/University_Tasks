#pragma once
#include "mathExpression.h"
#include <iostream>

class Sum : public MathExpression{
private:
    std::vector<MathExpression*> elements;
	class Iterator{
    private:
        MathExpression** pointer;
        friend class Sum;
        Iterator(MathExpression** ptr){pointer = ptr;};
    public:
        MathExpression* &operator *(){
            return *pointer;
        }
        MathExpression* const &operator *() const{
            return *pointer;
        }

        Iterator& operator ++(){
            ++pointer;
            return *this;
        }

        Iterator operator ++(int){
            Iterator old = *this;
            ++(*this);
            return old;
        }

        Iterator& operator --(){
            --pointer;
            return *this;
        }
        Iterator operator --(int){
            Iterator old = *this;
            --(*this);
            return old;
        }

        bool operator ==(const Iterator& other) const{
			return pointer == other.pointer;
		}
		bool operator !=(const Iterator& other) const{
			return !(*this == other);
		}
    };
    Iterator begin(){return Iterator((MathExpression**)(elements.data()));}
    Iterator end(){return Iterator((MathExpression**)(elements.data() + elements.size()));}
    MathExpression* Clone() const override{
        Sum* ptr = new Sum(*this);
        return ptr;
    }
public:
    //no big4 becuase std::vector is responsible for dynamic memory management
    double value() const override{
        double sum = 0;
        for(MathExpression* expr : elements){
            sum+=expr->value();
        }
        return sum;
    }
    void print() const override{
        std::cout << "sum(";
        for(MathExpression* expr : elements){
            std::cout << expr->value() << ',';//dint have time to remove that last comma
        }
        std::cout << ')';
    }
    void addExpression(MathExpression* exp){
        elements.push_back(exp);
    }
};