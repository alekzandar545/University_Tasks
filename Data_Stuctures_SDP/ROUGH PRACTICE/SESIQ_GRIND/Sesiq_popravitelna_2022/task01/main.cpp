#include <iostream>

struct Node {
    int val;
    Node* next;
    
    Node(int value) : val(value), next(nullptr) {}
};

// Function to split the list into two halves
void splitList(Node* head, Node*& left, Node*& right) {
    if (!head || !head->next) {
        left = head;
        right = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    // Move fast two steps and slow one step
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    left = head;
    right = slow->next;
    slow->next = nullptr; // Break the list into two halves
}

// Function to merge two sorted lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;
    
    if (left->val <= right->val) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Merge Sort function
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head; // Base case: 0 or 1 node

    Node* left;
    Node* right;
    
    splitList(head, left, right); // Split into two halves

    left = mergeSort(left);  // Recursively sort left half
    right = mergeSort(right); // Recursively sort right half

    return merge(left, right); // Merge sorted halves
}

// Utility function to print the list
void printList(Node* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Utility function to insert a new node at the end
void insert(Node*& head, int value) {
    if (!head) {
        head = new Node(value);
        return;
    }
    
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(value);
}

// Driver Code
int main() {
    Node* head = nullptr;
    
    insert(head, 4);
    insert(head, 2);
    insert(head, 1);
    insert(head, 5);
    insert(head, 3);

    std::cout << "Unsorted List: ";
    printList(head);

    head = mergeSort(head);

    std::cout << "Sorted List: ";
    printList(head);

    return 0;
}
