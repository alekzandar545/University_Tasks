#include <iostream>
#include <cmath>
#include <math.h>

bool IsValidMove(int**matrix, size_t size, unsigned x, unsigned y){
    return x < size && y < size && matrix[x][y] == 0;
}

int Power(int n){
    int temp = 1;
    for (size_t i = 1; i <= n; i++)
    {
        temp*=2;
    }
    return temp;
}

void FillMatrix(int** matrix, size_t size, unsigned sx, unsigned sy, unsigned fx, unsigned fy){
    if(!IsValidMove(matrix, size, sx, sy))
        return;
    //depending on where we go the value changes with an XOR of a value of 2; depending on the new position;
    int xdiff = size - fx;
    int ydiff = size - fy;  
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] = matrix[lx][ly] ^ Power(sx - 1);
    if(sx - lx == -1 && sy - ly == 0)
        matrix[sx][sy] = matrix[lx][ly] ^ Power(sx);
    if(sx - lx == 0 && sy - ly == 1)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx + 5);
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx);
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx);
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx);
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx);
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx);
    if(sx - lx == 1 && sy - ly == 0)
        matrix[sx][sy] == matrix[lx][ly] ^ Power(lx);


    return;
}

int main(){
    size_t size;
    std::cin>>size;
    if(size > 10){
        std::cout << "Invalid size!";
        return 0;
    }
    int** matrix = new(std::nothrow) int*[size];
    if(!matrix){
        std::cout << "Memory error!";
        return 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new(std::nothrow) int[size];
        if(!matrix[i]){
            std::cout << "Memory error!";
            for (size_t j = 0; j < i; j++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            return 0;
        }
    }
    
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }
    
    unsigned x, y;
    std::cin >> x >> y;
    if(x > size || y > size){
        std::cout << "invalid coordinates";
        return 0;
    }
    FillMatrix(matrix, size, x, y, x, y);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matrix[i][j];
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    

}