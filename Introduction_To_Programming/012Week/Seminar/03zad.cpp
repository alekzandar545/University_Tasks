#include <iostream>
bool ValidMove(bool** matrix, unsigned ex, unsigned ey, size_t size){
    return ex < size && ey < size && !matrix[ex][ey];
}
bool ValidPath(bool** matrix, unsigned sx, unsigned sy, unsigned ex, unsigned ey, size_t size){
    //checks if move is valid
    if(!ValidMove(matrix, sx, sy, size))
        return false;
    //checks if arrived
    if(sx == ex && sy == ey)
        return true;
    //if not, we move
    matrix[sx][sy] = 1;
    bool result = ValidPath(matrix, sx + 1, sy, ex, ey, size) || ValidPath(matrix, sx, sy + 1, ex, ey, size) ||
                  ValidPath(matrix, sx - 1, sy, ex, ey, size) || ValidPath(matrix, sx, sy - 1, ex, ey, size);
    //backtracking
    matrix[sx][sy] = 0;
    return result;
}

int main(){
    /*Задача 3 Да се напише рекурсивна функция, която намира валиден път между две точки. На функцията ще бъде подадена матрица NxN,
 
    картата по която трябва да се движим. Ако на дадена позиция има 1, това означава че не можем да минаваме през тази клетка.
    Движенията може да се случват само в 4те кардинални посоки(без диагоналите).*/
    size_t n;
    std::cin >> n;
    bool** matrix = new(std::nothrow) bool*[n];
    if(!matrix){
        std::cout << "memory error!";
        return 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new(std::nothrow) bool[n];
        if(!matrix[i]){
            for (size_t j = 0; j <= i; j++)
            {
                delete[] matrix[j];
            }
            delete[] matrix;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }   
    }
    unsigned sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    std::cout << std::boolalpha << ValidPath(matrix, sx, sy, ex, ey, n);

    for (size_t j = 0; j < n; j++)
        delete[] matrix[j];
    delete[] matrix;    
}