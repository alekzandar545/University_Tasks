#pragma once

namespace fmi::sdp {

template <typename T>
StaticStack<T>::StaticStack(size_t size)
    : data(new T[size])
    , tos(0)
    , size(size)
{}

template <typename T>
StaticStack<T>::StaticStack(const StaticStack& rhs)
    : data(new T[rhs.size])
    , tos(0)
    , size(rhs.size)
{
    while (tos < rhs.tos)
        push(rhs.data[tos]);
}

template <typename T>
StaticStack<T>& StaticStack<T>::operator=(const StaticStack& rhs)
{
    if (this != &rhs) {
        if (rhs.tos <= size) {
            tos = 0;
            while (tos < rhs.tos)
                push(rhs.data[tos]);
        }
        else {
            throw std::overflow_error("Not enough space");
        }
    }
    return *this;
}

template <typename T>
StaticStack<T>::~StaticStack() {
    delete[] data;
}

template <typename T>
void StaticStack<T>::push(const T& elem)
{
    if (!isFull()) data[tos++] = elem;
    else throw std::overflow_error("Stack is full");
}

template <typename T>
T StaticStack<T>::pop()
{
    if (!isEmpty()) return data[--tos];
    throw std::underflow_error("Empty stack");
}

template <typename T>
const T& StaticStack<T>::top() const
{
    if (!isEmpty()) return data[tos - 1];
    throw std::underflow_error("Empty stack");
}

template <typename T>
bool StaticStack<T>::isEmpty() const
{
    return tos == 0;
}

template <typename T>
bool StaticStack<T>::isFull() const
{
    return tos == size;
}

}   // namespace fmi::sdp