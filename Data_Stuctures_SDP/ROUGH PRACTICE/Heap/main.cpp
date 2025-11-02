#include <iostream>
#include <vector>
#include <cassert>
#include "heap.hpp" // Include your Heap class

void testHeapConstructor() {
    std::cout << "Test: Heap Constructor" << std::endl;
    Heap<int> minHeap;
    assert(minHeap.empty() && "Heap should be empty after initialization");
    std::cout << "Construction test passed!" << '\n';
}

void testInsert() {
    std::cout << "Test: Insert" << std::endl;
    Heap<int> minHeap;

    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(3);

    assert(minHeap.top() == 3 && "Top element should be the smallest element after insertions");
    std::cout << "Insertion test passed!" << std::endl;
}

void testExtract() {
    std::cout << "Test: Extract" << std::endl;
    Heap<int> minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(3);

    int extracted = minHeap.extract();
    assert(extracted == 3 && "Extracted element should be the smallest element (3)");
    assert(minHeap.top() == 5 && "Top element should be the next smallest element after extraction");

    extracted = minHeap.extract();
    assert(extracted == 5 && "Extracted element should be 5");
    assert(minHeap.top() == 10 && "Top element should now be 10");
    std::cout << "Extract test passed!" << std::endl;
}

void testHeapify() {
    std::cout << "Test: Heapify" << std::endl;
    std::vector<int> arr = {10, 20, 5, 6, 1, 8};
    Heap<int> minHeap(arr); // Assume this calls the heapify constructor
    assert(minHeap.top() == 1 && "Heapify should arrange elements such that the top is the smallest");
    std::cout << "Heapify test passed!" << std::endl;
}

void testHeapSort(){
    std::cout << "Test: Heap Sort" << std::endl;
    std::vector<int> arr = {10, 20, 5, 6, 1, 8};
    Heap<int>::heapSort(arr);
    // Verify if the array is sorted after heap sort
    for (size_t i = 1; i < arr.size(); i++) {
        assert(arr[i-1] >= arr[i]);
    }
    std::cout << "Heap sort test passed!" << std::endl; //we sorted it in descending order lmao
}

void testEmpty() {
    std::cout << "Test: Empty" << std::endl;
    Heap<int> minHeap;
    assert(minHeap.empty() && "Heap should be empty initially");

    minHeap.insert(5);
    assert(!minHeap.empty() && "Heap should not be empty after insertion");

    minHeap.extract();
    assert(minHeap.empty() && "Heap should be empty after extracting the only element");
    std::cout << "Empty test passed!" << std::endl;
}

void testEdgeCases() {
    std::cout << "Test: Edge Cases" << std::endl;
    
    Heap<int> minHeap;
    minHeap.insert(10);
    minHeap.insert(10);
    minHeap.insert(10);

    assert(minHeap.top() == 10 && "Top should still be 10 after inserting duplicates");

    int extracted = minHeap.extract();
    assert(extracted == 10 && "Extracted element should be 10");

    extracted = minHeap.extract();
    assert(extracted == 10 && "Extracted element should be 10 again");

    extracted = minHeap.extract();
    assert(extracted == 10 && "Extracted element should be 10 once more");
    
    std::cout << "Edge case test passed!" << std::endl;
}

int main() {
    testHeapConstructor();
    testInsert();
    testExtract();
    testHeapify();
    testHeapSort();
    testEmpty();
    testEdgeCases();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
