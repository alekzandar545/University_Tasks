#include <iostream>
#include "bst.hpp"

std::vector<int> mergeStreams(std::ifstream& stream1, std::ifstream& stream2){
    std::vector<int> res;
    int curr;
    while(stream1 >> curr)
        res.push_back(curr);
    while(stream2>>curr)
        res.push_back(curr);
    BST::mergeSort(res,0,res.size()-1);
    return res;
}

int main(){
    std::ifstream stream1("tree1.txt");
    std::ifstream stream2("tree2.txt");
    BST tree;
    std::vector<int> values = mergeStreams(stream1, stream2);
    tree.buildTree(values,0,values.size()-1);
    tree.printBFS();
}