#include "tree.hpp"
#include <iostream>

int main() {
    Tree<int> tree;

    int path1[] = {-1};
    int path2[] = {0, -1};
    int path3[] = {0, -1};
    int path4[] = {0,1,-1};

    tree.insert(1, path1); // Insert 1 as root
    tree.insert(2, path2); // Insert 2 as the first child of 1
    tree.insert(3, path3); // Insert 3 as the second child of 1
    tree.insert(4,path4); // nice cock

    //std::cout << tree.root;

    tree.print(); // Output: 1 2 3

    tree.printByLevels();
    // Output:
    // 1
    // 2 3

    std::cout << "Height: " << tree.getHeight() << '\n'; // Output: Height: 2

    std::cout << "Size: " << tree.getSize() << '\n'; // Output: Size: 3

    tree.remove(2);
    tree.print(); // Output: 1 3

    return 0;
}