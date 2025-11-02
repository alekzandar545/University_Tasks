#include <iostream>

void Permute(char * const str, const size_t left, const size_t right)
{
    if(left==right){
        std::cout << str << '\n';
    }
    for (size_t i = left; i < right; i++)
    {
        std::swap(str[left], str[i]);
        Permute(str, left + 1, right);
        std::swap(str[i], str[left]);
    }
    
}

int main(){
    //permutation with no repetition
    int len;
    std::cin >> len;
    char* arr = new(std::nothrow) char[len + 1];
    arr[len] = '\0';
    if(!arr){
        std::cout << "Memory error!";
        delete[] arr;
    }
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> arr[i];
    }
    Permute(arr, 0, len - 1);
    delete[] arr;
    
}