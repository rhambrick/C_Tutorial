/* Compile and run commands:
    gcc 7_Functions.c -o out
    out.exe
*/

#include <stdio.h>
#include <math.h>   // includes math functions for quick maths

// function declaration
void greeting(char name[], int age);
/* void means it returns (outputs) nothing, inside the parentheses we see char and int, these are the input variables
the function will be defined below main (define meaning we put in the code to run when we call the function)
you could define up here, but I find that hard to read. Compiler does need to have at least a declaration
before you call it, otherwise it won't know what to do.
*/

int sum(int x, int y);    // another one

void arrayFunc(int nums[5]);    // this one takes an array, the size is predefined

int fib(int x);

float globalNum = 3.14159;  // global variable, accessible anywhere. not a function since there's an equals and no (inputs){}

// main must always be there since compiler looks for it, doesn't necessarily need to be int, but thats convention
int main() {

    // greeting takes a string and int as defined above, so we input those and call the function here a few times
    greeting("John", 7);
    greeting("James", 12);
    greeting("Jen", 38);

    printf("\n");

    // functions can be for repetitive stuff
    int total = sum(354,2245);
    printf("your total is: %i\n", total);

    // you can pass anything to functions basically
    int nums[5] = {10, 20, 30, 40, 50};
    arrayFunc(nums);

    // Scope:
    /* Note how functions have internal variables (greeting is name[] and age for example)
    these variables' scope is only within that function. so here in main, I don't have
    a variable called "age", so trying to access it will result in an error.
    If you need to use a variable in a lot of places, global variables can be useful.
    Defined up top, we have globalNum accessible anywhere. */

    printf("\nglobalNum = %.3f \n", globalNum);    // .3f is how we round to a specific decimal place

    // Recursion
    int fibonaci = fib(10); // calling the recursive funciton, see comments within it below main.
    printf("Fibonacci of %i came out to %i\n", 10, fibonaci);

    // Math.h
    /* Math.h contains function definitions for common math stuff like square root,
    shownn below. There's a ton more, I suggest reading it further if you want.
    Knowing what tools are availible is sometimes the biggest crutch in coding. */
    printf("\nSqrt of 420 is: %f", sqrt(420));

    return 0;
}

// Function definitions:

void greeting(char name[], int age) {
    printf("Hey %s. You are %i years old apparently.\n", name, age);
  }

int sum(int x, int y) {
    return x + y;   // outputs x + y to an int, can use this in variables as shown in main
}

void arrayFunc(int nums[5]) {
    printf("%i is the third element in your array.\n", nums[2]);
}

int fib(int x) {
    if (x > 0) {
        return x + fib(x - 1);  // re-calls the function recursively. walk through with pen and paper if you want.
      } else {
        return 0;   // recursion can be dangerous if not handled properly it'll go infinite.
      }
}