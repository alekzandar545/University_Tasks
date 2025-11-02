#pragma once

#ifndef _SORTED_STACK_INCLUDED__
#define _SORTED_STACK_INCLUDED__

#include "../SortedArray/SortedArray.hpp"

namespace fmi
{
namespace sdp
{

template <class DataType>
class SortedStack
{
public:
    void push(const DataType& elem) { array.add(elem); }
    DataType pop();
    const DataType& top() const;
    bool isEmpty() const { return array.isEmpty(); }
    size_t getSize() const { return array.getSize(); }
    void clear() { array.clear(); }

private:
    SortedArray<DataType> array; //using composition, cus lazy
};

} // namespace sdp
} // namespace fmi

#include "SortedStack.inl"

#endif // _SORTED_STACK_INCLUDED__
