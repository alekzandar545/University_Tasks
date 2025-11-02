#include <iostream>
#include <stack>
#include <queue>

void ComboPrint(std::vector<std::string>& data, int index, std::string result){
    for (size_t i = index; i < data.size(); i++)
    {
        if(data[i].size() == 1)
            result.append(data[i]);
        else{
            char last = data[i].back();
            data[i].pop_back();
            ComboPrint(data, i, result);
            data[i].push_back(last);
            result.push_back(last);
        }
    }
    std::cout << result << '\n';
}

int main(){
    std::string input;
    std::cin >> input;
    std::vector<std::string> data;
    for (size_t i = 0; i < input.length(); i++)
    {
        if(input[i] == '{'){
            i++;
            std::string curr;
            while(input[i] != '}' ){
                if(input[i] != ','){
                    curr.push_back(input[i]);
                }
                i++;    
            }
            data.push_back(curr);
        }
        else{
            std::string curr;
            curr.push_back(input[i]);
            data.push_back(curr);
        }
    }
    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
    std::string res;
    ComboPrint(data,0, res);

    
}