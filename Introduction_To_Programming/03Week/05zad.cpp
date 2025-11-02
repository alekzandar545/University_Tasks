#include <iostream>

bool checkDigits(bool first, bool second, bool &output0){
    bool output1 = 0;
    if(first && second && output0)
        output1 = 1;
    else if((first && second) || ((first || second) && output0)){
        output0 = 0;
        output1 = 1;
    }
    else if (first || second)
        output0 = 1;

    return output1;  
}
int main(){
    /*Напишете програма, която прочита битовете на две цели числа от стандартния вход и извежда тяхната сума.
     Двете числа ще се въвеждат в двоично представяне и изходът също трябва да бъде в двоично представяне. 
     Променливите във вашата програма може да са само от тип bool, а операциите, които може да изпълнявате, 
     са само логически и побитови: "!, ~, ^, |, &, ||, &&".
    
    Входните числа ще са с дължина 4 бита, а изходът трябва да е с дължина от 5 бита (4 бита сума и 1 бит пренос).*/

    bool first0, first1, first2, first3;
    bool second0, second1, second2, second3;
    bool output0, output1, output2, output3, output4;

    std::cout << "Enter 2 4bit numbers: ";
    std::cin >> first3 >> first2 >> first1 >> first0 >> second3 >> second2 >> second1 >> second0;

    output1 = checkDigits(first0, second0, output0);
    output2 = checkDigits(first1, second1, output1);
    output3 = checkDigits(first2, second2, output2);
    output4 = checkDigits(first3, second3, output3);
    
    
    std::cout << output4 << output3 << output2 << output1 << output0;


}