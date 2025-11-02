#pragma once

#ifndef _STATIC_STACK_HEADER_INCLUDED_
#define _STATIC_STACK_HEADER_INCLUDED_

#include <cstddef>
#include <stdexcept>

namespace fmi::sdp {

template <typename T>
class StaticStack
{
public:
    StaticStack(size_t size = 16);
    StaticStack(const StaticStack& rhs);

    // As the size is constant we have to ensure the destination stack can take all the elements!
    StaticStack& operator=(const StaticStack& rhs);

    ~StaticStack();

    void push(const T& elem);
    T pop();
    const T& top() const;
    bool isEmpty() const;
    bool isFull() const;

private:
    T* data;
    size_t tos;

    const size_t size;
};

}   // namespace fmi::sdp

#include "staticStack.inl"

#endif // _STATIC_STACK_HEADER_INCLUDED_