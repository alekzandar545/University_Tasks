#pragma once
#include <vector>
#include <cstdint>

class BitsetProxy{
    private:
    uint8_t* m_el;
    uint8_t m_pos;
    BitsetProxy(uint8_t* el, uint8_t pos);
    public:
    operator bool() const;
    BitsetProxy& operator=(bool);
    friend class Bitset;
};

class Bitset{
    private:
    std::vector<uint8_t> m_data;
    size_t m_size;
    size_t m_capacity;
    void setBit(bool, size_t);
    bool getBit(size_t) const;
    public:

    Bitset();
    Bitset(size_t size);
    BitsetProxy operator[](size_t index);
    void push_back(bool);
    void pop_back();
    size_t size();
    void flip();
    void flip (size_t pos);
    bool all() const;
    bool any() const;
    bool none() const;
};