#include<iostream>

int main(){
	unsigned int limit = 0;
	unsigned long long sum = 0;
	std::cout << "Enter Limit: ";
	std::cin >> limit;

	for(unsigned int i = 3; i < limit; i++){
		if((i%3 ==0) || (i%5==0) ){
			std::cout << "n= " << i << std::endl;
			sum += i;
		}
	}
	std::cout << "sum= " << sum << std::endl;
}
