#include <iostream>
#include <cstring>

const size_t MAXSIZE = 100;
const size_t MAXLENGTH = 11; //+1 because we take in mind '\0'

int main(){
    /*Да се напише програма, която въвежда квадратна матрица с размери най-много 100x100 от символни низове. 
    Всеки от низовете ще бъде с дължина най-много 10 символа. 
    Програмата да проверява дали матрицата е симетрична относно главния си диагонал.*/
    char matrix[MAXSIZE][MAXSIZE][MAXLENGTH];
    int size;
    std::cin >> size;
    std::cin.ignore();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin.getline(matrix[i][j], 10);
            //Не знам защо програмата гърми, когато въведа повече от 10chars
        }
    }
    bool symetric = true;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
        
    }
    
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if(strcmp(matrix[i][j], matrix[j][i]) != 0){
            symetric = false;
            std::cout << std::boolalpha << symetric;
            return 0;
            }

        }
    }
    std::cout << std::boolalpha << symetric;
}