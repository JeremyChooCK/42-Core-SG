#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // Example of adding numbers using range of iterators
    std::vector<int> moreNumbers;
    for (int i = 0; i < 10000; ++i) {
        moreNumbers.push_back(i);
    }
    Span largeSpan(10000);
    largeSpan.addNumber(moreNumbers.begin(), moreNumbers.end());

    std::cout << "Large Span shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Large Span longest span: " << largeSpan.longestSpan() << std::endl;

    return 0;
}
