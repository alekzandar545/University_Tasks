#include <iostream>
#include <stack>
#include <string>

bool CheckBrackets(std::string str){
    std::stack<char> brackets;
    unsigned lenght = str.length();
    for (size_t i = 0; i < lenght; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{' ||str[i] == '<')
            brackets.push(str[i]);
        else if((str[i] == ')') && (brackets.top() == '('))
            brackets.pop();
        else if((str[i] == ']') && (brackets.top() == '['))
            brackets.pop();
        else if((str[i] == '}') && (brackets.top() == '{'))
            brackets.pop();
        else if((str[i] == '>') && (brackets.top() == '<'))
            brackets.pop();
    }
    return brackets.empty();
    
}

int main(){
    std::string str;
    std::getline(std::cin, str);
    std::cout << std::boolalpha << CheckBrackets(str);
        
}