#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <stdint.h>

struct Data {
    int n;
    char c;
    Data(int num, char ch) : n(num), c(ch) {}
};

class Serializer {
private:
    Serializer() {}
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
};

unsigned long Serializer::serialize(Data* ptr){
	return reinterpret_cast<unsigned long>(ptr);
}
Data* Serializer::deserialize(unsigned long raw) {
	return reinterpret_cast<Data*>(raw);
}
#endif