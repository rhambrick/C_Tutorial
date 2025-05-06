/* Compile and run commands:
    gcc 6_MemoryAndPointers.c -o out
    out.exe
*/

#include <stdio.h>

int main() {

    /* I could go on about RAM circuits for a while but I won't here,
    just know that RAM is oraganized like a street grid,
    every byte has an address and when the address wires are turned on
    the data at that addy is output.
    */
    int age = 42;
    printf("age is actually: %i \n", age);
    printf("age is stored at address: %p \n", &age); // Outputs a hex number. %p is for pointers.
    // &age is a pointer which points to the address of that data.

    // Dereferencing pointers:
    int myAge = 30;     // declaring the variable
    int* ptr = &myAge;  // declaring the pointer, this variable stores the address
    
    printf("%p\n", ptr);    // this is a reference, it outputs the address
    printf("%i\n", *ptr);   // this is a dereference, outputting the data the pointer is pointing to

    printf("\n");

    // Pointers and arrays:
    int nums[4] = {2, 4, 8, 16};

    // Array variables are actually pointers to the first element
    printf("nums array starts at: %p\n", &nums[0]);
    printf("*nums is nums[0] which = %i\n", *nums);
    
    // Arrays are stored sequentially in RAM, so incrementing the pointer gets the next element:
    printf("*(nums + 1) is: %i (which is just nums[1]).\n", *(nums + 1));
    printf("nums[2] is: %i \n", *(nums + 2));
    printf("nums[3] is: %i \n", *(nums + 3));

    // Can use pointers to change the value of elements too
    *nums = 9;
    // second element, etc.
    *(nums + 1) = 10;

    printf("\n");

    // use pointer to print by moving it around:
    int *pointer = nums;    // note how we don't need &nums since nums is an array, it actually is already the address of nums[0]
    int i;
    for (i = 0; i < 4; i++) {
      printf("pointer is pointinng to: %i \n", *(pointer + i));
    }

    // pointers are kinda tricky and seem overkill, but it's "closer to hardware" and therfore has tons of advantages.
    // pointers are fast and require less code in general.
    // data structures like linked lists can benefit heavily from pointers
    // but if used wrong, they can mess things up for sure...
    // getting comfy with pointers is critical for C and provides huge power.

    return 0;
}