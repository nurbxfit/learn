## What is Pointer ?

- a variable that point to an address in memory.
- address is the locations of stored data in memory.
- imagine memory store data in a boxes stack togethers.
- when we declare a variable we are allocating boxes.
- each boxes had their own unique id, indicating the location of the box in a stack.
- let say the memory address start with 0.
- when we point to the most bottom box in the memory, we are pointing to address 0.

## How do we declare pointer ?

- in `c` or `c++` we declare pointer using asterik symbol `int *ptr`;
- to point to a memory we use the address operator `&` to tell the pointer to point to an address of a variable.
- example.

```c
#include <stdio.h>

int main(){
    int a = 100;
    int b = 0;
    int *ptr;
    ptr = &a; //teling pointer to point to address of a not the value hold by a
    b = *ptr; //tell b to copy the value hold by variable pointed by ptr (a holding value 100);

    //we can view it
    printf("a= %d\nptr= %d\n*ptr= %d\naddress of a = %d \nb = %d\n",a,ptr,*ptr,&a,b);
    return 0;
}
```

- we get output something like this

```
a= 100
ptr= 166142976
*ptr= 100
address of a = 166142976
b = 100
```

## Pointer and Array.

- array is a collection data stored in memory.
- an array of size 5 means an array that take 5 boxes of memory address.
- the address of array is the address of the first element in an array.
- let say we store number 3,4,5,2,1 in array.
  - 5 boxes are allocated to store that number.
  - let say the array start at address 0x23,
  - the array adress is 0x23.
  - next element will be 0x24, 0x25,0x26,0x27.
  - assuming the number only take one box to store each number.
  - bigger object can allocate more boxes to store them, thus consuming more memory address.

### String, array and pointer.

- string is actually just an array of character.
- the string `hello` is just an array of character `h,e,l,l,o`.
- when storing that string in memory, it actually represent like this `[h][e][l][l][o][\0]`.
- noticed that there is `\0` at the end ?

  - this is used to indicate string termination.
  - to show the end of strings of characters.
  - so that we can know where to stop when reading the string from memory.

- when we declared an array or a strings, we basically declared a pointer pointing to the beginning of the array or string.

```c
#include <stdio.h>
int main(){
    char str[] = "Hello";
    char *str2 = "world"; //we can also declare it as a pointer
    printf("%s \n%c %d %d %d\n", str, str[0],&str,&str[0],str);
    printf("Offset str by 3 (str+3): %c\n",*(str2+3));
    printf("\n%s \n%c %d %d %d\n", str2, str2[0],&str2,&str2[0],str2);
    printf("Offset str2 by 3 (str+3): %c\n",*(str2+3));
    return 0;
}
```

- the output is something like this

```
Hello
H 1418006194 1418006194 1418006194
Offset str by 3 *(str+3): l

world
w 1418006184 4196116 4196116
Offset str2 by 3 *(str+3): l

```

- using the `%s` format string we tell the printf function to inteprete the `str` variable as a string.
- using the `%c` format string, we tell it to inteprete is as a single character at that position.
- find our more about printf format string [here](https://en.wikipedia.org/wiki/Printf_format_string#Type_field)
- the different of output we can see when we declare a string as an array vs a pointer are that
  - the value of &str and &str[0] is the same
  - the value of &str2 and &str[0] is different because str2 is a pointer pointing to memory location where &str2[0] are at.
  - when we use &str2, we are looking at the address of the pointer.
  - not the address of value store at memory location str2[0]
  - it is like this, when we declare as an array, and we read from it, we are reading directly to the array using let say our hand to point to it.
  - when we declared as a pointer, we declared another pointer pointing to the starting location of the array. and we referencing the pointer to go thru the array, it is like we are using a pen to point to it while our hand holding the pen.
  - so when we are referecing the address of `&str2`, we are actually refer to address of the pen we are holding.
  - but the address of `&str2[0]` indicating the address of the first index the pointer pointing to.
  - declaring as a pointer can also mean that we are indirectly addressing the array.
