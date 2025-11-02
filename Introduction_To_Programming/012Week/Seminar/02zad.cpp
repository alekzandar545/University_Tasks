#include <iostream>

void PrintBinarySequences(bool* const sequence, const size_t size, const size_t index){
    if(index == size){
        bool valid = true;
        for (size_t i = 0; i < size - 1; i++)
        {
            if (sequence[i] == true && sequence[i+1] == true){
                valid = false;
            }
        }
        if(valid){
            for (size_t i = 0; i < size; i++)
                std::cout << sequence[i];
            std::cout << '\n';
        }
        return;
    }

    //we fill up the array with 0s as a first priority and the 1s
    sequence[index] = false;
    PrintBinarySequences(sequence, size, index + 1);

    sequence[index] = true;
    PrintBinarySequences(sequence, size, index + 1);
}


int main(){
    //Задача 2 Да се напише рекурсивна функция, която по подадено цяло положително число n,
    //принтира всички възможни двоични низове, без съседни единици.

    size_t n;
    std::cin >> n;
    bool* sequence = new(std::nothrow) bool[n];
    if(!sequence){
        std::cout << "Memory error!";
        return 0;
    }
    
    PrintBinarySequences(sequence, n, 0);
    delete[] sequence;
}