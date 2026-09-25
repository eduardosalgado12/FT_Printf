*This project has been created as part of the 42 curriculum by <edsalgad>.*

## Description
The **ft_printf** project aims to mimic the behavior of the standard C library's `printf` function. The goal is to create a versatile formatting tool that handles various data types—such as characters, strings, integers, and hexadecimals—while managing variadic arguments. This project serves as an introduction to variadic functions in C and reinforces low-level data manipulation.

## Instructions

### Compilation
The project is compiled into a static library named `libftprintf.a`. To compile it, use the provided Makefile:

```bash
make
```

### Usage
To use the function in your code, include the header file and link the compiled library:

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! The number is %d.\n", "World", 42);
    return (0);
}
```

Compile your program as follows:
```bash
cc main.c libftprintf.a -o printf
```

## Algorithm and Data Structure
The project implementation follows a **modular and iterative** approach:
- **Algorithm:** The main function iterates through the format string. When a `%` character is encountered, the control is passed to a dispatcher function that identifies the specifier (e.g., `d`, `s`, `x`) and calls the corresponding helper function.
- **Data Structure:** I used the `va_list` structure (from `stdarg.h`) to handle the variable number of arguments passed to the function.
- **Hexadecimal Conversion:** For the conversion of numbers to base 16, I implemented an **iterative buffer approach**. This stores the remainders of the division by 16 in an array and prints them in reverse order.
- **Justification:** Choosing an iterative method over a recursive one for large numbers (like pointers) prevents potential stack overflow issues and ensures better performance and memory stability.

## 🎥 Resources

### Video Tutorials
- [ What are variadic functions (va_list) in C? ](https://youtube.com) - A great breakdown by CodeVault.
- [ understanding ft_printf](https://youtube.com) - Deep dive into how the function handles arguments.

### AI Usage
AI was utilized for the following tasks:
**Optimization:** The use of AI in this program allowed for the optimization of functions.
**Troubleshooting:** Identifying compilation errors related to data types (`long int` vs `int`) and explaining the generation of `.gch` files to maintain a clean build environment.
**Documentation:** Structuring and translating this README file according to the specific curriculum requirements.
