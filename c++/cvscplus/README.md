# Type safety in C++

- in C, type safety means, protection use to prevent one type from being confused with another.
- C is basically a type-unsafe language compared to C++.

## Example C vs C++.

```c
/*example in C language*/
int *p = malloc(sizeof(int));

/*example in C++*/
auto p = new int;
```

- in this example, we are allocation an int size memory in heap.
- in `C` we need to use `malloc()` which return `void *` which will automatically convert to `int *`.
- the problem here is the program implicitly convert a data type from `void*` to `int*`.
- a programmer can excidently write this

```c
int*p = malloc(sizeof(short));

//or
short c;
int*b = malloc(sizeof(c));
```

- which will caused the allocated short size memory returned and converted into an `int*`.
- the compiler will have no ideas if the conversion is too small from the actual size programmer trying to allocate.
- and the conversion will still applied.
- other drawback is programmer need to state the size of memory need to be allocated. which we use `sizeof()` to do that.
- here error can happen if programmer excidently give a wrong size like giving a pointer `sizeof(int*)` instead of actual type`sizeof(int)`;

# Object in C++

```c
/*In C language*/
struct point{
    int x;
    int y;
}

void addVal(point*p; int x,int y){
    if(p==NULL){
        return;
    }
    p->x+=x;
    p->y+=y;
}
```

```c++
/*In C++*/
struct point{
    int x;
    int y;
    void addVal(int x, int y){
        p->x += x;
        p->y += y;
    }
}

```

- the different is that, in c++ implementation, the addVal function is the member of the struct, thus it doesn't need to specify a pointer of type `point` as the first parameter to reference variable `p`.
- we also don't have to verify if the pointer equal to NULL or not.
- the implementation in C++ end up more clean and faster.
- moreover in C++ we got `~destructor` function that help object to properly deconstruct.
- best use of it is when we are opening a file descriptor, we can use the destructor to close the file descriptor at the end.
- so there is no problem of open file descriptor dangling around unclose.

```c++
//example closing file descriptor using destructor.
struct somefd{
    int fd{0};
    ~somefd(){
        close(fd);
    }
}
```
