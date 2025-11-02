#include <iostream>
#include <stack>
#include <string>



int CalculateExpression(const std::string& str){
    std::stack<int> stack;
    unsigned lenght = str.length();
    for (size_t i = 0; i < lenght; i++)
    {
        if(str[i] < '9' && str[i] > '0')
            stack.push(str[i] - '0');
        else if(str[i] == '+'){
            int n1 = stack.top();
            stack.pop();
            int n2 = stack.top();
            stack.pop();
            stack.push(n1+n2);
        }
        else if(str[i] == '/'){
            int n1 = stack.top();
            stack.pop();
            int n2 = stack.top();
            stack.pop();
            stack.push(n1/n2);
        }
        else if(str[i] == '-'){
            int n1 = stack.top();
            stack.pop();
            int n2 = stack.top();
            stack.pop();
            stack.push(n2-n1);
        }
        else if(str[i] == '*'){
            int n1 = stack.top();
            stack.pop();
            int n2 = stack.top();
            stack.pop();
            stack.push(n1*n2);
        }
    }
    return stack.top();
}

int main(){
    std::string str;
    std::cin >> str;
    
    std::cout << CalculateExpression(str);
}