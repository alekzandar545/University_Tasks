#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>

struct Node{
    int value;
    std::vector<Node*> children;

    Node() = default;
    Node(int value) : value(value){}
};

void printTree(Node* root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        std::cout << curr->value << ' ';
        for (size_t i = 0; i < curr->children.size(); i++)
        {
            q.push(curr->children[i]);
        }
        
    }
}

void printDFS(Node* curr){
    if(!curr)
        return;
    std::cout << curr->value << ' ';
    for (Node* child : curr->children)
        printDFS(child);
   
}

void formatedPrint(Node* curr,int depth,bool last, std::string& prefix){
    if(!curr)return;
    std::cout<<prefix;

    if(depth){
        if(last)
            std::cout<<"|\n"<<prefix;        
        
        std::cout<<(last ?  "L--" :"|--" );
    }
    std::cout<<curr->value<<std::endl;
   
    bool currLast;
    for(int i = 0; i < curr->children.size();i++){
        Node* child = curr->children[i];
        currLast = (i == curr->children.size() - 1 );
        if(depth){
            prefix.push_back( last ? ' ': '|');
            prefix.push_back(' ');
            prefix.push_back(' ');
        }
        formatedPrint(child,depth+1,currLast, prefix);
        if(depth){
            prefix.pop_back();
            prefix.pop_back();
            prefix.pop_back();
        }
    }
}
void print(Node* root){
    std::string s = "";
    formatedPrint(root,0,1, s);
}

int findLayer(Node* root){
    std::queue<Node*> q;
    for (size_t i = 0; i < root->children.size(); i++)
        q.push(root->children[i]);
    q.push(nullptr);
    int layer = 1;
    bool validLayer = true; // will set to false if anything pops up

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(q.empty())
            return -1; //reached the end
        if(!curr){
            if(validLayer)
                return layer;
            else{
                validLayer = true;
                q.push(nullptr);
                layer++;
                continue;
            }
        }
        // std::cout << curr->value << ' ' << std::boolalpha << validLayer << ' ';
        for (size_t i = 0; i < curr->children.size(); i++)        
            q.push(curr->children[i]);
        
        if(curr->children.size() != 1){
            // std::cout << "coock" << curr->value;
            validLayer = false;    
        }
    }

    //nothing found here ;c
    return -1;
}

void removeLayersRec(Node* last, Node* curr, int targetLayer, int currLayer){
    if(currLayer > targetLayer)
        return;
    if(currLayer == targetLayer){
        //remove curr as a child from last and replace it with curr's child
        for (int i = 0; i < last->children.size(); i++){
            if(last->children[i] == curr){
                last->children[i] = curr->children[0];
            }
        }
        delete curr;
        
    }
    else{
        for (size_t i = 0; i < curr->children.size(); i++)
            removeLayersRec(curr, curr->children[i], targetLayer, (currLayer+1));
    }
}

void removeLayers(Node* root){
    removeLayersRec(nullptr, root, findLayer(root), 0);
}

Node* deserialize(std::ifstream& stream) {
    Node dummy;
    Node* root = &dummy;
    std::queue<Node*> parents;
    parents.push(root);
    Node* curr;
    int val;

    while (stream) {
        //getting line
        std::string line;
        std::getline(stream, line, '|'); 
        while((line == "\n" || line == "") && stream){
            std::getline(stream,line,'|');
        }
        std::stringstream ss(line);

        //no children case
        if (line == " ") { 
            parents.pop();
            continue;
        }

        //getting curr
        curr = parents.front();
        parents.pop();

        //add children to parent otherwise
        while (ss >> val) {
            Node* newNode = new Node(val);
            parents.push(newNode);
            curr->children.push_back(newNode);
        }
    }
    return dummy.children[0];
}

void freeTree(Node* curr){
    if(!curr)
        return;
    for(Node* child : curr->children){
        freeTree(child);
    }
    delete curr;
}


int main(){
    std::ifstream stream("text.txt");
    Node* tree = deserialize(stream);

    removeLayers(tree);

    print(tree);

    freeTree(tree);
    stream.close();
}