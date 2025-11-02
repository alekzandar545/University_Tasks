#pragma once
#include <iostream>
#include <stdexcept>

template <typename DataType>
class Queue {
    DataType* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    size_t whereToPut = 0;
    size_t whereToGet = 0;

    void free() {
        delete[] data;
        data = nullptr;
        size = capacity = whereToPut = whereToGet = 0;
    }

    void copyPrimitiveData(const Queue& other) noexcept {
        size = other.size;
        capacity = other.capacity;
        whereToPut = other.whereToPut;
        whereToGet = other.whereToGet;
    }

    void copyFrom(const Queue& other) {
        data = new DataType[other.capacity];
        for (size_t i = 0; i < other.size; i++) {
            data[i] = other.data[(other.whereToGet + i) % other.capacity];
        }
        copyPrimitiveData(other);
    }

    void moveFrom(Queue&& other) noexcept {
        data = other.data;
        copyPrimitiveData(other);

        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
        other.whereToGet = 0;
        other.whereToPut = 0;
    }

    void resize(size_t newCapacity) {
        if (newCapacity <= size) {
            throw std::logic_error("New capacity must be greater than current size.");
        }

        DataType* temp = new DataType[newCapacity];
        for (size_t i = 0; i < size; i++) {
            temp[i] = data[(whereToGet + i) % capacity];
        }

        delete[] data;
        data = temp;
        capacity = newCapacity;
        whereToGet = 0;
        whereToPut = size;
    }

    void ensureCapacity() {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
    }

public:
    Queue(size_t initialCapacity = 5) 
        : data(new DataType[initialCapacity]), size(0), capacity(initialCapacity), whereToPut(0), whereToGet(0) {}

    ~Queue() {
        free();
    }

    Queue(const Queue& other) {
        copyFrom(other);
    }

    Queue(Queue&& other) noexcept {
        moveFrom(std::move(other));
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    Queue& operator=(Queue&& other) noexcept {
        if (this != &other) {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    void push(const DataType& element) {
        ensureCapacity();
        data[whereToPut] = element;
        whereToPut = (whereToPut + 1) % capacity;
        size++;
    }

    DataType pop() {
        if (empty()) {
            throw std::underflow_error("Queue is empty.");
        }
        DataType res = data[whereToGet];
        whereToGet = (whereToGet + 1) % capacity;
        size--;
        return res;
    }

    const DataType& front() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty.");
        }
        return data[whereToGet];
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};
