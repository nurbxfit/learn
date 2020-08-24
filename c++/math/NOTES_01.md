# Introduction
these tutorials is based on learning C++ through solving problems. 

# Problems:
## 1. Sum of naturals numbers divisable by 3 or 5.
### Understanding the question.
- what is natural numbers ? 
		- natural number are positive intergers (whole numbers) such as 1,2,3,4,5 .... 
		- what are naturals numbers that are divisable by 3 and 5 ? and how to find it ?
		- natural numbers that are divisable by 3 or 5 starts from 3 .... 
		- divisable means, the modulo operations of a number is 0.
		- modulo operations in programming means, finding the remainder of a division. 
		- so the question ask to find the sum of numbers that when devided by 3 or 5 will return a reminder of 0.

### Approching the problem
- to find the remainder of a division in c++, we make use of the module operation. 
	which is the percentage symbol '%'. 
- this modulus operator return the remainder of an `integer` division. 
- note that if we use other data types such as float or double with %, it will throw an error during compilation.

### program design.
- the program receive input from the user, as a limit for our operation. 
- the program will loop x limits, eg: our lower limit = 3, upper limit is 200,
the program will loop until number 200, and check if the number in between 3 and 200 is divisable by 3 or 5.
- if a number is divisable by 3 and 5, the number is added to a variable called sum.
- and the sum get incremented adding next number that are divisable by 3 or 5.
- because the limit can be a huge number like a millions. 
- we need large memory space to store the sum. so sum need to be declared using long long data type.
- the different between int and long is that:
	- int is at least 16-bit of size, means around 2^16 (65,536) numbers can be stored in that variable.
	- long is at least 32-but of size
	- long long is at least 64-bit of size. 
- if we declared it as int, and stored the value of more than 66 thousand in it, it will caused an overflow in the memory. 

### example code.
```cpp
int main()
{
	unsinged int limit = 0 ; // we use unsinged because we know that number is a natural (positive int) numbers
	unsinged long long sum = 0; // because the limit can be a large number, we need more storage to store out sum.
	std::cout << "Upper Limit" ;
	std::cin >> limit;

	for(unsingned int i = 3; i < limit; i++){
		if(i%3 || i%5)
		{
			sum+=i;
		}
	}
	std::cout << "sum=" << sum << std::endl;

}
```
