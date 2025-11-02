#pragma once

class DumbDynArray{
public:
    unsigned size;
    char* array;
    bool IsDigit(char const a) const;
    unsigned FindDigits(char* const arr) const;
    void AssignDigits(char* const arr);

public:
    DumbDynArray(char* const arr);
    ~DumbDynArray();
    void Print();
};

