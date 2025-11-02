#pragma once
#include "set.h"
#include "dynamicSet.h"
#include "evenNumbers.h"

class SetUnion : Set{
private:

public:
    bool member(int x) const override{
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x);
        }
        return false;
    }
    bool contains(int x) const{
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x)
                return true;
        }
        return false;
        
    }
    void addSet(Set* set){
        for (size_t i = 0; i < set->getSize(); i++)
        {
            if(!this->contains(set->getElement(i)))
                nums.push_back(set->getElement(i));
        }
    }
};