
#include<iostream>
#include<functional> //std::function
// this is a werid concept I recently learn about c++
// it can behave like javascript, where we can pass function as params for other function.
// we can also create a vector and store multiple function, and then pass that vector to a function.

int add(int,int);

//but here we need to pass argument for add() seperately
int multiply(int multiplier, std::function<int(int,int)>, int, int);

int main(int argc,char**argv){
    auto addition = add; // int (*addition)(int,int) = add;
    std::cout << "2*(5+1) = " << multiply(2,addition,5,1) << std::endl; 
}

int add(int a, int b){
    return a+b;
}

int multiply(int m, std::function<int(int,int)> func, int a, int b ){
    return m * func(a,b);
}