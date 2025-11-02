#include <iostream>

struct point{
    int x = 0, y = 0;
};

int main(){
    point p;
    std::cin >> p.x >> p.y;
    //check for each figure
    bool inCircle = false, inTriangle = false, inRectangle = false;
    inCircle = sqrt(p.x*p.x + p.y*p.y) <= 1;
    inTriangle = (p.x + p.y == 2) && (p.x <= 1 && p.x >=-1) && (p.y <= 2 && p.y >=1);
    inRectangle = (p.x >= -2 && p.x <=2) && (p.y <=3 && p.y >= 2);

    if(p.x == 0 && p.y = 2){
        std::cout << "The point is on the edge of the rectangle and the square";
    }
    else if(p.x == )
}