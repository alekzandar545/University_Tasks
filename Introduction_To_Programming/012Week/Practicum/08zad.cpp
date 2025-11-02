#include <iostream>

bool IsValidMove(bool**map, size_t sizex, size_t sizey, unsigned x, unsigned y){
    return x<sizex && y < sizey && map[x][y];
}

int FindIslands(bool** map, size_t sizex, size_t sizey, unsigned x, unsigned y){
    if(!IsValidMove(map, sizex, sizey, x, y))
        return 0;
        //std::cout << map[x][y];
    map[x][y] = 0;
        FindIslands(map, sizex, sizey, x+1, y);
        FindIslands(map, sizex, sizey, x, y+1);
        FindIslands(map, sizex, sizey, x-1, y);
        FindIslands(map, sizex, sizey, x, y-1);
        FindIslands(map, sizex, sizey, x+1, y+1);
        FindIslands(map, sizex, sizey, x-1, y-1);
        FindIslands(map, sizex, sizey, x-1, y+1);
        FindIslands(map, sizex, sizey, x+1, y-1);
    return 1;
}

int main(){
    size_t sizex, sizey;
    std::cin >> sizex >> sizey;
    bool** matrix = new(std::nothrow) bool*[sizex];
    if(!matrix){
        std::cout << "memory error!";
        return 0;
    }
    for (size_t i = 0; i < sizex; i++)
    {
        matrix[i] = new(std::nothrow) bool[sizey];
        if(!matrix[i]){
            for (size_t j = 0; j <= i; j++)
            {
                delete[] matrix[j];
            }
            delete[] matrix;
        }
    }
    for (size_t i = 0; i < sizex; i++)
    {
        for (size_t j = 0; j < sizey; j++)
        {
            std::cin >> matrix[i][j];
        }   
    }
    int islands = 0;
    for (size_t i = 0; i < sizex; i++)
    {
        for (size_t j = 0; j < sizey; j++)
        {
            islands += FindIslands(matrix, sizex, sizey, i, j);
        }   
    }
    std::cout << islands;
    for (size_t j = 0; j < sizex; j++)
        delete[] matrix[j];
    delete[] matrix;  

}