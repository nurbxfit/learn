#include<iostream>
#include<vector>
//function usually declared before main, for main to know about it.
//we can declare function definition above main or we can declare just prototype

//example function prototype.

// here are function prototype
void sitBelow();
int add(int,int);
int add(int); //overloading prototype
void printVector(std::vector<char>);
void printVector(std::vector<int>);

//refer : https://www.ibm.com/docs/en/zos/2.2.0?topic=calls-pass-by-reference-c-only
//pass by reference (using pointer) example
void assignNum(int&); //only in c++

//diff between ref vs point, is that poin can be NULL or re-assigned, ref cannot.

//pass by pointer, same effect as pass by reference
// using pass by pointer, a copy of pointer is pass to function
// modi a pointer in it, only change the copy not the actual pointer.
// we pass a ref address, so our copyPointer can point to that address.
void assignNum(int*); //can be use in c programming

//here are definition
//here ret type is void, (we not return anything)
void sitAbove(){
    std::cout << "my definition is above main\n";
}


int main(int argc, char** argv){
    int param1{5};
    int param2{10};
    std::vector<int> myNums {1,2,3,4,5};
    std::vector<char> myChars {'h','e','l','l','o'};


    //here we call a function
    sitAbove(); //these function does not return anything
    sitBelow(); //so we do not catch the return value;

    //passing params to function
    int retValue{add(param1,param2)}; //we store return value to retValue variable.
    std::cout << "retValue: " << retValue << std::endl;
    std::cout << "overload: " << add(retValue) << std::endl;
    assignNum(retValue);
    std::cout << "assigned: " <<retValue << std::endl;
    assignNum(&retValue); //passing pointer ref address
    std::cout << "byPointer: " <<retValue << std::endl;
    printVector(myNums);
    printVector(myChars);
    return 0;
}

void sitBelow(){
    std::cout << "I sit below but my proto sit above\n";
}
//function have return type and params, here ret type is int;
int add(int a,int b){
    return a + b;
}

//example of function overloading.
//will get call if only one params is passed.
int add(int a){
    //only add constant number  to innt 
    return a + 10;
}

void printVector(std::vector<int> myVec){
    for(auto i = 0 ; i < myVec.size(); ++i){
        std::cout << myVec[i] << ", ";
    }
    std::cout << "\n";
}

void printVector(std::vector<char>myVec){
    for(auto i = myVec.begin(); i != myVec.end(); ++i){
        std::cout << *i;
    }
    std::cout << "\n";
}

//passing by reference
void assignNum(int& mynum){
    mynum = 10;
}

void assignNum(int* mynum){
    *mynum = 20;
}