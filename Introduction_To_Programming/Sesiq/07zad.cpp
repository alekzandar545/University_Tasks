#include <iostream>
struct Point
{
    double x, y;
};

struct Mesh
{
    Point* arr;
    unsigned size;
};

Mesh positive(Mesh m){
    Mesh output;
    unsigned index = 0;
    output.size = 0;
    for (size_t i = 0; i < m.size; i++)
    {
        if(m.arr[i].x > 0)
            output.size++;
    }
    output.arr = new(std::nothrow) Point[output.size];
    for (size_t i = 0; i < m.size; i++)
    {
        if(m.arr[i].x > 0){
            output.arr[index] = m.arr[i];
            index++;
        }
    }
    return output;
}

int main(){
    /*Задача 3. Да се дефинира подходяща структура Point, описваща точка в равнината с координати от тип double и структура Mesh,
    описваща множество от точки в равнината с произволен брой елементи. Да се дефинира функция 

    Mesh positive (Mesh m), 
    която по дадено множество от точки създава ново множество само от тези точки, които са с положителна ордината (т.е. лежат над остта x).*/
    Mesh mesh;
    std::cin >> mesh.size;
    mesh.arr = new(std::nothrow) Point[mesh.size];
    if(!mesh.arr){
        std::cout << "Memory error!";
        return 0;
    }
    for (size_t i = 0; i < mesh.size; i++)
    {
        Point point;
        std::cin >> point.x >> point.y;
        mesh.arr[i] = point;
    }
    Mesh newmesh = positive(mesh);
    if(!newmesh.arr){
        std::cout << "Memory error";
        delete[] mesh.arr;
        return 0;
    }
    for (size_t i = 0; i < newmesh.size; i++)
    {
        std::cout << newmesh.arr[i].x << ' ' << newmesh.arr[i].y << std::endl;
    }
    

    delete[] newmesh.arr;
    delete[] mesh.arr;
    return 0;
}