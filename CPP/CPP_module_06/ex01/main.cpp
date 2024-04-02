#include "main.hpp"

int main() {
    Data myData(42, 'x');
    unsigned long serializedData = Serializer::serialize(&myData);
    Data* deserializedData = Serializer::deserialize(serializedData);

    if (&myData == deserializedData) {
        std::cout << "Success: Original and deserialized pointers match." << std::endl;
        std::cout << "Data content: n = " << deserializedData->n << ", c = " << deserializedData->c << std::endl;
    } else {
        std::cout << "Error: Pointers do not match." << std::endl;
    }

    return 0;
}
