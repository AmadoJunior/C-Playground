#include <iostream>

int main(){
    int x = 10;
    int *ptr = &x;
    *ptr = 20;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    return 0;
}