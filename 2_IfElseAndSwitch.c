/* Compile and run commands: (make sure terminal is open in the right folder and u installed the gcc compiler)
    gcc 2_IfElseAndSwitch.c -o out
    out.exe
    ^ mac and linux aren't .exe files, use ./out for those platforms
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    if (200 > 100) {
        printf("Yep, the if statement is true.\n");
      }

    // adding else
    if (65 == 43) {
        printf("This won't execute.\n");
    }
    else {      // here you can also do "else if" as well if you need more ifs. but "else" works fine here.
        printf("This will execute since 65 != 43");
        if (3 != 2) {
            printf("\n\tThis is the nested if executing.\n");
        }
    }

    // Shorthand ifs:
    int x = 44;
    int y = 11;
    // variable = (condition) ? expressionTrue : expressionFalse;
    char yesOrNo = (x / y == 4) ? 'y' : 'n';

    printf("%c", yesOrNo);  // note: you can't just do printf(yesOrNo);, must use format specifiers with printf.
    printf("\n");

    // Switches:
    int day = 2;

    switch (day) {
    case 1:
        printf("Monday");
        break;  // breaks out of the block to prevent others from executing
    case 2:
        printf("Tuesday!!");    // this gets output
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    }

    // Defaults:
    day = 3;
    switch (day) {
    case 6:
        printf("Today is Saturday!!!");
        break;
    case 7:
        printf("Today is Sunday.");
        break;
    default:
        printf(":( it's a weekday\n");  // this executes if no other blocks do
        // no break needed
    }

    return 0;
}