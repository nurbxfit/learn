
#include<iostream>
#include<string>

/*
copying and pasting from Bjarne Stroustrup's "The C++ Programming Language 4th Edition":

List initialization does not allow narrowing (§iso.8.5.4). That is:

An integer cannot be converted to another integer that cannot hold its value. For example, char to int is allowed, but not int to char.
A floating-point value cannot be converted to another floating-point type that cannot hold its value. For example, float to double is allowed, but not double to float.
A floating-point value cannot be converted to an integer type.
An integer value cannot be converted to a floating-point type.

    int x2 = val;    // if val == 7.9, x2 becomes 7 (bad)

    char c2 = val2;  // if val2 == 1025, c2 becomes 1 (bad)

    int x3 {val};    // error: possible truncation (good)

    char c3 {val2};  // error: possible narrowing (good)

    char c4 {24};    // OK: 24 can be represented exactly as a char (good)

    char c5 {264};   // error (assuming 8-bit chars): 264 cannot be 
                     // represented as a char (good)

    int x4 {2.0};    // error: no double to int value conversion (good)
*/
int main(int argc, char ** argv){

    int myNumb {0};
    std::string strNumber{"10"};
    int intNumber{stoi(strNumber)};
    std::cout << "examaple output to screen" << std::endl;
    std::cout << "example str to int stoi: "<< intNumber << std::endl;
    

    do{
        if(myNumb > 0){
            std::cout << "try again" << std::endl;
        }
        else if (myNumb < 0){
            std::cout << "You guessed to low" << std::endl;
        }
        std::cout << "Guess a number (1-10): ";
        std::cin >> myNumb;

    }while(myNumb < 10);

    if(myNumb > 10){
        std::cout << "You guessed too high" << std::endl;
    }else{
        std::cout << "You Win!, the number is 10 " << std::endl;
    }

    return 0;
}