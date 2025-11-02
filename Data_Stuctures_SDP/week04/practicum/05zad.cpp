#include <iostream>
#include <stack>
#include <queue>
#include <stdexcept>
/*Има група ученици, които чакат на опашка за обяд. Всеки ученик 
има предпочитание за сандвич – от 1 до К. Във всеки момент има само 
един сандвич, който може да се вземе. Ученик взема сандвича ако съвпада 
с неговото предпочитание, а иначе се нарежда отново и се надява да се 
падне сандвич, който да му харесва. Процеса се повтаря докато всички 
ученици на опашката останат без сандвич. На вход получавате N броя 
сандвичи и ученици и К броя видове сандвичи. На следващите 2 реда 
получавате по N числа. Сандвичите, които ще излизат и предпочитанията 
на учениците. Изведете колко от тях ще останат гладни.*/

void printQ(std::queue<int> queue){
    while (!queue.empty())
    {
        std::cout << queue.front() << ' ';
        queue.pop();
    }
    std::cout << '\n';
}

void printS(std::stack<int> stack){
    while(!stack.empty()){
        std::cout << stack.top() <<  ' ';
        stack.pop();
    }
    std::cout << '\n';
}

int main(){
    size_t N;
    size_t K;
    std::cin >> N >> K;
    //validation for sandwitch types will be just with the nums 1-4
    std::stack<int> sandwitches;
    std::queue<int> students;
    for (size_t i = 0; i < N; i++)
    {
        int type;
        std::cin >> type;
        if(type > K || type < 1)
            throw std::out_of_range("Invalid sandwitch type");
        sandwitches.push(type);
    }
    for (size_t i = 0; i < N; i++)
    {
        int preference;
        std::cin >> preference;
        if(preference > K || preference < 1)
            throw std::out_of_range("Invalid sandwitch type");
        students.push(preference);
    }

    unsigned hungryChaps = N;
    unsigned hungerStreak = 0;
    while (!sandwitches.empty())
    {   
        //std::cout << "==================================='\n";
        //printS(sandwitches);
        //printQ(students);

        if(hungerStreak > hungryChaps)
            break;
        
        int student = students.front();
        if(student == sandwitches.top()){
            hungryChaps--;
            hungerStreak = 0;
            sandwitches.pop();
            students.pop();
            continue;
        }
        students.pop();
        students.push(student);
        hungerStreak++;
    }
    
    
    std::cout << "Hungry chaps: " << hungryChaps;
    
    
}