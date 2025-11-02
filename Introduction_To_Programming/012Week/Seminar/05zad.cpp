#include <iostream>
const unsigned capacity = 15;
const size_t SIZE = 128;

int IsValidMove(int map[SIZE][SIZE], unsigned x, unsigned y, size_t size, int &balance, int path[SIZE][SIZE]){
    return x < size && y < size && balance + map[x][y] <= capacity && balance + map[x][y] >= 0 && path[x][y] == 0;
}

bool FindRoute(int map[SIZE][SIZE], unsigned sx, unsigned sy, unsigned ex, unsigned ey, size_t size, int &balance, int path[SIZE][SIZE]){
    bool forward, backward;
    if(!IsValidMove(map, sx, sy, size, balance, path))
        return 0;
    balance += map[sx][sy];
    std::cout << map[sx][sy] << '\n'; //<< ' ' << sx << ' ' << sy << ' ' << balance << '\n';
    if(sx == ex && sy == ey){
        std::cout << "OK";
       return 1;
    }
 
    path[sx][sy] = 1; //cells the truck has visited
    forward = FindRoute(map, sx + 1, sy, ex, ey, size, balance, path) ||
              FindRoute(map, sx, sy + 1, ex, ey, size, balance, path) ||
              FindRoute(map, sx - 1, sy, ex, ey, size, balance, path) ||
              FindRoute(map, sx, sy - 1, ex, ey, size, balance, path);
    if(forward){
        return 1;
        path[sx][sy] = 0;
    }

    path[sx][sy] = 0; 
    return false;
    //my dude has to go forward and then backward
}

int main(){
    int map[SIZE][SIZE];
    int path[SIZE][SIZE] = {0};
    int size;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> map[i][j];
        }   
    }
    unsigned sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    int balance = 0;
    FindRoute(map, sx, sy, ex, ey, size, balance, path);
    path[sx][sy] = 0;
    path[ex][ey] = 0;
    std::cout << balance << "SOOOOOOOOOOOOOOOK" << '\n';
    std::cout << FindRoute(map, ex, ey, sx, sy, size, balance, path);
    
}