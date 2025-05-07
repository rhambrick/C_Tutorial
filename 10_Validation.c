/* Compile and run commands:
    gcc 10_Validation.c -o out
    out.exe
*/

#include <stdio.h>

int main() {
    float num;
    float result;
    char input[100];

    printf("Enter a letter, bro: ");

    // Read input as a string to handle non-number input gracefully
    if (fgets(input, sizeof(input), stdin) == NULL) {   // this handles empty input
        printf("Error reading input. Did you put anything? \n");
        return 1;   // not returning 0, so we know there was an error if we check return value
    }

    // Attempt to convert the string to an float
    result = sscanf(input, "%f", &num);

    // Check if the conversion was successful
    if (result != 1) {
        printf("Sike! This program only takes floats. Re run ;).\n");
        return 1;
    }

    // If input is valid, proceed with using the integer
    printf("You did it! Here's what you enterd: %f\n", num);

    // This is just for simple input, but you can typically take user input as a string
    // then break it up into chunks and make sure each chunk is valid before moving forward.
    // Thinking of edge cases / ways users could cause errors is tricky sometimes, but also rewarding
    // when your code can withstand anything.

    return 0;
}