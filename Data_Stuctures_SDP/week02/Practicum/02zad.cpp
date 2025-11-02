#include <iostream>
#include <vector>

void PrintCombination(const std::vector<int>& res){
    for(int i: res)
        std::cout << i << ' ';
    std::cout << '\n';
}

//alternatively we can substract from goal every time
void GenerateSums(const std::vector<int>& nums, int desiredSum, unsigned pos, std::vector<int>& res){
    if (desiredSum < 0)
        return;
    if(desiredSum == 0)
        return PrintCombination(res);
    for (size_t i = pos; i < nums.size(); i++)
    {   
        res.push_back(nums[i]);
        GenerateSums(nums, desiredSum-nums[i], i, res);
        res.pop_back();
    }
};

 /*Напишете рекурсивна функция, която намира всички
уникални комбинации от числа в даден набор,
чийто сбор е равен на зададена целева сума.*/
int main(){
    unsigned size;
    std::cin >> size;
    std::vector<int> nums, res;
    for (size_t i = 0; i < size; i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    int sum;
    std::cin >> sum;
    GenerateSums(nums, sum, 0, res);
    
}