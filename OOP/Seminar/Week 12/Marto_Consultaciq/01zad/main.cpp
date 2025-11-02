#include <iostream>
#include "sequence.h"

int plus2(int i){
    return i+2;
}

int main(){
    Sequence seq(0,10, plus2);
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << seq[i] << '\n';
    }
    for(int i : seq){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    
}