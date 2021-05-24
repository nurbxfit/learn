#include<cstdlib>
#include<limits>
#include<iostream>

/*
each character types had their own size and limit. 
*/

int main(int argc, char ** argv){

    float f1 (1.11111111) ; //float only accurate up to 6 digits
    double d1 (1.11111111111111111111111111111111);
    long double ld1 (1.1111111111111111111111111111111111); 

    std::cout << std::endl;
    std::cout <<"Min unsigned short int: " << std::numeric_limits<unsigned short int>::min() << std::endl;
    std::cout <<"Max unsigned short int: " << std::numeric_limits<unsigned short int>::max() << std::endl;
    std::cout <<"size: " << sizeof( unsigned short int ) <<" bytes" << std::endl;

    std::cout << std::endl;
    std::cout <<"Min short int: " << std::numeric_limits<short int>::min() << std::endl;
    std::cout <<"Max short int: " << std::numeric_limits<short int>::max() << std::endl;
    std::cout <<"size: " << sizeof( short int ) <<" bytes" << std::endl;

    std::cout << std::endl;
    std::cout <<"Min unsigned int: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout <<"Max unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout <<"size: " << sizeof( unsigned int ) <<" bytes" << std::endl;

    std::cout << std::endl;
    std::cout <<"Min int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout <<"Max int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout <<"size: " << sizeof(int) <<" bytes" << std::endl;

    std::cout << std::endl;
    std::cout <<"Min unsigned long: " << std::numeric_limits<unsigned long>::min() << std::endl;
    std::cout <<"Max unsigned long: " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout <<"size: " << sizeof( unsigned long ) <<" bytes" << std::endl;

    std::cout << std::endl;
    std::cout <<"Min long: " << std::numeric_limits<long>::min() << std::endl;
    std::cout <<"Max long: " << std::numeric_limits<long>::max() << std::endl;
    std::cout <<"size: " << sizeof( long ) <<" bytes" << std::endl;
    


    std::cout << std::endl;
    std::cout << "Floating Point Don't have unsingned type declaration" << std::endl;
    std::cout <<"Min float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout <<"Max float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout <<"size: " << sizeof( float ) <<" bytes" << std::endl;
    std::cout << "1.11111111 only accurate up to 6 digits : " << f1 << std::endl;
    printf("f1 precise to 6 point: %.7f\n",f1+1);

    std::cout << std::endl;
    std::cout <<"Min double: " << std::numeric_limits<double>::min() << std::endl;
    std::cout <<"Max double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout <<"size: " << sizeof( double ) <<" bytes" << std::endl;
    std::cout << "1.11111111 only accurate up to 6 digits : " << d1 << std::endl;
    printf("d1 precise to 16 point: %.17f\n",d1+1);

    std::cout << std::endl;
    std::cout <<"Min long double: " << std::numeric_limits< long double>::min() << std::endl;
    std::cout <<"Max long double: " << std::numeric_limits< long double>::max() << std::endl;
    std::cout <<"size: " << sizeof( long double ) <<" bytes" << std::endl;
    std::cout << "1.11111111 only accurate up to 6 digits : " << ld1 << std::endl;
    printf("ld1 precise to 16 point: %.17Lf\n",ld1+1);

    std::cout << std::endl;
    std::cout <<"size of char: " << sizeof( char ) <<" bytes" << std::endl;
    std::cout <<"size of bool: " << sizeof( bool ) <<" bytes" << std::endl;
    std::cout <<"size of string: " << sizeof( std::string ) <<" bytes" << std::endl;
    


    return 0;

}