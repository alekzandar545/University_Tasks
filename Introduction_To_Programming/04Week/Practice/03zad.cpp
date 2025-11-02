#include <iostream>

using namespace std;

int main(){
    //Да се прочетат от конзолата цяло число x и цифра n и да се намери колко пъти цифрата n се среща в числото x.
    int input, num, output;
    //output = 0;
    cin >> input >> num;

    do{
       if(input % 10 == num)
            output++;
        input /= 10;         
    }  
    while(input != 0);
    
    cout << output;
}