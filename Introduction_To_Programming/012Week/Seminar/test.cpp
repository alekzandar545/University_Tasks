#include <iostream>

void Permute(char * const str, const size_t left, const size_t right)
{
    if(left == right)
    {
        std::cout << str << '\n';
        return;
    }
    for(size_t i = left; i <= right; i++)
    {
        std::swap(str[left], str[i]);
        Permute(str, left + 1, right);
        std::swap(str[left], str[i]);
    }
}

int main(){
    char string[4] = "abc";
    Permute(string, 0, 2);
}