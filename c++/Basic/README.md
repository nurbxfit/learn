## C/C++ basic types.

os: linux.
format: typename : 32-bit os size in bytes : 64-bit os size in bytes : printf format specifier.

- short : 2 : 2 : %hd
- unsigned short : 2 : 2 : %hu
- int : 4 : 4 : %d
- unsigned int : 4 : 4 : %u
- long : 4 : 8 : %ld
- unsigned long : 4 : 8 : %lu
- long long : 8 : 8 : %lld
- unsigned long long : 8 : 8 : %llu

## Floating point types

- float (single precision) 4 bytes
- double (double precision) 8 bytes
- long double (extended precision) 8 bytes

## <cstdint> integer types.

- int8_t
- int16_t
- int32_t
- int64_t

## character types

- char (default type 1-byte character such as ASCII (signed or unsigned))
- char16_t (2-byte character set such as UTF-16)
- char32_t (4-byte character set such as UTF-32)
- signed char (1-byte character but with signed)
- unsigned char(1-byte character but not signed)
- wchar_t (large character such as Unicode).

## Hardcoded Literal.

- `0b` for binary
- `0` for octal : %o
- `0x` for hexadecimal :%x
- `F` or `f` for default 8 bytes (double) floating point.
- `L` or `l` for 8 bytes long/extended.
- `e` for exponential notation.

- example:
  - declaring `int a = 0123` means we declare octal value octal(123)=dec(83);
    - this will print the decimal value 83 to the screen instead of `0123`
  - declaring `int a = 0xF` mean we declared hex(F)=dec(15)
  - declaring `int a = 0b1010` mean we declared bin(1010)=dec(10)
  - declaring `float a = 0.1F`
  - declaring `long double a = 0.3L`
  - delcaring `double planks_constant = 6.62607004e-34`

## Initialization.

- in C++, there are 4 common ways to initialize a variables

```cpp
int a; // no initializer
int b = 5; // initializer after equals sign (copy initialization)
int c( 6 ); // initializer in parenthesis (direct initialization)
int d{ 7 }; // initializer in braces (list initialization)
```

- copy initialization, copy value from right side of `=` to the left side.
  - we use this in c language.
  - copy init can be less efficient with complex data types.
  - it's ok to be use with simple primitive type.
- direct initialization, tend to be more effecient then copy.
  - it's look like a contructor.
  - only limited to certain data type.
  - not suitable for init an object with a list of data.
- list initialization.
  - other example of list initialization
  ```cpp
  int myNumb {10}; //prefered list init method
  int myNumb2 = {10}; //copy list init (list init but copy value to var)
  int zeroVal {};// called value init
  ```
  - direct init are prefered, when coding..
  - list init provide, value safety.
  - if we try to use value like `2.0`in an `int` initialization, compiler will throw error.
  - unlike copy init where we can init like this `int myval = 2.3`;
  - which will not cause error, just that only 2 get stored in var not `.3`

## operator.

- i++ (Assign->increment);
  - let say i = 0;
  - if a = i++; then a == 0, and value of i after i++ is 1. it assign a=i first then i++;
- ++i (increment->Assign);
  - same example but, a will be 1, i also will be 1. we perform i++ first then a = i;
  - in for loop, we can use any one of these, some say it is better to use ++i;
