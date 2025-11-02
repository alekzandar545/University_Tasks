#pragma once
#include <stdexcept>
#include "vector.hpp"

template <class DataType>
class KHeap {
private:
    MyVector<DataType> data;
    unsigned k; // children per node

    unsigned getParent(unsigned index) const {return (index - 1) / k;}
    unsigned getFirstChild(unsigned index) const {return k * index + 1;}
    unsigned getLastChild(unsigned index) const {return k * index + k;}

    unsigned minChild(unsigned index, unsigned last) const {
        unsigned firstChild = getFirstChild(index);
        unsigned minChildIdx = firstChild;

        for (unsigned i = 1; i < k; ++i) {
            unsigned currentChild = firstChild + i;
            if (currentChild <= last && data[currentChild] < data[minChildIdx]) {
                minChildIdx = currentChild;
            }
        }

        return minChildIdx;
    }

    void siftUp(unsigned index) {
        if (index == 0) return;

        unsigned curr = index;
        unsigned parent = getParent(index);

        while (curr > 0 && data[curr] < data[parent]) {
            std::swap(data[curr], data[parent]);
            curr = parent;
            parent = getParent(curr);
        }
    }

    void siftDown(unsigned index, unsigned last) {
        if (data.empty() || index > last) return;

        unsigned curr = index;
        unsigned firstChild = getFirstChild(curr);

        while (firstChild <= last) {
            unsigned minChildIdx = minChild(curr, last);
            if (data[curr] < data[minChildIdx]) break;

            std::swap(data[curr], data[minChildIdx]);
            curr = minChildIdx;
            firstChild = getFirstChild(curr);
        }
    }

    void heapify() {
        for (int i = data.size() / k - 1; i >= 0; i--)
            siftDown(i, data.size() - 1);
    }

public:
    KHeap(unsigned kValue) : k(kValue) {
        if (kValue < 2)
            throw std::invalid_argument("K must be at least 2");
    }

    KHeap(unsigned kValue, const MyVector<DataType>& arr) : data(arr), k(kValue) {
        if (kValue < 2)
            throw std::invalid_argument("K must be at least 2 for a valid K-heap.");
        heapify();
    }

    KHeap(const KHeap& other) : data(other.data), k(other.k){}

    KHeap(KHeap&& other) noexcept{
        data = std::move(other.data);
        k = std::move(other.k);
    }

    KHeap& operator=(const KHeap& other){
        if(this != &other){
            data = other.data;
            k = other.k;
        }
        return *this;
    }

    KHeap& operator=(KHeap&& other) noexcept{
        if(this != &other){
            data = std::move(other.data);
            k = std::move(other.k);
        }
        return *this;
    }

    void insert(DataType val) {
        data.push_back(val);
        siftUp(data.size() - 1);
    }

    DataType extract() {
        if (data.empty()) 
            throw std::underflow_error("Empty data!");

        DataType res = data[0];
        std::swap(data[0], data.back());
        data.pop_back();
        if (!data.empty())
            siftDown(0, data.size() - 1);
        return res;
    }

    DataType top() const {
        if (data.empty())
            throw std::underflow_error("Empty data!");
        return data[0];
    }

    bool empty() const {return data.empty();}

};
