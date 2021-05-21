# Arrays is a collection of something.

- image computer memory is like a box books when we learn math in school.
- the boxes is the region where we can store number.
- an array basically the collections of those boxes.
- ley say if we want to store number 1,4,5,7,8.
- we write those number in 5 small boxes.
- we can give the name of that collection of 5 boxes as myArray.
- what we got here is an array of size 5 named myArray.
- c++ representation of this example is

```c
int myArray[5] = {1,4,5,7,8} ;
```

- each number had their own location (the index of the boxes).
- we can say number 4 is located in index 2 ( or box number two from the left).
- In computer, we start counting number with `0`.
- so instead of at index 2, number of is actually in index 1.
- the position 8 is at index 0 + 4 or simply index 4.
- let say we have a pen pointing to box at index 0.
  - so the pen point to myArray[0] or simply myArray.
- we can tell the pen to point to number 8 by saying point to myArray[4] or `pen+4`, which tell the pen to move 4 box to the right;

```c++
#include <iostream>

int main()
{

    int myArray[5] = {1,4,5,7,8};
    int *pen;
    pen = myArray;
    std::cout << "myArray[4]: " << myArray[4] << std::endl;
    std::cout << "pen+4: " << *(pen+4) <<std::endl;
    std::cout << "myArray+4: " << *(myArray+4) << std::endl;

    return 0;
}
```

- we can run this example and see that we can get the same result which is 8.
- if we take the same box context and extent the array into y-axis (move downward or upward).
- then we produced an multi dimensional array or a matrix.
