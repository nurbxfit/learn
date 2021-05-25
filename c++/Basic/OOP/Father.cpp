#include "Father.h"
#include <iostream>

//constructor definition

//default construction
Father::Father(){
    //when a father created, add them to clubmembers;
    clubMembers = clubMembers + 1;
}


Father::Father(float height,float weight){
    clubMembers = clubMembers + 1;
    //set weight
    this->height = height;
    this->weight = weight;
}

//deconstructor dont have overloading becasause they dont take params and dont return anything.
Father::~Father(){
    clubMembers = clubMembers - 1;
    // do something when they die, remove from clubmembers;
}

//static function
int Father::GetClubMembers(){
    return clubMembers; //noticed for static we don't use this->
}

//define default value for our static
int Father::clubMembers = 0;

//definition for setters and getters
void Father::SetHeight(float height){
    this->height = height;
}

float Father::GetHeight(){
    return this->height;
}

void Father::SetWeight(float weight){
    this->weight = weight;
}

float Father::GetWeight(){
    return this->weight;
}

void Father::SetChild(std::string childname){
    this->childNames.push_back(childname);
}

void Father::SetIDNumber(int number){
    this->idnumber = number;
}

int Father::GetIDNumber(){
    return this->idnumber;
}

std::vector<std::string> Father::GetFamily(){
    return this->childNames;
}