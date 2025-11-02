#pragma once

namespace fmi
{
namespace sdp
{

template <class DataType>
DataType SortedStack<DataType>::pop()
{
    DataType temp = array[getSize() - 1];
    array.remove(getSize() - 1);
    return temp;
}

template <class DataType>
const DataType& SortedStack<DataType>::top() const
{
    return array[getSize() - 1];
}

} // namespace sdp
} // namespace fmi
