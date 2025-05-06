/* Compile and run commands: (make sure terminal is open in the right folder and u installed the gcc compiler)
    gcc Program.c -o out
    out.exe
*/

#include <stdio.h>  // standard input / output for printing
#include <stdbool.h> // lets us use bools for a lesson down there
#include <string.h> // for string functions down there

int main() {    // main is function name, must always have main. it takes in () nothing, and outputs an int. everything within it is { in here }
    printf("Hello, gang.\n");
    printf("Have a good day twin!\n"); 
    
    float haha = 3.42;
    printf("%f\n", haha);

    // Create variables
    int myNum = 420;            // Integer (whole number)
    float myFloatNum = 5.99;   // Floating point number
    char myLetter = 'D';       // Character

    // Print variables
    printf("myNum is %d\n", myNum);
    printf("%f\n", myFloatNum);
    printf("%c\n", myLetter);

    // Redefine - can't redeclare "int myNum" once already set
    myNum = 15;
    myLetter = 'D';
    printf("My number is %d and my letter is %c\n", myNum, myLetter);

    int x = 5, y = 6, z  = 50;
    printf("sum  = %d\n", x + y + z);

    // Good variable name
    int minutesPerHour = 60;

    // OK, but not so easy to understand what m actually is
    int m = 60;

    printf("\n");

    // IRL math example: Create integer variables
    int length = 4;
    int width = 6;
    int area;

    // Calculate the area of a rectangle
    area = length * width;

    // Print the variables
    printf("Length is: %d\n", length);
    printf("Width is: %d\n", width);
    printf("Area of the rectangle is: %d\n", area);
    
    // Int math
    x = 5;
    y = 2;
    int sum = 5 / 2;
    
    printf("int sum: %d\n", sum); // Outputs 2 not 2.5 

    // Precision
    myFloatNum = 3.5;

    printf("%f\n", myFloatNum);   // Default will show 6 digits after the decimal point
    printf("%.1f\n", myFloatNum); // Only show 1 digit
    printf("%.2f\n", myFloatNum); // Only show 2 digits
    printf("%.4f\n", myFloatNum);   // Only show 4 digits 

    // Float vs double
    myFloatNum = 3.123456789012345;  // floats only go to 7 decimals (32 bit)
    double myDoubleNum = 3.123456789012345; // doubles go to 15 decs (64 bit)
    printf("Float: %.15f\n", myFloatNum);   // tries to output more, but not accurate
    printf("Double: %.15lf\n", myDoubleNum);    // accurate

    // Memory sizes:
    int myInt;
    float myFloat;
    double myDouble;
    char myChar;

    printf("int bytes: %lu\n", sizeof(myInt)); // these are in bytes
    printf("float bytes: %lu\n", sizeof(myFloat));
    printf("double: %lu\n", sizeof(myDouble));
    printf("char: %lu\n", sizeof(myChar)); 

    // Automatic conversion: int to float
    myFloat = 9;

    printf("myfloat is 9: %f\n", myFloat); // 9.000000

    // Automatic conversion: float to int
    myInt = 9.99;

    printf("int is 9.99: %d\n", myInt); // 9

    // int math on floats
    sum = 5 / 2; // 2.0000000 not 2.5

    // Manual conversion: int to float
    sum = (float) 5 / 2; // 2.500000

    // Another way
    int num1 = 5;
    int num2 = 2;
    sum = (float) num1 / num2; // 2.5
    
    // Consts:
    const int fifteenBabyyy = 15;  // that will always be 15, read only
    const int blank;    // cannot change
    // error if u uncomment this: blank = 15;

    // Operators
    int op = 0;
    op ++; // op is 1
    op --; // 0
    op += 5; // op is 5
    op += 10; // 15
    printf("op now is: %d\n", op);

    printf("\n");

    // Logic
    int op2 = 4;
    printf("op > op2? %d\n", op > op2); // returns 1 for true 0 for false
    // can also do ==, !=, >=, <=, &&, ||, !

    // Booleans
    bool isHamburgerTasty = true;
    bool isPizzaTasty = true;

    // Find out if both hamburger and pizza is tasty
    printf("is pizza and burger yummy? 1 for yes 0 for no: %d\n", isHamburgerTasty == isPizzaTasty); 

    printf("\n");

    // if else's
    x = 2;
    y = 1;
    if (x > y) {
        printf("x is greater than y\n"); // yep
    }

    x = 2;
    y = 2;
    if (x > y) {
        printf("x is greater than y\n"); // no, not output
    }
    else {
        printf("womp womp\n"); // :(
    }  

    // shorthand if: variable = (condition) ? expressionTrue : expressionFalse;
    // ex:
    int outputVariable = (x >= y) ? 1 : 0;

    // Switch cases
    int day = 4;

    switch (day) {
      case 1:
        printf("Monday");
        break;
      case 2:
        printf("Tuesday");
        break;
      case 3:
        printf("Wednesday");
        break;
      case 4:
        printf("Thursday gang\n");
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

    printf("\n");

    // While
    int i = 0;

    while (i < 5) {
    printf("loop %d\n", i);
    i++;
    }

    // Do while
    i = 0;

    do {
    printf("doing loop %d\n", i);
    i++;
    }
    while (i < 5);

    // For
    for (i = 0; i < 5; i++) {
        printf("For loop %d\n", i);
      }

    // Nested
    int row = 0;
    int col = 0;    // note how for loop overwrites these
    // Outer loop
    for (row = 1; row <= 2; ++row) {
        printf("Outer row: %d\n", row);  // Executes 2 times
  
    // Inner loop
        for (col = 1; col <= 3; ++col) {
            printf(" Inner col: %d\n", col);  // Executes 6 times (2 * 3)
        }
    }

    // Break and continue (can use in while loops too)
    for (i = 0; i < 10; i++) {
        if (i == 4) {
          break;
        }
        printf("break loop: %d\n", i);
      }

    
    for (i = 0; i < 10; i++) {
        if (i == 4) {
            continue;
        }
        printf("cont. loop: %d\n", i);
    } 

    printf("\n");

    // Arrays:
    int myNumbers[] = {25, 50, 75, 100};
    myNumbers[0] = 33;

    printf("array[0] %d\n", myNumbers[0]); // Now outputs 33 instead of 25

    // Don't mix data types, these are all ints in this case.
    // Declare an array of four integers:
    float myNumbersFloats[4];   // 4 entries total. cannot change array sizes after making them.

    // Add elements
    myNumbersFloats[0] = 25.2;
    myNumbersFloats[1] = 50.4;
    myNumbersFloats[2] = 75.8;
    myNumbersFloats[3] = 100.0;

    
    // Sizes
    printf("size of my array, in bytes: %lu", sizeof(myNumbers)); // Prints 20 (4 elements each at 4 bytes)
    int leng = sizeof(myNumbers) / sizeof(myNumbers[0]);  // 16 / 4 (since first elem is int, which is 4 bytes)

    printf("size of my array elements: %d\n", leng);

    // Multi-dimensions:
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 3; col++) {
            printf(" matrix: %d\n", matrix[row][col]);
        }
    }
    
    printf("\n");

    // Strings (char arrays):
    char greetings[] = "Hello gng!";
    greetings[0] = 'J';
    printf("%s", greetings);
    // Outputs Jello gng!

    printf("\n");

    // String loops
    char carName[] = "Toyota";
    length = sizeof(carName) / sizeof(carName[0]);  // length was defined way up there

    for (i = 0; i < length; ++i) {
        printf("%c\n", carName[i]);
    }

    printf("\n");

    // \0 and sizes
    char hello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    char hello2[] = "Hello World!";

    printf("Hello World! array has: %lu characters.\n", sizeof(hello));   // Outputs 13, \0 is null character and is auto added by compiler in hello2
    printf("The other hello world also has %lu because of \\0\n", sizeof(hello2));  // Outputs 13 as well (note \\0, \\ is one regular \. similar to \" for single and double quotes.)

    printf("\n");

    // sizeof vs strlen
    char twentyLetters[20] = "ABCD";
    printf("Actual # of letters: %d", strlen(twentyLetters));
    printf(" Size of array: %d\n", sizeof(twentyLetters));

    // Concat strings
    char str1[20] = "Ayyy ";    // notice how we leave space in array making it 20 long
    char str2[] = "Wassup!";

    // Concatenate (result is stored in str1)
    strcat(str1, str2);

    // Print str1
    printf("%s\n", str1);
    // for more string functions, look up the string library header file and read what functions do in there (string.h)

    printf("\n");

    // User Input:
    int userIn;
    printf("Type a number bro (btw it has to be a number, we haven't covered error handling yet): \n");

    // Get and save the number the user types with scanf
    scanf("%d", &myNum);

    // you can also do scanf multiple variables too: scanf("%d %c", &userNumber, &userChar);

    // Output the number the user typed
    printf("Your number is: %d, bro.\n", myNum);

    // scanf takes spaces, tabs, etc. as the end of the input, so if you need to read in something with spaces, like a string, use fgets
    // ALSO! scanf leaves the "enter" key alone, it won't use it, so we need to clear that from the input buffer before reading input again, otherwise the next input will just be read as the \n.
    getchar(); // Read and discard the newline character

    char fullName[30];  // note that we leave lots of space here, but if your user exceeds this, it'll get cut off (I think the extra stuff stays in input buffer)
    // full name will be 29 characters long max, with \0 auto added at end.

    printf("Type your full name: \n");
    fgets(fullName, sizeof(fullName), stdin);

    printf("Hello %s\n", fullName);

    // 

    return 0;  // final return of main(). usually it's 0 to indicate a success to the OS.
}
// https://www.w3schools.com/c/