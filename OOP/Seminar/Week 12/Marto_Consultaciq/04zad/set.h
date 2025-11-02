#pragma once
#include <vector>

class Set{
protected:
    std::vector<int> nums;
public:
    virtual bool member(int x) const = 0;
    unsigned getSize() const{return nums.size();}
    int getElement(unsigned index) const{return nums[index];}
};