#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        vec.push_back(arr[i]);
    }

    std::list<int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.push_back(arr[i]);
    }

    try {
        std::cout << "Found " << *easyfind(vec, 3) << " in vector\n";
        std::cout << "Found " << *easyfind(lst, 3) << " in list\n";
        std::cout << "Found " << *easyfind(vec, 6) << " in vector\n"; // This should throw an exception
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}