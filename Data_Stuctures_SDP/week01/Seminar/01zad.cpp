#include <iostream>

const unsigned SIZE = 6;

/*Нека разглеждаме пешка на шахматна дъска с размери n х n.
Поставяме пешката в горния ляв ъгъл и искаме да я преместим
до долния десен само чрез движения надолу и надясно.
По-колко начина може да се случи това.*/

unsigned FindWays(unsigned x, unsigned y){
    unsigned ways = 0;
    if((x == SIZE-1) && (y == SIZE-1))
        return 1; //means we have one valid way
    //count ways
    if(x < SIZE-1)
        ways += FindWays(x+1, y);
    if(y < SIZE-1)
        ways += FindWays(x, y+1);
    return ways;
};

int main(){
    unsigned startX = 0;
    unsigned startY = 0;
    std::cout << FindWays(startX, startY);
    
    return 0;
};