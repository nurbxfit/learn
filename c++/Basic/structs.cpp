#include <iostream>
#include <sstream> // std::ostringstream
/*
struct example, unlike class, struct is public by default,
we can define a private . we can also inherit with struct
I think this is unique in c++, in c language struct may behave different.
*/

struct MyStruct
{
    int myAge,energyLevel;
    char myGrade;
    std::string myString;

    //constructor
    MyStruct(int age = 24, char grade='F'){
        myAge = age;
        myGrade = grade;
        energyLevel = 100;
    }
    bool amIaFailure(){
        return true;
    }

    //operator overloading example
    MyStruct & operator ++ () {
        //increase age
        myAge++;
        energyLevel--;
        return *this;
    }

    MyStruct & operator -- (){
        energyLevel --;
        return *this;
    }

    operator const char*(){
        std::ostringstream myStream;
        myStream << "Age: " << myAge << 
            "\n Energy: " << 
            energyLevel << 
            "\n Grade:" << 
            myGrade;

            myString = myStream.str();
            return myString.c_str();
        
    }

    bool operator == (const MyStruct& otherObj){
        //check if other object same as this
        return ((myGrade == otherObj.myGrade) && (myAge == otherObj.myAge));
    }

};


int main(int argc, char**argv){
    MyStruct  jun(23,'C');
    MyStruct jake{24,'D'};

    std::cout.setf(std::ios::boolalpha);
    std::cout << "Jun is a failure: " << jun.amIaFailure() << std::endl;
    ++jake; //our ++ operator overloading

    std::cout << jake << std::endl; //using our char (c string ) overloading.

    //our compare == overloading
    std::cout << "is jake and jun same ? : " << (jake == jun) << std::endl;

    --jun;
    std::cout << "Jun's information\n";
    std::cout << jun << std::endl;

    return 0;
}