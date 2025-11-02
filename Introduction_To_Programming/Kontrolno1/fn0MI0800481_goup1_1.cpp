#include <iostream>
    
const size_t ROWS = 2;
const size_t COLS = 3;

int main(){
    /*[30т.] Да се напише програма, която въвежда от клавиатурата правоъгълна матрица от реални числа с 5 реда и 10 колони . 
    Програмата да извежда на стандартния изход текста "yes" в случай, че въведената матрицата има поне два различни линейно 
    зависими реда и "no"  в противен случай.

    Казваме, че редовете a­0,a1,…a9 и b0,b1,…,b9 са линейно зависими, ако съществува такова число k≠0, че a0=k.b0,a1=k.b1,…a9=k.b9.

    Напишете примерна програма, която демонстрира използването на функцията.*/
    double matrix[ROWS][COLS];
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    double currentLine[COLS];
    for (size_t i = 0; i < COLS; i++)
    {
        currentLine[i] = matrix[0][i];
    }
    double firstK;
    double currK;
    //gotta divide the elements of each line and then see if the coefficient is the same
    for (size_t i = 1; i < ROWS; i++)
    {
        firstK = currentLine[0] / matrix[i][0];
        for (size_t j = 0; j < COLS; j++)
        {
            currK = currentLine[j] / matrix[i][j];
            if (currK != firstK){
                std::cout << "yes";
                return 0;
            }
        }
        //new currentLine
        for (size_t j = 0; j < COLS; j++)
        {
            currentLine[j] = matrix[i][j];
        }        
    }
    std::cout << "no";
    return 0;
}