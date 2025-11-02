#pragma once

class Vector{
private:
    int* arr;
    size_t size;
    size_t capacity;
    void Resize(size_t size);
    void Clear();
public:
    Vector();
    Vector(size_t size);
    Vector(size_t size, int a);
    ~Vector();
    //functionality
    int At(size_t index) const;
    void SetAt(size_t index, int value);
    void RemoveAt(size_t index);
    void PushBack(int value);
    bool Empty() const;
    size_t Size() const;
    size_t Capacity() const;
};