#include <iostream>

int CalculateBlocks(size_t n, size_t m){
    int result = 1;
    if(n == 1 && m == 1)
        return 1;
    if(n==0 || m == 0)
        return 0;
    size_t block;
    for (size_t i = 1; i <= std::min(n,m); i*=2)
    {
        block = i;
    }
    std::cout << block << n << m << '\n';
    //we split the cube in 3 parts now and find teh blocks recursively
    result += CalculateBlocks(n-block, m-block);
    result +=  CalculateBlocks(n-block, block);
    return result += CalculateBlocks(block, m-block);
}

int main(){
    //Задача 1 Да се напише рекурсивна функция, която по подадени N и M, размерите на площад. Намерете 
    //колко най-малко плочки ще са нужни да запълнят площада, ако плочките са размери 2^n x 2^n.

    //will do thi with area
    unsigned n, m;
    std::cout << "Enter the dimensions: ";
    std::cin >> n >> m;
    std::cout << CalculateBlocks(n, m);

}