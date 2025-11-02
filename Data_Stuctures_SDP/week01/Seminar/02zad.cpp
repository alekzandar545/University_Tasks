#include <iostream>
#include <stdexcept>

/*Искаме да генерираме стринг с дължина n съдържащ валидни комбинации от скоби.
Невалидна комбинация от скоби ще наричаме такава комбинация, която има префикс
с повече затварящи отколкото отварящи скоби.*/

void GenerateBrackets(int n, std::string curr, int left, int right){
    if(curr.length() == n)
    {
        if(left == right)
            std::cout << curr << '\n';
        return;
    }
    if(left > right){
        GenerateBrackets(n, curr + ")", left, right+1);  
    }
    GenerateBrackets(n, curr + "(", left+1, right);
}

void printBrackets(std::string& str){
    std::cout << str;
}

int main(){
    int n;
    std::cin >> n;
    if(n%2 != 0)
        throw std::invalid_argument("only even numbers allowed");
    GenerateBrackets(n, "", 0, 0);

    return 0;
}