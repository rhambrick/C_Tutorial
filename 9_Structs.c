/* Compile and run commands:
    gcc 9_Structs.c -o out
    out.exe
*/

#include <stdio.h>
#include <string.h>

// Createing a structure called myStructure
// Structs can hold multiple data types within them.
// These are the core of OOP - object oriented programming.
struct myStructure {
    int num;
    char letter;
  };    // note semicolon here to differentiate structs from functions

struct stru2 {
    int age;
    char name[30];  // a string
};
  
int main() {
    // Create a structure variable of myStructure called Struct1. This is an "object".
    // OOP convention is to capitalize objects, I think, but it's your decision ultimately.
    struct myStructure Struct1;
  
    // Assign values to members of the struct
    Struct1.num = 98;
    Struct1.letter = 'A';
  
    // Print
    printf("The number: %d\n", Struct1.num);
    printf("The letter: %c\n", Struct1.letter);

    // For stru2, there's a string in it. Sadly you can't just do stru2.name = "name";
    // since strings are arrays of characters. Get around that with the strcpy() function from <string.h>
    struct stru2 S2;
    S2.age = 44;
    strcpy(S2.name, "Billy Bob");

    // You can shorthand assign values too when instantiating the object:
    struct stru2 S3 = {57, "Johnny Johnson"};    // easier than strcpy

    printf("s2 age = %d \n s2 name = %s \n", S2.age, S2.name);
    printf("3 age = %d \n s3 name = %s \n", S3.age, S3.name);
    
    return 0;
  } 