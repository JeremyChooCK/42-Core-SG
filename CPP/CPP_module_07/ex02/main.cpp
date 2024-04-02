#include "Array.hpp"

int main() {
    // Demonstrating default construction
    Array<int> arr;
    std::cout << "Size of empty array: " << arr.size() << std::endl;

    // Construction with size
    Array<int> arrWithSize(5);
    std::cout << "Size of array with size 5: " << arrWithSize.size() << std::endl;

    // Testing element access and modification
    for (unsigned int i = 0; i < arrWithSize.size(); ++i) {
        arrWithSize[i] = i;  // Initialize elements
    }

    // Copy construction
    Array<int> copiedArr = arrWithSize;
    copiedArr[0] = 100;  // Modify copied array

    // Verify original array is not affected
    std::cout << "Original array first element: " << arrWithSize[0] << std::endl;
    std::cout << "Copied array first element: " << copiedArr[0] << std::endl;

    // Accessing out of bounds (should throw an exception)
    try {
        for (int i = 0; i < 5; i++){
            std::cout << arrWithSize[i] << " ";
        }
        std::cout << std::endl;
        std::cout << arrWithSize[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}