#ifndef FATHER_H
#define FATHER_H

#include<vector>
#include<string>
/*
header files are use to define prototype of our class,
we can forward declare our function or anything here.,

we use #ifndef, as a header guide, to prevent our code to be include multiple type.
- it basically say, if not define, then we define.

static variable exist here and destroy here,
only member of same origin can access that variable.
here if we declared a static variable in a class, it only exist and can only known by member of that class, not outsider

if we create multiple object, does object can have access to the same static variable.
*/

class Father {
    protected:
        float height;
        float weight;
    
    public:
        static int clubMembers; //father's club members, every father know about it.
        Father(); //constructor
        Father(float height,float weight); //set height and weight;

        virtual ~Father(); //deconstructor;
        virtual std::vector<std::string> GetFamily(); //virtual, we can overide it in child

        //getters and setters
        void SetHeight(float height);
        float GetHeight();

        void SetWeight(float weight);
        float GetWeight();

        void SetChild(std::string childname);
        std::vector<char> GetChild();

        void SetIDNumber(int idnumber);
        int GetIDNumber();


        //static functions to access static variable
        static int GetClubMembers();

    private:
        int idnumber;
        std::vector<std::string>childNames;

}; //don't forget this semicolon

#endif