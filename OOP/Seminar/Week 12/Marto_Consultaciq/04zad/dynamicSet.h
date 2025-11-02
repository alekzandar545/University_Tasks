#pragma once
#include "set.h"

class DynamicSet : Set{
public:
    bool member(int x) const override{
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x)
                return true;
        }
        return false;
    }
    void addElement(const int x){
        nums.push_back(x);
    }
};