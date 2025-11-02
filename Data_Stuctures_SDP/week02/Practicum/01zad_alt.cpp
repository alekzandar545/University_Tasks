#include <iostream>
#include <cmath>
#include <vector>
//Напишете рекурсивна функция, която генерира всички подмножества на дадено множество от числа.
void PrintSubset(const std::vector<int>& set){
    std::cout << '{';
    unsigned size = set.size();
    if(size > 1){
        for (size_t i = 0; i < size-1; i++)
            std::cout << set[i] << ", ";
    }
    if(size > 0)
        std::cout << set[size-1];
    std::cout << '}' << '\n';
};

void GenerateSubsets(const int* arr, const unsigned size, const unsigned pos, std::vector<int>& res){
    if(pos >= size)
        return PrintSubset(res);
    for (size_t i = pos; i < size; i++)
    {
        res.push_back(arr[i]);
        GenerateSubsets(arr, size, i+1, res);
        res.pop_back(); 
    }
    PrintSubset(res);
  

}

int main(){
    unsigned n;
    std::cin >> n;
    int* arr = new(std::nothrow) int[n];
    if(!arr){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::vector<int> res;
    
    GenerateSubsets(arr, n, 0, res);

    delete arr;
}