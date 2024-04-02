#include <iostream>

template <typename T>
void iter( T *arr, int size, void (*f)(T &) ){
    for (int i = 0; i < size; i++){
        f(arr[i]);
    }
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void ft_plusone(int &arr){
    arr += 1;
}

int main(){
    char carr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int iarr[7] = {0, 1, 2, 3, 4, 5, 6};
    std::cout << "char arr: " << carr << std::endl;
    std::cout << "int arr: " ;
    for(int i = 0; i < 7; i++){
        std::cout << iarr[i] << " ";
    }
    std::cout << std::endl;
    ::iter(carr, 7, ft_toupper);
    ::iter(iarr, 7, ft_plusone);
    std::cout << "char arr: " << carr << std::endl;
    std::cout << "int arr: " ;
    for(int j = 0; j < 7; j++){
        std::cout << iarr[j] << " ";
    }
}