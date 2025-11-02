#pragma once
#include <iostream>
#include <stdexcept>

template <typename P>
class Queue {
public:
    // Default constructor
    Queue() : capacity(10), head(0), tail(0) {
        data = new(std::nothrow) P[capacity];
        if (!data)
            throw std::invalid_argument("Memory error!");
    }

    // Parameterized constructor
    Queue(unsigned capacity) : capacity(capacity), head(0), tail(0) {
        data = new(std::nothrow) P[capacity];
        if (!data)
            throw std::invalid_argument("Memory error!");
    }

    // Destructor
    ~Queue() {
        free();
    }

    // Copy constructor
    Queue(const Queue& other) {
        copy(other);
    }

    // Move constructor
    Queue(Queue&& other) noexcept : data(nullptr), capacity(0), head(0), tail(0) {
        move(std::move(other));
    }

    // Copy assignment operator
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            free();
            copy(other);
        }
        return *this;
    }

    // Move assignment operator
    Queue& operator=(Queue&& other) noexcept {
        if (this != &other) {
            free();
            move(std::move(other));
        }
        return *this;
    }

    // Resize function
    void Resize() {
        unsigned size = tail - head;
        if (size < capacity / 2) {
            // Move elements to the beginning of the array
            for (size_t i = 0; i < size; i++) {
                data[i] = std::move(data[head + i]);
            }
            head = 0;
            tail = size;
        } else { // Expand and reallocate
            capacity *= 2;
            P* newData = new(std::nothrow) P[capacity];
            if (!newData)
                throw std::invalid_argument("Memory error!");

            for (size_t i = 0; i < size; i++) {
                newData[i] = std::move(data[head + i]);
            }
            delete[] data;
            data = newData;
            head = 0;
            tail = size;
        }
    }

    // Push function
    void Push(const P& el) {
        if (tail == capacity)
            Resize();
        data[tail++] = el;
    }

    // Move Push function
    void Push(P&& el) {
        if (tail == capacity)
            Resize();
        data[tail++] = std::move(el);
    }

    // Peek function
    const P& Peek() const {
        if (isEmpty())
            throw std::out_of_range("Queue is empty");
        return data[head];
    }

    // Pop function
    P Pop() {
        if (isEmpty())
            throw std::out_of_range("Queue is empty");
        return std::move(data[head++]);
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return head == tail;
    }

private:
    P* data;
    unsigned capacity;
    unsigned head;
    unsigned tail;

    void copy(const Queue& other) {
        capacity = other.capacity;
        head = other.head;
        tail = other.tail;
        data = new(std::nothrow) P[other.capacity];
        if (!data)
            throw std::invalid_argument("Memory error!");

        for (size_t i = head; i < tail; i++) {
            data[i] = other.data[i];
        }
    }

    void move(Queue&& other) {
        data = other.data;
        capacity = other.capacity;
        head = other.head;
        tail = other.tail;

        other.data = nullptr;
        other.capacity = 0;
        other.head = 0;
        other.tail = 0;
    }

    void free() {
        delete[] data;
        data = nullptr;
    }
};