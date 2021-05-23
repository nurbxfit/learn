#include<iostream>

int main(int argc, char** argv){
    std::string myNumstr;
    std::cout << "Enter a number (1-100):";
    std::cin >> myNumstr;
    int myNumint { stoi(myNumstr) };
    int lastEven;    
    // condition check using >= <= == > < 
    // we can use or using || 
    if ((myNumint >= 1) && (myNumint <=100)){
        int i=1;
        for(; i <= myNumint; i++){
            if( i%2 == 0 ){
                std::cout << i << " is even" << std::endl;
            }else{
                std::cout << i << " is odd" << std::endl;
            }
        }
        // if myNumint = 3; after loop, i will be 4;
        // we decrement for use in lastEven
        i--; 
        //example of ternary operator
        // var = (condition) ? if_true : if_false; 
        lastEven = ( i %2 == 0) ? i : i-1;
    }else{
        std::cout << "Your number is either too big or negative" << std::endl;
    }
    std::cout << "Last even Number is:" << lastEven << std::endl;
    
    // bool will store trus as 1 false as 0
    bool isOurLastEven = (lastEven == myNumint) ? true : false;

    /*to set cout to show true or false instead of 1 or 0,
     we can set format using std::cout << std::boolaplha;
     or std::cout.setf(std::ios::boolalpha);
     - to disable it we change boolalpha to noboolalpha
    */
    std::cout.setf(std::ios::boolalpha);
    std::cout << "is myNumber Even? " << isOurLastEven << std::endl;

    return 0;
}