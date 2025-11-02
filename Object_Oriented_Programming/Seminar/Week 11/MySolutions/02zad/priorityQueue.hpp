#pragma once
#include "queue.hpp"
#include <stdexcept>

template <typename P>
class PriorityQueue {
public:
    // Default constructor
    PriorityQueue() : capacity(10), head(0), tail(0) {
        data = new(std::nothrow) Queue<P>[capacity];
        if (!data)
            throw std::invalid_argument("Memory error!");
    }

    // Parameterized constructor
    PriorityQueue(unsigned capacity) : capacity(capacity), head(0), tail(0) {
        data = new(std::nothrow) Queue<P>[capacity];
        if (!data)
            throw std::invalid_argument("Memory error!");
    }

    // Destructor
    ~PriorityQueue() {
        free();
    }

    // Copy constructor
    PriorityQueue(const PriorityQueue& other) {
        copy(other);
    }

    // Move constructor
    PriorityQueue(PriorityQueue&& other) noexcept : data(nullptr), capacity(0), head(0), tail(0) {
        move(std::move(other));
    }

    // Copy assignment operator
    PriorityQueue& operator=(const PriorityQueue& other) {
        if (this != &other) {
            free();
            copy(other);
        }
        return *this;
    }

    // Move assignment operator
    PriorityQueue& operator=(PriorityQueue&& other) noexcept {
        if (this != &other) {
            free();
            move(std::move(other));
        }
        return *this;
    }

    // Push function
    void Push(const P& el, unsigned pr) {
        if (pr >= capacity) {
            Resize(pr);
        }
        data[pr].Push(el);
        if (tail <= pr) {
            tail = pr + 1;
        }
    }

    // Move Push function
    void Push(P&& el, unsigned pr) {
        if (pr >= capacity) {
            Resize(pr);
        }
        data[pr].Push(std::move(el));
        if (tail <= pr) {
            tail = pr + 1;
        }
    }

    // Peek function
    const P& Peek() const {
        for (unsigned i = head; i < tail; ++i) {
            if (!data[i].isEmpty()) {
                return data[i].Peek();
            }
        }
        throw std::out_of_range("Priority queue is empty");
    }

    // Pop function
    P Pop() {
        for (unsigned i = head; i < tail; ++i) {
            if (!data[i].isEmpty()) {
                return data[i].Pop();
            }
        }
        throw std::out_of_range("Priority queue is empty");
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        for (unsigned i = head; i < tail; ++i) {
            if (!data[i].isEmpty()) {
                return false;
            }
        }
        return true;
    }

private:
    Queue<P>* data;
    unsigned capacity;
    unsigned head;
    unsigned tail;

    void copy(const PriorityQueue& other) {
        capacity = other.capacity;
        head = other.head;
        tail = other.tail;
        data = new(std::nothrow) Queue<P>[capacity];
        if (!data)
            throw std::invalid_argument("Memory error!");

        for (unsigned i = 0; i < tail; ++i) {
            data[i] = other.data[i];
        }
    }

    void move(PriorityQueue&& other) {
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
        for (size_t i = 0; i < capacity; i++)
        {
            delete data[i];//why not working?
        }  
        delete[] data;
        data = nullptr;
    }

    void Resize(unsigned newCapacity) {
        if (newCapacity < capacity) {
            return;
        }
        newCapacity = std::max(newCapacity + 1, 2 * capacity);
        Queue<P>* newData = new(std::nothrow) Queue<P>[newCapacity];
        if (!newData)
            throw std::invalid_argument("Memory error!");

        for (unsigned i = 0; i < tail; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};
