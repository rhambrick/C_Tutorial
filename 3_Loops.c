/* Compile and run commands: (make sure terminal is open in the right folder and u installed the gcc compiler)
    gcc 3_Loops.c -o out
    out.exe
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    // While Loops:
    int count = 0;

    while (count < 5) {
        printf("count: %d\n", count);
        count++;
    }

    // Do while:
    // note how count is now 5 from above loop
    do {
        printf("do count: %d\n", count);
        count--; 
    }
    while (count > 0);

    // For loops:
    // for (int iterator = start value; condition; increment amount){...}
    int i;
    for (i = 0; i < 5; i++) {
        printf("for loop i= %d\n", i);
    }

    // Nested loops
    for (int row = 1; row <= 3; ++row) {
        printf("Outer (row): %d\n", row);  // Executes 2 times

    // Inner loop
        for (int column = 1; column <= 3; ++column) {
            printf("\tInner (col): %d\n", column);  // Executes 6 times (2 * 3)
        }
    }

    // Break and continue
    for (i = 0; i < 10; i = i+2) {
        if (i == 4) {
          break;    // loop breaks out at 4 and stops
        }
        printf("another loop with a break: %d\n", i);
      }

    
    for (i = 0; i < 10; i= i+2) {
        if (i == 4) {
            continue;   // goes back to top of loop
        }
            printf("cont. loop: %d\n", i);
    } 

    return 0;
}