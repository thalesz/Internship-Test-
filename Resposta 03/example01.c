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
