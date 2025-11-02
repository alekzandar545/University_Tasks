#pragma once

template <typename T>
class Sequence{
private:
    unsigned k;
    T* arr;
    void copy(const Sequence& other){
        k=other.k;
        arr = new T[k];
        for (size_t i = 0; i < k; i++)
        {
            arr[i] = other.arr[i];
        }   
    }
    class Iterator{
    private:
        T* ptr;
        friend class Sequence;
    public:
        bool operator!=(const Iterator& other){return ptr != other.ptr;}
        bool operator==(const Iterator& other){return ptr == other.ptr;}
        Iterator& operator++(){
            ptr++;
            return *this;
        }
        Iterator& operator+=(unsigned num){
            ptr+=num;
            return *this;
        }
        T operator*(){
            return *ptr;
        }
    };
public:
    Iterator begin(){
        Iterator res;
        res.ptr = arr;
        return res;
    }
    Iterator end(){
        Iterator res;
        res.ptr = arr + k;
        return res;
    }
    Sequence(T a0, unsigned k, T(*next)(T)){
        this->k = k;
        arr = new T[k];
        arr[0] = a0;
        for (unsigned i = 1; i < k; i++)
        {
            arr[i] = next(arr[i-1]);
        }
    }
    Sequence(const Sequence& other){
        copy(other);
    }
    Sequence& operator=(const Sequence& other){
        if(this != other){
            delete[] arr;
            copy(other);
        }
        return *this;
    }
    ~Sequence(){
        delete[] arr;
    }
    T operator[](unsigned index){
        return arr[index];
    }
};