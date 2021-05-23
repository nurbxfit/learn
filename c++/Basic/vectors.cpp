#include<iostream>
#include<vector>

int main(int argc, char** argv){

    //we use vector when we don't know the size of our array. view it like a dynamic array

    //we declare vector of size 2;
    std::vector<char> myVect(2);
    myVect[0] = 'h';
    myVect[1] = 'e';
    myVect.push_back('l'); //here we can still expan the size.
    myVect.push_back('l');
    myVect.push_back('o');

    //printing vectors, .begin() return an iterator pointing to the begin of vector
    for(auto i = myVect.begin(); i != myVect.end(); ++i){
        std::cout << *i; //use * to print value of pointer
    }
    std::cout << std::endl;

}