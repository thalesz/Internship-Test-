## 3. In C language, what’s a static variable?

According to [W3School](https://www.w3schools.in/c-programming/storage-classes#:~:text=Static%20variables%20preserve%20the%20value,0'%20by%20the%20C%20compiler.):

`Static variables` preserve the value of a variable even when the scope limit exceeds. Static storage class has its scope local to the function in which it is defined. On the other hand, global `static variables` can be accessed in any part of your program. The default value assigned is '0' by the C compiler. 


### 1. Local static variables

Local static variables are declared within a function and retain their value between calls to that function. This means that even after the function finishes executing, the value of the static variable will be preserved

Example:

```c
#include <stdio.h>

void contador() {
    // Static local variable
    // This variable retains its value between function calls
    static int count = 0;
    // Increment the static local variable
    count++;
    // Print the current value of count
    printf("Contador: %d\n", count);
}

int main() {
    // Call contador function multiple times
    // Each call will increment and print the current value of count
    contador(); // Output: Contador: 1
    contador(); // Output: Contador: 2
    contador(); // Output: Contador: 3

    return 0;
}
```


### 2. Global static variables
Global static variables are accessible only within the file where they are declared. They cannot be accessed from other files, even if those files are included:

Example:

```c
#include <stdio.h>

// Static global variable
// This variable is only accessible within this file
static int globalCount = 0;

void incrementar() {
    // Increment the static global variable
    globalCount++;
    // Print the current value of globalCount
    printf("Global Count: %d\n", globalCount);
}

int main() {
    // Call incrementar function, which will increment and print globalCount
    incrementar(); // Output: Global Count: 1
    incrementar(); // Output: Global Count: 2

    return 0;
}
```



| **Type**                | **Description**                                                                                       | **Scope**                                  | **Initialization**                 |
|-------------------------|-------------------------------------------------------------------------------------------------------|--------------------------------------------|-----------------------------------|
| **Local Static Variable** | Preserves its value between function calls and is initialized only once.                             | Limited to the block or function where it is defined. | Initialized only once during the first call. |
| **Global Static Variable** | Visible only within the file where it is defined, maintaining its value throughout the program’s execution. | Accessible only within the file where it is defined. | Initialized only once when the program starts. |

---

[⬅️ Previous](../Resposta%2002/Resposta02.md)

<!-- Next Button -->
[➡️ Next](../Resposta%2004/Resposta04.md)

<!-- Home Button -->
 [🏠 Home](../README.md)
