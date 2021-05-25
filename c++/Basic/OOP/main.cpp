#include <iostream> 
#include "Father.h"
#include "Child.h"
//example Object oriented programming.

void PrintFamily(Father &father);


int main (int argc, char ** argv){
    Father bob(170.0,75.3);
    Father john(176.3,80.5);
    Father nomado = Father();

    Child james("bob","marrie");

    std::cout << "Number of Club members (bob):" << bob.GetClubMembers() << std::endl;
    std::cout << "Number of Club members (john):" << john.GetClubMembers() << std::endl;
    std::cout << "Number of Club members (nomado):" << nomado.GetClubMembers() << std::endl;

    //set childname
    std::string childName = "Ariel";
    bob.SetChild(childName);
    childName = "James";
    bob.SetChild(childName);
    bob.SetChild("Anela");

    // std::vector<std::string> bobChilds = bob.GetFamily();

    std::cout << "Bob's Child:\n" ;
    PrintFamily(bob);
    std::cout << "\n=======================\n";
    james.SetHeight(172.8); //we use function we inherit from parent
    james.SetWeight(75);

    std::cout << "James's infos\n";
    std::cout << "height: " << james.GetHeight() << std::endl;
    std::cout << "weight: " << james.GetWeight() << std::endl;

    std::cout << "James's Parent:\n" ;
    PrintFamily(james);

    return 0;
}

//polymorph example, we can use same funct with child and father.
void PrintFamily(Father &father){
    for(int i=0; i < father.GetFamily().size(); ++i){
        std::cout << father.GetFamily()[i] << std::endl;
    }
}