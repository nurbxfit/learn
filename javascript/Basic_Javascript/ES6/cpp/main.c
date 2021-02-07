#include <iostream>

using namespace std;

int main(){
    int a=10,b=5;
    if(a<15){
        //this is a new block scope
        int x = 10;
        cout << b << endl; // we can print this.
    }
    cout << x << endl; // we cannot print this. compilation will cause error.
    return 0;

}