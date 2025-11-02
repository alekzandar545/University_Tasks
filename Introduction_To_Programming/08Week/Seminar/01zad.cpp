#include <iostream>

size_t const CAPACITY = 100;

void PrintSpiral(int arr[][CAPACITY], int xSize, int ySize){
    int startRow = 0;
    int endRow = xSize - 1;
    int startCol = 0;
    int endCol = ySize - 1;
    while (endCol >= startCol && endRow >= startRow)
    {
        //right
        for (int i = startRow; i <= endRow; i++)
        {
            std::cout << arr[startCol][i];
        }
        startCol++;
        //down
        for (int i = startCol; i <= endCol; i++)
        {
            std::cout << arr[i][endRow];
        }
        endRow--;
        //left
        if(startRow <= endRow){
            for (int i = endRow; i >= startRow; i--)
            {
                std::cout << arr[endCol][i];
            }
            endCol--;
        }
        //up
        if(startCol <= endCol){
            for (int i = endCol; i >= startCol; i--)
            {
                std::cout << arr[i][startRow];
            }
            startRow++;
        }

        //std::cout << ' ' << startRow << ' ' << endRow;
        //std::cout << ' ' << startCol << ' ' << endCol;
    }

    
}


int main(){
    //Да се напише функция, която принтира матрица в спираловидна форма. Елементите са положителни цели числа
    int arr[CAPACITY][CAPACITY];
    std::cout << "Enter the 2 size of the matrix: ";
    int xSize, ySize;
    std::cin >> ySize >> xSize;
    std::cout << "Enter the elements of the array: ";
    for (size_t i = 0; i < ySize; i++)
    {
        for (size_t j = 0; j < xSize; j++)
        {
            std::cin >> arr[i][j];
        }
    }


    
    PrintSpiral(arr, xSize, ySize);
    
}