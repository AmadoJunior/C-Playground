#include <iostream>
#include "LinkedList.h"

int main(){
    LinkedList myList;

    myList.push(1);
    myList.push(2);
    myList.push(3);
    myList.push(4);
    myList.pop(0);

    myList.reverseList();

    myList.printList();
    std::cout << "\n" ;
    myList.printReversed();

    return 0;
}