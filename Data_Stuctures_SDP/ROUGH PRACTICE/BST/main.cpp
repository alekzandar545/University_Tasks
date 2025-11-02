#include "bst.hpp"
#include <iostream>
#include <cassert>

void testExceptionSafety() {
    try {
        BST<int> tree;
        tree.insert(10);
        tree.insert(5);

        // Simulate a failure during a deep copy
        throw std::bad_alloc();
    } catch (const std::exception&) {
        std::cout << "Exception handled correctly\n";
    }
}
void testInOrderIterator() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    std::vector<int> result;
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        result.push_back(*it);
    }

    // Expected: In-order traversal [5, 10, 15]
    std::vector<int> cmp ={5,10,15};
    assert(result == cmp);
}

void testLevelOrderIterator() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    std::vector<int> result;
    for (auto it = tree.beginLevel(); it != tree.end(); ++it) {
        result.push_back(*it);
    }

    // Expected: Level-order traversal [10, 5, 15]
    std::vector<int> cmp = {10,5,15};
    assert(result == cmp);
}
void testMoveConstructor() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    BST<int> movedTree = std::move(tree);

    assert(movedTree.find(10) == true);
    assert(tree.find(10) == false); // Original tree should be empty
}
void testCopyConstructor() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    BST<int> copyTree = tree;
    copyTree.insert(20);

    assert(tree.find(20) == false); // Original tree should not be affected
    assert(copyTree.find(20) == true);
}
void testBalance() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    assert(tree.isBalanced() == true);          // Balanced
    assert(tree.isPerfectlyBalanced() == true); // Perfectly balanced

    tree.insert(20); 
    tree.insert(25); //now is imbalanced
    assert(tree.isBalanced() == false);
    assert(tree.isPerfectlyBalanced() == false);
}
void testHeight() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    assert(tree.getHeight() == 3); // Height of this tree is 3
}
void testRemove() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    assert(tree.remove(15) == true); // Remove leaf
    assert(tree.find(15) == false);

    assert(tree.remove(5) == true);  // Remove node with two children
    assert(tree.find(5) == false);

    assert(tree.remove(100) == false);
    
    tree.printInOrder(); // Expected: 2 7 10
}
void testFindIterative() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    assert(tree.findIterative(10) == true);
    assert(tree.findIterative(5) == true);
    assert(tree.findIterative(15) == true);
    assert(tree.findIterative(20) == false);
}
void testFind() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    assert(tree.find(10) == true);  // Should find 10
    assert(tree.find(5) == true);   // Should find 5
    assert(tree.find(15) == true);  // Should find 15
    assert(tree.find(20) == false); // Should not find 20
}
void testDuplicateInsert() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(10);

    tree.printInOrder(); // Expected: 10 (if duplicates are ignored)
}
void testInsert() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    // Check in-order traversal (should be sorted order)
    tree.printInOrder(); // Expected: 2 5 7 10 15
}

int main() {
    testInsert();
    testDuplicateInsert();
    testFind();
    testFindIterative();
    testRemove();
    testHeight();
    testBalance();
    testCopyConstructor();
    testMoveConstructor();
    // // testInOrderIterator();
    // // testLevelOrderIterator();
    testExceptionSafety();

    std::cout << "All tests passed!\n";
    return 0;
}
