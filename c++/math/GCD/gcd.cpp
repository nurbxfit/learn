#include <cstdio>

unsigned int getValue(){
    unsigned int a;
    printf("decimal value: ");
    scanf("%u",&a);
    return a;
}
unsigned int gcd(unsigned int a, unsigned int b){
    while(b!=0){
        unsigned int remainder = a % b;
        //shift
        a = b;
        b = remainder;
        //continue devide until b = 0;

    }
    return a;
}

unsigned int gcdRecursive(unsigned int a, unsigned int b){
    return b == 0 ? a : gcdRecursive(b,a%b);
}

int main(){
    unsigned int a(getValue());
    unsigned int b(getValue());
    unsigned int g(gcd(a,b));

    printf("a: %u \nb:%u\ngcd: %u \n",a,b,g);
    return 0;
}