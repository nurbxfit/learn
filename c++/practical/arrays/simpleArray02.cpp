#include<iostream>
#include<cassert>
#include<iterator>

#define arraySize 10

void removeValue(int *array){
    int place(0);
    std::cout<<"remove array at location:";
    std::cin>> place;
    place--;
    assert(place < arraySize);

    for(int i=place;i<=arraySize-2;i++){
        array[i] = array[i+1]; //shifting place+1 into place,
    }
    array[arraySize-1] = 0;

}

void printArray(int *array){

    std::cout<<"arrayValue:" ;
    for(int i(0);i<arraySize;i++){
        std::cout << array[i] <<',';
    }
    std::cout<<'\n';
}

int main(){
    int myarray[] = {12,2,4,7,6,8,200,333,13,1};
    printArray(myarray);
    removeValue(myarray);
    printArray(myarray);
    return 0;
}