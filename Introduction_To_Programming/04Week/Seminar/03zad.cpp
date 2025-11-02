#include <iostream>

using namespace std;

int main(){
    //Задача 3 Да се напише програма, която въвежда цяло положително число n и отпечатва n!.
    int n;
    int fact = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)    {
        fact *= i;
    }
    cout << n << "! = " << fact;
    
    return 0;
}