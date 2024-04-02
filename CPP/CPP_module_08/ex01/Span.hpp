#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Span {
private:
    std::vector<int> numbers;
    unsigned int N;

public:
    Span(unsigned int size);
    void addNumber(int number);
    template<typename Iterator>
    void addNumber(Iterator begin, Iterator end);
    int shortestSpan();
    int longestSpan();
};
template<typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin++);
        if (numbers.size() == N) break; // Prevent exceeding max capacity
    }
}
#endif