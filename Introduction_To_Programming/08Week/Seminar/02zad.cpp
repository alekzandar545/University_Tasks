#include <iostream>
const size_t CAPACITY = 100;

//we have to check the 2 diagonals and each row/col
bool isMagicSquare(int arr[][CAPACITY], int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[0][i];
    }
    for (int i = 0; i < size; i++)
    {
        int localSum = 0;
        for (int j = 0; j < size; j++)
        {
            localSum += arr[i][j];
        }
        if(localSum != sum)
            return false;
    }
    for (int i = 0; i < size; i++)
    {
        int localSum = 0;
        for (int j = 0; j < size; j++)
        {
            localSum += arr[j][i];
        }
        if(localSum != sum)
            return false;
    }

    int diagSum = 0;
    for (int i = 0; i < size; i++)
    {
        diagSum += arr[i][i];
    } 
    if(diagSum != sum)
        return false;

    diagSum = 0;
    for (int i = size; i >= 0; i--)
    {
        diagSum += arr[i][i];
    }
    if(diagSum != sum)
        return false;
    return true;
}

int main(){
    //да се провери за магически квадрат ~~~~
    int size;
    std::cout << "Enter the side of the square:" ;
    std::cin >> size;

    int arr[CAPACITY][CAPACITY];
    std::cout << "Enter the numbers in the square: ";
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    std::cout << std::boolalpha << isMagicSquare(arr, size);


}
