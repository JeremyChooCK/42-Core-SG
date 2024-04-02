#include "Span.hpp"

Span::Span(unsigned int size) : N(size) {};
void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw std::length_error("Cannot add more numbers, Span is full.");
    }
    numbers.push_back(number);
}
int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough elements for a span.");
    }
    std::sort(numbers.begin(), numbers.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < numbers.size(); ++i) {
        minSpan = std::min(minSpan, numbers[i] - numbers[i - 1]);
    }
    return minSpan;
}
int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough elements for a span.");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}