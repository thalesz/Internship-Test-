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
