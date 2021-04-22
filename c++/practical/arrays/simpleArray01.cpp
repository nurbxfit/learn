#include <iostream>
#include <cassert>

/*
example of inserting element into array;
*/

#define ARRAYMAX 100

//array pass by reference (a pointer);
int getValue(int *array){
    int size(0);
    std::cout<< "Enter array Length: ";
    std::cin>>size;


    assert(size < ARRAYMAX);
    for(int i = 0; i < size; i++){
        std::cout << i+1 << " values=";
        std::cin >> array[i];
    }
    return size;
}


int main(){
    int myarray[ARRAYMAX];
    int arraysize(getValue(myarray));

    //print array
    for(int i = 0; i < arraysize; i++){
        std::cout << myarray[i] << std::endl;
    }
    return 0;
}