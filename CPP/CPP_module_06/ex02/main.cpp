#include "main.hpp"

Base::~Base(){};

Base* generate(){
	Base* classes[3];
	classes[0] = new A;
	classes[1] = new B;
	classes[2] = new C;
	int random = rand() % 3;

	for (int i = 0; i < 3; i++){
		if (i != random)
			delete classes[i];
	}
	return classes [random];
}

void identify(Base* p){
	A* aptr = dynamic_cast<A*>(p);
	B* bptr = dynamic_cast<B*>(p);
	C* cptr = dynamic_cast<C*>(p);
	if (aptr != NULL)
		std::cout << "p: A" << std::endl;
	else if (bptr != NULL)
		std::cout << "p: B" << std::endl;
	else if (cptr != NULL)
		std::cout << "p: C" << std::endl;
}
void identify( Base& p ) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

int main(){
	
	Base* basePtr1 = generate(); // Assume basePtr points to a DerivedClass instance
	Base* basePtr2 = generate();
	Base* basePtr3 = generate();
	identify(basePtr1);
	identify(*basePtr1);
	identify(basePtr2);
	identify(*basePtr2);
	identify(basePtr3);
	identify(*basePtr3);
	delete basePtr1;
	delete basePtr2;
	delete basePtr3;
}