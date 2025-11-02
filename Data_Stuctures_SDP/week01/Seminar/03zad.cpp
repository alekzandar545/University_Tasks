#include <iostream>

//Дадено ни е число n искаме да преброим всички възможни начини да представим това число като сбор на положителни числа.

int GenerateSums(int n, int sum, int lastAdded){
    //std::cout << sum << ' ' << lastAdded << '\n';
    if(sum == n)
        return 1;
    if(sum > n)
        return 0;
    int res = 0;
    for (size_t i = lastAdded; i <= n-sum; i++)
    {
        res += GenerateSums(n, sum+i, i);
    }
    return res;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << "-----" << GenerateSums(n, 0, 1) - 1 << "------";
    //-1 cus we dont wanna count the case 0 + number

}
