#include <iostream>
#include <vector>
//Да се принтират всички подмножества на дадено множество с числа.


void PrintSubset(std::vector<int> res){
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n'; 
}

void GenerateSubsets(int* arr, int size, int pos, std::vector<int> res){
    if(pos >= size)
        return ;
    PrintSubset(res);
    for (size_t i = pos; i < size; i++)
    { 
        std::vector<int> temp = res;
        temp.push_back(arr[i]);
        //res.push_back(arr[i]);
        GenerateSubsets(arr, size, i+1, temp);
        //res.pop_back();
        
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> poopy;
    GenerateSubsets(arr, 5, 0, poopy);
}