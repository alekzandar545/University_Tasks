#include <iostream>
const size_t maxLen = 100;

int VectorInput(int *vector, int size){
    for (size_t i = 0; i < size; i++)
    {
        int input;
        std::cin >> input;
        vector[i] = input;   
    }
}

int main(){
    /*Да се напише програма, която намира скаларното произведение на два вектора.
     Векторите може да се представляват чрез едномерни масиви. Двата вектора трябва
      да са с равен брой елементи (1 <= n <= 100).*/
    int size;
    std::cout << "Enter the size of the vectors: ";
    std::cin >> size;
    if(size > maxLen){
        std::cout << "Invalid size!";
        return 0;
    }

    int vector1[maxLen];
    int vector2[maxLen];
    int product = 0;

    std::cout << "vector1: ";
    VectorInput(vector1, size);
    std::cout << "vector2: ";
    VectorInput(vector2, size);

    for (size_t i = 0; i < size; i++)
    {
        product += vector1[i] * vector2[i]; 
    }

    std::cout << product;
    
    
    
}