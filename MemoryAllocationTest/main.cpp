#include <iostream>
#include <string>

class TestObject{
    public:
        std::string greet;
        TestObject(std::string greet) : greet(greet) {}
};

TestObject* createObject(){
    //Creates Object on the Stack 
    TestObject newObject("Test");
    //Returns an empty pointer because object is deleted after function call is over
    TestObject* myPtr = &newObject;
    //Using new keyword to allocate memory on the heap
    myPtr = new TestObject("Hello World");
    return myPtr;
}

int main(){
    TestObject* ptr;
    ptr = createObject();
    std::cout << "Accessing Object through Pointer: " << ptr->greet << std::endl;
    std::cout << "Address Stored in Pointer: " << ptr << std::endl;
    delete(ptr);
    //The address to the object is still stored in the pointer but it is empty
    std::cout << "Address Still Stored after Deletion of Object: " << ptr << std::endl;
    return 0;
}