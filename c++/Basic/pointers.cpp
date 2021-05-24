#include<iostream>

int main(int argc, char ** argv){
    //pointing hold an address, refer to c_lang/pointer folder.
    //declare a pointer uusing * initialize it with nullptr value;
    int* myPointer (nullptr);
    int something (154);
    std::cout << "size of nullptr: " << sizeof(nullptr) << std::endl;

    //pointing to someting, using `&` to get the address.
    myPointer = &something;
    std::cout << "myPointer is holding an address of: " << myPointer << std::endl;
    std::cout << "myPointer value pointed by pointer: " << *myPointer << std::endl;
    std::cout << "Address of the pointer itself: " << &myPointer << std::endl;

    std::cout << "\n\n";
    //double pointer, a pointer point to pointer
    auto *doublePtr {&myPointer};
    std::cout << "doublePtr is holding an address of: " << doublePtr << std::endl;
    std::cout << "doublePtr value pointed by pointer: " << *doublePtr << std::endl;
    std::cout << "Address of the pointer itself: " << &doublePtr << std::endl;
    std::cout << "real value pointed by double pointer: " << **doublePtr << std::endl;

    //pointing an array; and iterate thru it
    int myList[] {1,3,7,9,2};
    int *myPtr (myList);
    std::cout << "First element of array: " << *myPtr << std::endl;
    myPtr++; //move to the next address.
    std::cout << "Second element of array: " << *myPtr << std::endl;


    return 0;
}