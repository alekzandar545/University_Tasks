#include <iostream>

int main(){
    /*Задача 4 Да се напише функция, която приема n x m матрица от цели положителни числа acoounts, където accounts[i][j] е сумата,
    която i-тия човек държи, в банка j. Функцията да връща кой е най-богатият човек
    Състоянието на един човек се определя от сбора на сумите, които той държи във всички банки.*/
    int x, y;
    std::cin >> x >> y;
    int** matrix = new(std::nothrow) int*[x];
    if(!matrix){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < x; i++)
    {
        matrix[i] = new(std::nothrow) int[y];
        if(!matrix[i]){
            std::cout << "Memory error!";
            for (size_t j = 0; j < i; j++)
            {
                delete[] matrix[j];
            }
            delete[] matrix;
            return -1;
        }
        for (size_t j = 0; j < y; j++)
        {
            std::cin >> matrix[i][j];
        } 
    }

    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
        
    }
    
    for (size_t i = 0; i < x; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    //note: Поради някаква причина не мога да гръмна програмата и да получа "Memory error!"
}