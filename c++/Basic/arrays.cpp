#include<iostream>

int main (int argc, char** argv){
    
    //note that array declared like this is fixed size.
    //we cannot change it size after declared, only the value.
    
    // here we declared 5 arrays of int and char.
    int myIntarray [5] = { 1, 2, 3, 6, 5 };
    // we can declare size 5, but not necessarily populate all space. 
    char myCharArray [5] = {'h','e','l','l'}; // only 4 place populated extra one is fill with 0 or garbage.
    int myArray [] = { 1, 3, 4, 5};
    //here we add last 0 to myCharArray
    myCharArray[4] = 'o';
    
    //alternative ways to declare array of char as strings.
    char myCharArray2 [] = "test"; // this actually 6 because it add \0 at the end
    const char * mypoinArray = "World";

    // we can acess array by providing the index

    std::cout << &myCharArray << "=> " << myCharArray[0] << std::endl; // using my pc, address here is 0x7ffe42f6aa6e=>h, where in decimal end with 110
    std::cout << myCharArray[1] << std::endl; //e
    std::cout << myCharArray[2] << std::endl; //l
    std::cout << myCharArray[3] << std::endl; //l
    std::cout << myCharArray[4] << std::endl; //o

    // noticed that beyond here, using the same variable, 
    // we can read myCharArray2 value by simply incrementing the index.
    // maybe because in memory this two variable are stack together. 
    std::cout << &myCharArray2 << "=> " <<myCharArray[5] << std::endl; //here the address is 0x7ffe42f6aa73=>t, which decimal end 115, noticed that address different is 5 (the size of myCharArray).
    std::cout << myCharArray[6] << std::endl; //e
    std::cout << myCharArray[7] << std::endl; //s
    std::cout << myCharArray[8] << std::endl; //t

    //beyond here is just a garbage value from memory or simply nothing.
    std::cout << myCharArray[9] << std::endl;
    std::cout << myCharArray[10] << std::endl;

    // here another array
    std::cout << &mypoinArray << "=> " << mypoinArray[0] << std::endl;
    std::cout << mypoinArray[1] << std::endl;
    // we can also move thru array by increment/offset it
    std::cout << *(mypoinArray+2) << std::endl;
    std::cout << *(mypoinArray+3) << std::endl;
    std::cout << *(mypoinArray+4) << std::endl;
    std::cout << *(mypoinArray+5) << std::endl;
    std::cout << *(mypoinArray+6) << std::endl;
    return 0;
}