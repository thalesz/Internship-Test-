## 1. Fix the Issues in the Following Code

### Requirements:
- **Compiler:** `gcc`
- **Task:** 
  - Remove errors and warnings.
  - Fix memory handling issues.

```c
#include <stdio.h>

int copyStr(char *x) {
 strcpy(x, "test");
 return 0;
}

int main() {
 const char x[3];
 copyStr((char *) x);
 printf("x=%s (%d bytes)\n", x, strlen(x));
 return 0;
} 
```


## Answer

### 0. First compilation

After compiling the code for the first time using the command:
`gcc -o main main.c`

The following results were obtained: 

```
main.c: In function 'copyStr':
main.c:4:2: warning: implicit declaration of function 'strcpy' [-Wimplicit-function-declaration]  
  strcpy(x, "test");
  ^~~~~~
main.c:4:2: warning: incompatible implicit declaration of built-in function 'strcpy'
main.c:4:2: note: include '<string.h>' or provide a declaration of 'strcpy'
main.c: In function 'main':
main.c:11:33: warning: implicit declaration of function 'strlen' [-Wimplicit-function-declaration]
  printf("x=%s (%d bytes)\n", x, strlen(x));
                                 ^~~~~~
main.c:11:33: warning: incompatible implicit declaration of built-in function 'strlen'
main.c:11:33: note: include '<string.h>' or provide a declaration of 'strlen'
```


### 1. `string.h` library not included

```
main.c:11:33: note: include '<string.h>' or provide a declaration of 'strlen'
main.c:4:2: note: include '<string.h>' or provide a declaration of 'strcpy'
```

These errors are happening because the necessary header for the `string.h` library, which includes `strcpy` and `strlen`, is missing.

```
#include <string.h> 
```

According to [W3School](https://www.w3schools.com/c/c_ref_string.php):
The <string.h> library has many functions that allow you to perform tasks on `string`. including `strcpy` and `strlen`

### 2. Usage of `%d`

This warning occurs because the `strlen` function returns a value of type `size_t`, which is often an `unsigned long int` on many systems. However, the code is using the `%d` format specifier in `printf`, which expects a value of type `int`.

```
main.c:12:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘size_t’ {aka ‘long unsigned int’} [-Wformat=]
   12 |  printf("x=%s (%d bytes)\n", x, strlen(x));
      |                ~^               ~~~~~~~~~
      |                 |               |
      |                 int             size_t {aka long unsigned int}
      |                %ld
x=test (4 bytes)
```

According to [w3School](https://www.w3schools.com/c/ref_string_strlen.php#:~:text=The%20strlen()%20function%20returns,using%20the%20sizeof%20operator%20instead.): The `strlen()` function returns the length of a `string`, which is the number of characters up to the first null terminating character. This is smaller than the amount of memory that is reserved for the `string`, which can be measured using the `sizeof` operator instead.

According to [CPlusPlus](https://cplusplus.com/reference/cstdio/printf/): To correct this, you should use the `%zu` format specifier for the `size_t` type.`%zu` is used to ensure that the value is printed correctly regardless of the platform.

### 3. Insufficient array size

The array `x` was declared as `const char x[3]`. This is insufficient to store the string `"test"`, which contains 5 characters (4 letters plus the null terminator `\0`). The array size needs to be increased to at least 5.

#### About Arrays
[W3School](https://www.w3schools.com/c/c_arrays.php)

### 4. Using `const` with content modification

According to [W3School](https://www.w3schools.com/c/c_constants.php):

If you don't want others (or yourself) to change existing variable values, you can use the `const` keyword.
This will declare the variable as "constant", which means unchangeable and read-only.

The variable `x` has been declared as `const char`, which means it cannot be modified. However, the copyStr function is trying to modify the contents of `x`, which is not allowed in variables declared as `const`. The solution would be to remove the `const` or handle the string in such a way that it is not modified.

### 5. Pointer Conversion

Converting `const char *` to `char *` in `copyStr((char *) x)` is risky because it breaks the immutability guaranteed by `const`. To modify the `string`, `x`should be declared as `char *` instead of `const char *`.



# Corrected code:

```c
#include <stdio.h>   // Standard I/O library for using printf
#include <string.h>  // String library for using strcpy and strlen

// Function that copies the string "test" into the memory pointed by x
int copyStr(char *x) {
    strcpy(x, "test");  // Copies the string "test" into the buffer x (which must have enough space)
    return 0;  // Returns 0 to indicate success
}

int main() {
    char x[5];  // Declares an array of 5 characters to hold the string "test" (4 chars + null terminator '\0')
    
    // Calls the copyStr function to copy the string "test" into the array x
    copyStr(x);
    
    // Prints the string stored in x, and its length in bytes
    // strlen(x) returns the length of the string (4 for "test")
    // %zu is used to format the size returned by strlen (which is of type size_t)
    printf("x=%s (%zu bytes)\n", x, strlen(x));

    return 0;  // Returns 0 to indicate the program finished successfully
}

```

---

<!-- Next Button -->
[➡️ Next Question](../Resposta%2002/Resposta02.md) 

<!-- Home Button -->
 [🏠 Home](../Enunciado.md)
