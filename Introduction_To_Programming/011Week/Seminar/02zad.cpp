#include <iostream>

void PrintPyramid(int size, int row, int num){
    if(num == size*(size+1)/2)
        return;
    if(num == row*(row+1)/2){
        row++;
        std::cout << '\n';
    }
    std::cout << num + 1 << ' ';
    PrintPyramid(size, row, num+1);

}

int main(){
    //Задача 2 Да се направи рекурсивна функция, която принтира пирамида от числа.
    PrintPyramid(4, 1, 0);
}