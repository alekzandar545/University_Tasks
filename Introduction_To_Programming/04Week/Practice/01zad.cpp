#include <iostream>

using namespace std;

int main(){
    //Да се прочете от конзолата цяло число и да се отпечатат цифрите му в обратен ред.
    int input;
    cin >> input;
    while(input != 0){
        cout << input % 10;
        input /= 10;
    }
}