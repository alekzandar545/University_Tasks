#include <iostream>
#include <stack>

struct factRec{
    int result;
    int arg;
};

int main(){
    std::stack<factRec> factoriel;
    int n;
    int result = 0;
    std::cin >> n;
    factoriel.push({n, -1});
    while(!factoriel.empty()){
        if(factoriel.top().arg != -1){
            int temp = factoriel.top().result;
            factoriel.pop();
            result = factoriel.top().result*temp;
        }
        else if(factoriel.top().arg > 0){
            factoriel.push({factoriel.top().arg - 1 , -1});
            continue;
        }
        else if (factoriel.top().arg == 1)
            factoriel.top().arg = 1;
        else{
            factoriel.pop();
        }
    }
}