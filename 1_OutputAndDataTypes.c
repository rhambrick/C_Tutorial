// Read the readme for info
/* Compile and run commands: (make sure terminal is open in the right folder and u installed the gcc compiler)
    gcc 1_OutputAndDataTypes.c -o out
    out.exe
    ^ mac and linux aren't .exe files, use ./out for those platforms
*/

#include <stdio.h>  // standard input / output header that handles functions like print so we can output data.
#include <stdbool.h> // standard boolean library for booleans (see towards end).

// main function. compiler always looks for a main. int means it outputs a number (return 0;)
// return 0 is typically used to indicate success (historical convention).

int main() {

    // Basic printing
    printf("Hello, bro.");
    printf("Have a good day bro!"); 

    // New lines (\n)
    printf("\n\nHello, bro.\n");
    printf("Have a good day bro!\n\n"); 

    // Variables
    // type variableName = value; is the structure
    // the more descriptive the name the better. int age; makes more sense then int a;
    int num = 15;

    int num2; // this declares the variable, allocating a spot for it
    num2 = 16;    // this defines it (this idea comes up later in functions as well)

    float decimal = 3.14;   // floats are up to 32 bits and hold up to 7 decimal places
    double decimal2 = 9.35;  // doubles are long floats, 64 bits instead, so more precision

    char letter = 'R'; 

    // Format specifiers
    printf("myNum = %i \n", num); // %i for integers (can also use %d but that's low key confusing since I think d for double)
    printf("myFloat and myDouble are: %f , %lf \n", decimal, decimal2); // %f and lf for float and double
    printf("%c is your letter.\n", letter); // %c for chars
    
    // const means you can't change the variable again, so set it and read only.
    const int birthYear = 1995;
    const int year2;  // here we define it but it's useless now because it's empty.

    // Arithmetic
    int x = 1 + 2;  // x=3
    int y = x + 5;  // y=8
    y++;    // y=9
    x--;    // x=2
    x+= 10; // x=12
    // I ain't showing them all but there's all the + - * / modulo etc.

    // Comparison
    printf("is x > y? 1 for yes, 0 for no: %d \n", x > y);  // comparisons like y<=x return 1 for true and 0 for false

    // Boolean data types
    bool isThisAProgram = true;
    bool areCookiesHealthy = false;

    printf("are my two bools different? %d \n", isThisAProgram != areCookiesHealthy);   // ! is for not. 1 for true 0 for false.

    return 0;   // return ends the function, sending a 0 to the operating system here.
}