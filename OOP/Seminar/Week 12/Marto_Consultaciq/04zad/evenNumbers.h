#pragma once
#include "set.h"

class EvenNumbers : Set{
public:
    EvenNumbers() : Set(){ //questionable
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 != 0)
                nums.erase(nums.begin() + i);
        }
    }
    bool member(int x) const override{
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x && x%2 == 0)
                return true;
        }
        return false;
    }
};