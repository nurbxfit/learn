## C/C++ basic types.
os: linux.
format: typename : 32-bit size in bytes : 64-bit size in bytes : printf format specifier.
- short                 : 2 : 2 : %hd
- unsigned short        : 2 : 2 : %hu
- int                   : 4 : 4 : %d
- unsigned int          : 4 : 4 : %u
- long                  : 4 : 8 : %ld
- unsigned long         : 4 : 8 : %lu
- long long             : 8 : 8 : %lld
- unsigned long long    : 8 : 8 : %llu 

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
- char  (default type 1-byte character such as ASCII (signed or unsigned))
- char16_t  (2-byte character set such as UTF-16)
- char32_t  (4-byte character set such as UTF-32)
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