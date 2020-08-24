#include <iostream>

int main(){
	int sixteenbit = 65536;
	int nexvar = 0;
	int lsi = 0;
	std::cout << "Enter a number: " ;
	std::cin >> lsi;
	std::cout << "old16bit= " << sixteenbit << std::endl;
	sixteenbit += lsi;
	std::cout << "sixteenbit= "<< sixteenbit << std::endl;
	std::cout << "nexvar= " << nexvar << std::endl;
}
