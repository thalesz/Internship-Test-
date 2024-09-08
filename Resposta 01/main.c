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
