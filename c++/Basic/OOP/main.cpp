#include <iostream> 
#include "Father.h"
//example Object oriented programming.

int main (int argc, char ** argv){
    Father bob(170.0,75.3);
    Father john(176.3,80.5);
    Father nomado = Father();

    std::cout << "Number of Club members (bob):" << bob.GetClubMembers() << std::endl;
    std::cout << "Number of Club members (john):" << john.GetClubMembers() << std::endl;
    std::cout << "Number of Club members (nomado):" << nomado.GetClubMembers() << std::endl;


    return 0;
}