#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>
#include <cstdlib>
template <typename T>
class Array {
private:
    T* elements;
    unsigned int size_;

public:
    // Default constructor
    Array() : elements(NULL), size_(0) {}

    // Constructor with size
    Array(unsigned int n) : elements(new T[n]()), size_(n) {}

    // Copy constructor
    Array(const Array& other) : elements(new T[other.size_]), size_(other.size_) {
        for (unsigned int i = 0; i < size_; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            T* newElements = new T[other.size_];
            for (unsigned int i = 0; i < other.size_; ++i) {
                newElements[i] = other.elements[i];
            }
            delete[] elements;
            elements = newElements;
            size_ = other.size_;
        }
        return *this;
    }

    // Subscript operator for const and non-const access
    T& operator[](unsigned int index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Size of the array
    unsigned int size() const {
        return size_;
    }
};
#endif