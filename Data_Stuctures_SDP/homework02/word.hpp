#include <string>

#pragma once

struct Word
{
    std::string word;
    int value;

    Word(std::string word, int value) : word(word), value(value){}
    bool operator<(const Word& other)const{
        return value > other.value;
    }
};