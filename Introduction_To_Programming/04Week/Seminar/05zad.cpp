#include<iostream>

using namespace std;

int main(){
    //Задача 5 Да се напише програма, която въвежда цяло число n и отпечатва дали е степен на 2.
    int input;
    cin >> input;
    bool isPower;
    
    for (int i = 1; i <= input; i *= 2)
    {
        if(i == input){
            isPower = true;
        } 
    }
    cout << boolalpha << isPower;
    
}