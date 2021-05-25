#ifndef CHILD_H
#define CHILD_H

#include "Father.h"


//example Child inherit from father
class Child : public Father
{       
    public:
        Child();
        Child(float height,float weight);
        Child(std::string father,std::string mother);
        virtual ~Child();
        std::vector<std::string> GetFamily();
        
    private:
        std::string fatherName;
        std::string motherName;
};


#endif