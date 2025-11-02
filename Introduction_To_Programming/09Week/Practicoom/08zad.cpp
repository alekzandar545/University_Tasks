#include <iostream>

int main(){
    //Да се напише функция, която измества нулите от всеки ред на целочислена матрица най-отзад,
    //подредбата на останалите елементите да се запази. Употребата на оператора за индексиране не е позволена.
    //Да не се използва помощна матрица.
    int rows, cols;
    std::cin >> rows >> cols;
    int** matrix = new(std::nothrow) int*[rows];
    if(!matrix){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < rows; i++)
    {
        *(matrix + i) = new(std::nothrow) int[cols];
        if(!*(matrix + i)){
            std::cout << "Memory error";
            for (size_t j = 0; j < i; j++)
            {
                delete[] *(matrix + j);
            }
            delete[] matrix;
            return -1;
        }
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> *(*(matrix + i) + j);
        }
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols - 1; j++)
        {
            if(*(*(matrix + i) + j) == 0){
                int temp = *(*(matrix + i) + j);
                *(*(matrix + i) + j) = *(*(matrix + i) + j + 1);
                *(*(matrix + i) + j + 1) = temp;
            }
        }
    }

    //printer
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << *(*(matrix + i) + j);
        }
        std::cout << '\n';
    }
}