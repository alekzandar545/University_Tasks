#include <iostream>
#include <stack>
#include <string>

std::string ChangeExpression(std::string str){
    std::stack<char> operations;
    unsigned len = str.length();
    std::string output;
    for (size_t i = 0; i < len; i++)
    {
        if(str[i] == '(')
            operations.push(str[i]);
        else if (str[i] == ')'){
            while (operations.top() != '(')
            {
                output.push_back(operations.top());
                operations.pop();
            }
            operations.pop();
            //std::cout << operations.top();//removing the last bracket
        }
        else if (operations.empty() && (str[i] == '+' ||str[i] == '-' ||str[i] == '*' ||str[i] == '/'))
            operations.push(str[i]);
        else if (str[i] == '+' || str[i] == '-'){
            if (operations.top() == '*' || operations.top() == '/'){
                output.push_back(operations.top());
                operations.pop();
                operations.push(str[i]);
            }
            else
                operations.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/'){
            operations.push(str[i]);
        } 
        else
            output.push_back(str[i]);
        //output.push_back(str[i]);
        //std::cout << str[i] << ' ' << output <<' ' << operations.top() << '\n';
        
    }
    while(!operations.empty()){
        output.push_back(operations.top());
        operations.pop();
    }
   
    return output;
}

int main(){
    std::string str;
    std::getline(std::cin, str);
    std::string result = ChangeExpression(str);
    std::cout << result;
}