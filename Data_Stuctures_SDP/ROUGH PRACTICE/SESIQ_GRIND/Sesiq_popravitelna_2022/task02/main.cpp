#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr){}
    Node(int data, Node* left, Node* right) : data(data), left(left), right(right){}
};

Node* toTree(const int* sorted_data, int start, int end){
    if(start > end)
        return nullptr;
    int mid = (start + end) / 2;
    return new Node(sorted_data[mid], toTree(sorted_data,start,mid-1), toTree(sorted_data,mid+1,end));
}

Node* toTree(const int* sorted_data, size_t size){//binary search that bitch
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    return new Node(sorted_data[mid], toTree(sorted_data,0,mid-1), toTree(sorted_data,mid+1,end));//the root
}

void release(Node* curr){
    if(!curr)
        return;
    release(curr->left);
    release(curr->right);
    delete curr;
}

void toArray(Node*curr, int*& output, unsigned& index){
    if(!curr)
        return;
    toArray(curr->left, output, index);
    output[index++] = curr->data;
    toArray(curr->right, output, index); 
}

size_t toArray(Node* tree, int*& output){//we assume output is big enough //we do a cheeky BFS
    unsigned index = 0;
    toArray(tree, output, index);
    return index;
}

int main(){
    const int arr[5] = {1,2,3,4,5};
    Node* tree = toTree(arr, 5);
    int* res = new int[5];
    toArray(tree, res);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << res[i] << " ";
    }
    
    release(tree);
}