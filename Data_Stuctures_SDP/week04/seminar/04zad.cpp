#include <iostream>
#include <stack>
#include <string>

int main(){
    std::string input = "The quick brown fox jumps over";
    std::stack<std::string> s;
    s.push("");
    for(auto x: input){
        if(x == ' ')
            s.push("");
        else
            s.top() += x;
    }
    std::string result = "";
    while (!s.empty())
    {
        result += s.top();
        result += " ";
        s.pop();
    }
    std::cout << result;
    
}