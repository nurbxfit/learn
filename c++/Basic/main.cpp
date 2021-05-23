
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <typeinfo>
/*
up there is just a list of usefull library we can import.
Here are example of 
multi line comment.

std:: means we are telling the compiler that we referencing template from std (standart) library.
if we refer from other template such as a struct we delcared name Orange, we caan use Orange::orangeFunction(); 

*/



//here we place global variable
int myGlobalVar = 10;

int returnGlobalPlusOne (){
    return myGlobalVar +1;
}



int main (int argc, char** argv){
    
    //different data types we can declare
    int myInteger{100};
    bool myBoolean {true};
    char singleCharacters{'F'};
    std::string stringOfChar{"Hello"}; //string is not primitive, so we need to use std::
    const char * cstyleString{"C style String"};
    const char cstyletwo[] {"Second C style String"};
    auto inttype = 1;
    auto chartype = 'R';

    std::cout << "Hello World" << std::endl;
    std::cout << "myGlobal:" << myGlobalVar << std::endl;
    std::cout << "myGlobal+1:" << returnGlobalPlusOne() << std::endl;
    std::cout << cstyleString << std::endl;
    printf("C style printing: %s\n",cstyletwo);
    printf("C style printing: %c\n",singleCharacters);
    std::cout << "Typeof inttype: " << typeid(inttype).name() << std::endl;
    std::cout << "Typepf chartype: "<< typeid(chartype).name() << std::endl;

    return 0;
}