#include "Child.h"

//child constructor calling Father constructor
Child::Child(float height, float weight): Father(height,weight){
}

Child::Child(std::string father,std::string mother){
    this->fatherName = father;
    this->motherName = mother;
}

Child::~Child() = default;

//our virtual GetFamily, instead of return childname, we overide it and return parents instead
std::vector<std::string> Child::GetFamily(){
    std::vector<std::string> parent {this->fatherName, this->motherName};
    return parent;
}

//other definition we don't need, because we inherit from father.

