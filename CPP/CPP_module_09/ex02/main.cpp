#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename Iterator>
void mergeInsertionSort(Iterator first, Iterator last) {
    int distance = std::distance(first, last);
    if (distance <= 1) return;

    Iterator middle = first;
    std::advance(middle, distance / 2);

    mergeInsertionSort(first, middle); // Sort the first half
    mergeInsertionSort(middle, last); // Sort the second half

    std::vector<typename Iterator::value_type> temp(distance);
    std::merge(first, middle, middle, last, temp.begin());

    // Copy the sorted data back to the original container
    std::copy(temp.begin(), temp.end(), first);

    // If odd number of elements, insert the last one using insertion sort principle
    if (distance % 2 == 1) {
        Iterator end_sorted = last;
        --end_sorted; // Move to the actual last sorted element
        typename Iterator::value_type last_elem = *end_sorted;
        Iterator iter = end_sorted;
        while (iter != first && *(--iter) > last_elem) {
            std::iter_swap(iter, end_sorted);
            end_sorted = iter;
        }
    }
}

void sortVector(std::vector<int>& vec) {
    mergeInsertionSort(vec.begin(), vec.end());
}

void sortList(std::list<int>& lst) {
    mergeInsertionSort(lst.begin(), lst.end());
}

// Template to print sequences (vector or list)
template<typename Container>
void printContainer(const Container& container, const char* msg) {
    cout << msg;
    typename Container::const_iterator it = container.begin();
    for (; it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Error: No numbers provided." << endl;
        return 1;
    }

    vector<int> numbersVector;
    list<int> numbersList;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value <= 0) {
            cerr << "Error: Only positive integers are allowed." << endl;
            return 1;
        }
        numbersVector.push_back(value);
        numbersList.push_back(value);
    }

    // Display original sequence
    printContainer(numbersVector, "Before: ");

    // Sort using vector
    clock_t startVec = clock();
    sortVector(numbersVector);
    clock_t endVec = clock();

    // Sort using list
    clock_t startList = clock();
    sortList(numbersList);
    clock_t endList = clock();

    // Display sorted sequence and timing
    printContainer(numbersVector, "After: ");
    cout << "Time to process a range of " << numbersVector.size() << " elements with std::vector: "
         << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000 << " us" << endl;
    cout << "Time to process a range of " << numbersList.size() << " elements with std::list: "
         << static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000 << " us" << endl;

    return 0;
}
