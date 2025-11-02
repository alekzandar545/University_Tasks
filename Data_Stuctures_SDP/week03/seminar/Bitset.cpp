#include "Bitset.hpp"
#include <vector>
#include <cstdint>
#include <stdexcept>

bool Bitset::getBit(size_t pos) const{

}
void Bitset::setBit(bool b, size_t pos){//b stands for bucket
    size_t bIndex = pos>>3; //this ensures we have the num /8
    uint8_t bPos = pos & 7; //and then we see where the bit is inside the 8-bit byte //ostatuk pri delenie na 8
    uint8_t mask = 1 << pos;
    if(b){m_data[bIndex] = m_data[bIndex] | mask;}
    else{ m_data[bIndex] = m_data[bIndex] & (~mask);}
    //m_data[bIndex] = (m_data[bIndex] & (~mask) | (b << pos)); po-hitro
}

Bitset::Bitset(){}
Bitset::Bitset(size_t size){
    m_data.reserve((size+7)/8);
    m_capacity = m_data.size()*8;
    this->m_size = size;
}
BitsetProxy Bitset::operator[](size_t index){
    return BitsetProxy(&m_data[index >> 3], index & 7);
}

void Bitset::push_back(bool val){
    if(m_size >= m_capacity){
        m_data.push_back(0);
        m_capacity+=8;}
    setBit(val,m_size);

}
void Bitset::pop_back(){
    m_size--;
}
size_t Bitset::size(){
    return m_size;
}
void Bitset::flip(){

}
void Bitset::flip (size_t pos){
    if(pos>m_size)
        throw std::invalid_argument("index out of range");
    size_t bIndex = pos >> 3;
    uint8_t bPos = pos & 7;
    m_data[bIndex] = m_data[bIndex] ^ (1 << bPos);
}
bool Bitset::all() const{}
bool Bitset::any() const{}
bool Bitset::none() const{}

BitsetProxy::BitsetProxy(uint8_t* element, uint8_t pos) :m_el(element), m_pos(pos){}

BitsetProxy::operator bool() const{
    return (*m_el >> m_pos) & 1;
}

BitsetProxy& BitsetProxy::operator=(bool val){
    uint8_t mask = 1 << m_pos;
    *m_el = (*m_el & (~mask)) | (val << m_pos);
    return *this;
}

//!!! explicit before constructor zapranqva neqvni castvaniq