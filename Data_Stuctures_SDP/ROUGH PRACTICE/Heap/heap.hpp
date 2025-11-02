#pragma once
#include <vector>
#include <stdexcept>

template <class DataType>
class Heap{ //will be doing a minHeap here
private:
    std::vector<DataType> data;
    static unsigned getParent(unsigned index) {return index/2;}
    static unsigned getLeftChild(unsigned index) {return 2*index + 1;}
    static unsigned getRighthChild(unsigned index) {return 2*index + 2;}
    static unsigned minChild(unsigned index, const std::vector<DataType>& data){
        unsigned leftChild = getLeftChild(index);
        unsigned rightChild = getRighthChild(index);
        if(rightChild >= data.size())//how are we sure the left child is also not going bonkers? Its okay i think...
            return leftChild; //yup, here all out of bounds exceptions are handled cus it doesnt matter what leftChild is
        return data[leftChild] < data[rightChild] ? leftChild : rightChild;
    }
    unsigned minChild(unsigned index) const {return minChild(index,data);}
    
    void siftUp(unsigned index){
        if(data.empty() || index == 0)
            return;
        unsigned curr = index;
        unsigned parent = getParent(index);
        while(curr > 0 && data[curr] < data[parent]){//what if we want curr to go all the way up to 0? if parent cannot be 0, then how do we swap?
            std::swap(data[curr], data[parent]);
            curr = parent;
            parent = getParent(curr);
        }
    }
    void siftDown(unsigned index, unsigned last){//same as soak
        if(data.empty() || index > last) //handling the case for empty heaps
            return;
        unsigned curr = index;
        unsigned child = minChild(index);
        while(child <= last && data[curr] > data[child]){
            std::swap(data[curr], data[child]);
            curr = child;
            child = minChild(curr);
        }
    }
    void heapify(){//same as buildHeap
        for (int i = data.size()/2-1; i >= 0; i--)
            siftDown(i, data.size()-1);
    } 


    //helpers for heap sort ;3
    static void siftDown(std::vector<DataType>& arr, unsigned index, unsigned last) {
        unsigned curr = index;
        while (true) {
            unsigned child;
            unsigned leftChild = getLeftChild(curr);
            unsigned rightChild = getRighthChild(curr);
            if(leftChild > last)
                break;
            else if (rightChild > last)
                child = leftChild;
            else 
                child = arr[leftChild] < arr[rightChild] ? leftChild : rightChild;
            
            if (arr[curr] <= arr[child]) break;
            std::swap(arr[curr], arr[child]);
            curr = child;
        }
    }

    static void heapify(std::vector<DataType>& arr) {
        for (int i = (arr.size()/2)-1; i >= 0; i--) {
            siftDown(arr, i, arr.size() - 1);
        }
    }
public:
    Heap() = default;
    ~Heap() = default;
    Heap(const std::vector<DataType>& arr) : data(arr) {heapify();}
    Heap(const Heap& other) :data(other.data){}
    Heap(Heap&& other) noexcept{std::swap(data,other.data);}
    Heap& operator=(const Heap& other){
        if(*this != other)
            data = other.data;
        return *this;
    }
    Heap& operator=(Heap&& other) noexcept{
        if(*this != other)
            data = other.data;
        return *this;
    }
    void insert(DataType val){
        data.push_back(val);
        siftUp(data.size() - 1);
    }
    
    DataType extract(){//extracts extremal element
        if(data.empty())
            throw std::underflow_error("Empty data!");
        DataType res = data[0];
        std::swap(data[0], data.back());
        data.pop_back();
        if(!data.empty())
            siftDown(0, data.size()-1);        
        return res;
    }

    DataType top()const{
        if(data.empty())
            throw std::underflow_error("Empty data!");
        return data[0];
    } //shows top element
    
    bool empty()const{return data.empty();}

    static void heapSort(std::vector<DataType>& arr) {
        heapify(arr); // Build heap
        for (int i = arr.size() - 1; i > 0; i--) {
            std::swap(arr[i], arr[0]); // Move min to the end
            siftDown(arr, 0, i-1);  // Restore heap property
        }
    }
};