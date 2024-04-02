#include <stack>
#include <iostream>
#include <deque>
#include <list>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    MutantStack() : std::stack<T, Container>() {}

    MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) {}

    MutantStack& operator=(const MutantStack<T, Container>& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    const_iterator end() const {
        return this->c.end();
    }
};


int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Copy constructor test
    MutantStack<int> copiedStack(mstack);
    std::cout << "Copied stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Assignment operator test
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Demonstrate usage with a different container type
    MutantStack<int, std::list<int> > listBasedStack;
    listBasedStack.push(42);
    listBasedStack.push(21);
    std::cout << "List-based stack elements:" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = listBasedStack.begin(); it != listBasedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Check if the stack can be reversed
    std::cout << "Reversed stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = --mstack.end(); it != --mstack.begin(); --it) {
        std::cout << *it << std::endl;
        if (it == mstack.begin()) break; // Avoid infinite loop
    }

    return 0;
}
