#include <iostream>

bool checkSquare(int xIndex, int yIndex, int matrix[9][9]){
    int supposedSum = 45;
    int currSum = 0;
    for (size_t i = xIndex; i < xIndex+3; i++)
    {
        for (size_t j = yIndex; j < yIndex+3; j++)
        {
            currSum += matrix[i][j];
        }
    }
    if(currSum != supposedSum)
        return false;
    return true;
    
}

int main(){
    int matrix[9][9];
    std::cout << "Enter sudoku numbers: ";
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    bool isSudoku = true;
    //chech rows
    int supposedSum = 45; //sum of first 9 nums (n)(n+1)/2
    int currSum = 0;
    for (size_t i = 1; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            currSum += matrix[i][j];
        }
        if(currSum != supposedSum){
            isSudoku = false;
            std::cout << std::boolalpha << isSudoku;
            return 0;
        }
        currSum = 0;
    }
    
    //check cols
    for (size_t i = 1; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            currSum += matrix[j][i];
        }
        if(currSum != supposedSum){
            isSudoku = false;
            std::cout << std::boolalpha << isSudoku;
            return 0;
        }
        currSum = 0;
    }    
    //check squares
    for (size_t i = 0; i < 9; i+=3)
    {
        for (size_t j = 0; j < 9; j+=3)
        {
            isSudoku = isSudoku && checkSquare(i, j, matrix);
        }
        
    }
    
    std::cout << std::boolalpha << isSudoku; 
}