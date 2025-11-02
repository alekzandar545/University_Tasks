#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

struct Node{
    int val;
    std::vector<Node*> children;

    Node(int val) : val(val) {}
};

Node* deserialize(std::ifstream& stream){
    std::string line = "";
    std::queue<Node*> parents;
    Node dummy(0);
    Node* root = &dummy;
    Node* curr;
    parents.push(root);
    int val;

    while(stream && !parents.empty()){
        //readin
        std::getline(stream, line, '|');
        while((line == "" || line == "\n") && stream)
            std::getline(stream, line, '|');
        //empty space
        if(line == " "){
            parents.pop();
            continue;
        }
        //getting curr
        curr = parents.front();
        parents.pop();

        //adding children
        std::stringstream ss(line);
        while(ss >> val){
            Node* newNode = new Node(val);
            parents.push(newNode);
            curr->children.push_back(newNode);
        }

    }
    return root->children[0];
}

void printDFS(Node* curr){
    if(!curr)
        return;
    std::cout << curr->val << ' ';
    for (Node* child : curr->children)
        printDFS(child);

}

bool matchTree(Node* candidateCurr, Node* smallCurr){
    if(!candidateCurr && !smallCurr)
        return true;
    else if(!candidateCurr || !smallCurr)
        return false;
    else if(candidateCurr->val != smallCurr->val)
        return false;
    else{
        bool valid = true;
        for (size_t i = 0; i < smallCurr->children.size(); i++)
        {
            valid = valid && matchTree(candidateCurr->children[i],smallCurr->children[i]);
        }
        return valid;
    }
}

bool isSubtree(Node* smallRoot, Node* bigRoot){
    Node* curr;
    std::vector<Node*> candidates;
    //find maching values and add candidates to try next alg on
    std::queue<Node*> q;
    q.push(bigRoot);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr->val == smallRoot->val)
            candidates.push_back(curr);

        for (size_t i = 0; i < curr->children.size(); i++)
            q.push(curr->children[i]);
    }
    for (Node* candidate : candidates)
    {   
        if(matchTree(candidate,smallRoot))
            return true;
    }
    return false;
}

int main(){
    std::ifstream stream1("tree1.txt");
    std::ifstream stream2("tree2.txt");
    Node* bigRoot = deserialize(stream1);
    printDFS(bigRoot);
    std::cout << '\n';
    Node* smallRoot = deserialize(stream2);
    printDFS(smallRoot);
    
    std::cout << std::boolalpha << isSubtree(smallRoot,bigRoot);
}