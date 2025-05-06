/* Compile and run commands: (make sure terminal is open in the right folder and u installed the gcc compiler)
    gcc 4_ArraysAndStrings.c -o out
    out.exe
*/

#include <stdio.h>
#include <string.h> // use this to access functions specific to strings (see string section)

int main() {

    int someNums[] = {10, 20, 30, 40}; // int array definition, list of variables

    // Access:
    printf("someNums[0] = %i \n", someNums[0]);    // index starts at 0, so this prints 10.
    printf("someNums[1] = %i \n", someNums[1]);

    someNums[0] = 60;   // change first element

    // Loop access:
    for (int i = 0; i < 4; i++) {
        printf("Loop thru: %i \n", someNums[i]);
    }

    // Adding elements later:
    float newArr[5];  // this holds only 5 items total, you'll have to know this in advance.
    // also, this holds floats, not ints. Cannot mix types.
    newArr[0] = 3.14;
    newArr[1] = .707;

    // Size vs length:
    printf("someNums size is %i bytes \n", sizeof(someNums)); // Prints 16 (someNums is {60, 20, 30, 40}, why not output 4?)
    // This is because sizeof() calculates size in bytes. ints are 4 bytes each, so 4 int array is 16 total bytes.
    // Additionally, floats are 4 bytes, doubles are 8, chars are 1, etc. google for more data types.

    int length = sizeof(someNums) / sizeof(someNums[0]);    // so here it's 16 total size / 4 size for each element = 4

    printf("someNums length is %i nums \n", length);

    // Use this for better loops,
    for (int i = 0; i < length; i++) {
        printf("looping through one more time: %i \n", someNums[i]);
    }

    printf("\n");

    // Multi-dimensional arrays:
    int matrix[2][3] = { {1, 3, 5}, {2, 4, 6} };    // array in an array
    printf("coordinate (0,2) = %i \n", matrix[0][2]);  // access specific elements like so

    for (int row = 0; row < 2; row++) {     // nested loop example to access
        for (int col = 0; col < 3; col++) {
          printf("Row, col = (%i, %i) \n", row, matrix[row][col]);
        }
    } 

    printf("\n");

    // STRINGS:

    char hey[] = "Hello World!";    // strings in C are character arrays.
    printf("First letter in the string is: %c \n", hey[0]);

    // changing
    hey[0] = '7';
    printf("Changed: %s \n", hey);

    // loop access
    char car[] = "Toyota";
    int leng = sizeof(car) / sizeof(car[0]);
    int i;
    
    for (i = 0; i < leng; ++i) {
      printf("%c\n", car[i]);
    }
    
    // a manual way to make a string
    char hi[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    printf("%s \n", hi);
    // note the \0 escape sequence, \0 is null terminator and tells C a string is ended
    // when manually making strings this must be included, but otherwise the compiler adds it on automatically
    // ex: car[] = "ford"; is truly {'f', 'o', 'r', 'd', '\0'}, so the length is actually 5!
    
    // a simple ex:
    char message[] = "Good to see you,";
    char name[] = "Programmer";
    
    printf("%s %s! \n", message, name);

    // Special characters:
    char special[] = {"This is how you do a backslash \\, a quote \", single quote \', a emoticon: ¯\\_(ツ)_/¯, and finish with a null \0 this part here is cut off due to null!"};
    printf("%s \n", special);   // I forgot to mention %s is for strings but u probably got that by now.

    // String.h functions (see how we included <string.h>)
    char letters[26] = {"ABCDE"};   // note how we allocated 26 spaces but only fill 5
    printf("letters length: %d \t", strlen(letters));   // 5
    printf("letters size: %d \n", sizeof(letters)); // 26 (1 byte each)

    // concatenate:
    char str1[20] = "Hey ";
    char str2[] = "bro!";
    
    // Concatenate (result is stored in str1)
    strcat(str1, str2);
    printf("Concatenated: %s \n", str1);

    // Compare
    char str3[] = "ABC";
    char str4[] = "ABC";
    char str5[] = "AB";
    
    printf("%i\n", strcmp(str3, str4));  // returns 0 (equal)
    printf("%i\n", strcmp(str3, str5));  // returns 1 (not equal)

    // see string.h for more functions. knowing what tools are availible is often half the battle.

    return 0;
}