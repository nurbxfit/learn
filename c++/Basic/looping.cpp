#include<iostream>
#include<vector>

int main(int argc,char** argv){
    int i {0} ;

    //example do while loop
    // do this while condition true.
    do {
        i++;
        std::cout << "Inside do: " << i << std::endl;
    }while (i < 5);

    while(i < 10){
        std::cout << "Inside while: " << i << std::endl;
        i++;
    }
    int num;
    std::vector<int> numbers;
    for(int x=0; x < i; x++){
        std::cout << "add even number to vectors: ";
        std::cin>> num;

        if(num %2 == 0){
            
            numbers.push_back(num);
            continue;
        }
        //using continue all code below here will be skip, and loop continue
        std::cout << "please use even number" << std::endl;
        //use break to jump out of any loop or switch
        if(x == 7) break;
    }

    //looping vectors
    for(auto i = 0; i < numbers.size(); ++i){
        std::cout<< "inside vector: " << numbers[i] << std::endl;
    }

    char endStr[] = "end\n";
    //looping array
    for(auto x : endStr) std::cout << x ;
    return 0;
} 