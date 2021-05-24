#include <iostream>

//handling error
int main(int argc, char**argv){
    int x(10);
    try{
        for(int i = 1; i < x ; ++i){
            if(i == 5){
                //we throw an error, everything else stop running, and we go to catch block.
                throw "we reach 5";
            }
            std::cout << "looping.." << std::endl;
        }
    }catch(const char* e){ //here we catch the error.
        std::cout << e << std::endl;
    }
    return 0;
}