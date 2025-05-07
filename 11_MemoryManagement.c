/*
    As you may know, when a program is run, the binary is loaded from your hard drive
    to the RAM. If I do char letters[50] = "ABCDEFG";, that array takes up 50 memory
    bytes, despite not really needing to. Now that's not a whole lot given a lot of
    computers have 8 billion bytes (8GB) of RAM or more, but that's still memory
    that could be used by other running programs (processes). Memory management
    in C can be a real pain, but is powerful for optimization.
    They flew to the moon with less memory than a dang smart fridge.
*/

#include <stdio.h>
#include <stdlib.h>

void leakyFunction();

// Hey just FYI, this program probably has leaks in it. I demonstrate leaks and tried to clear it,
// but was in a hurry!
// Probably not a big deal, but very bad practice! Educational tho.

int main() {
    /*  So what I described above, with my 50 long char array, was called Static Memory, or "compile time" memory.
        However, we can allocate memory after the program starts running, only using what we need. This is
        called runtime memory or Dynamic Memory. Dynamic memory is only accessible with pointers.
        o allocate dynamic memory, you can use the malloc() or calloc() functions. 
        We need to include the <stdlib.h> header to use them.
        The malloc() and calloc() functions allocate some memory and return a pointer to its address.

        The malloc(size) function has one parameter, size, which specifies how much memory to allocate, measured in bytes.
        The calloc(amount, size) function has two parameters:
        amount - Specifies the amount of items to allocate
        size - Specifies the size of each item measured in bytes

        Unlike malloc(), the calloc() function writes zeroes into all of the allocated memory. 
        However, this makes calloc() slightly less efficient.
    */
   
    int *people;     // a pointer to the address of an int (which is 4 bytes)
    int numPeople = 12;
    people = calloc(numPeople, sizeof(*people)); // here, we are callocating memory for 12 ints, 4 bytes each.
    printf("We have %i people. Each one is assigned an int, so we allocated: %i bytes with calloc().\n", numPeople, numPeople * sizeof(*people)); 

    /*
    For completeness, it is worth mentioning stack memory. Stack memory is a type of dynamic memory which is
    reserved for variables that are declared inside functions. When a function is called, stack memory is
    allocated for the variables in the function. When the function returns the stack memory is freed.
    It is good to be aware of stack memory to be able to handle the memory usage of nested function calls
    and recursion. Recursion that repeats itself too many times may take up too much stack memory.
    When that happens it is called a stack overflow. Crazy how they named that after the website. /s
    */

    // Dynamic memory is similar to arrays where we access based on an index.
    int *ptr;
    ptr = calloc(4, sizeof(*ptr));  // our pointer is of integer type. we calloc 4 total spaces for the size of what the pointer points to (int, so 4 bytes)

    // Write to the memory - think of it as carving out a box of space in RAM
    *ptr = 2;   // equivalent to ptr[0], since ptr is just the start of the allocated memory
    ptr[1] = 4;
    ptr[2] = 6;

    // Read from the memory
    printf("ptr[0] is %i\n", *ptr);
    printf("and the rest are: %i %i %i \n", ptr[1], ptr[2], ptr[3]); 
    // notice how ptr[3] is 0, since we calloc'd it fills the space with 0's. if it didn't, we would get a null.

    // Different data types:
    // Dynamic memory has no type, it's just some bytes in RAM we carved out and reserved.
    // So the pointer itself tells C how to interpret the data (since it's all 1's and 0's in latches at the end of the day).

    int *ptr1 = malloc(4);  // this pointer holds the address of a block of 4 bytes we allocated with malloc (enough for an int)
    // Put another way: We're asking the computer for a small storage box (4 bytes) that can hold an integer,
    // and ptr1 is now a label that points to the location of that box.
    
    char *ptr2 = (char*) ptr1;  // pointer2 is now pointing to a spot for a char (1 byte for chars as we know)
    // the (char*) ptr1 is called a type cast. We're telling the compiler to treat the memory address stored
    // in ptr1 (which we originally thought of as pointing to an integer) as if it were the starting address of a sequence of characters.
    // put another way: We're now looking at the same storage box we got earlier, but instead of thinking of it
    // as one big integer container, we're now thinking of it as a container holding four smaller, 1-byte slots
    // that can each hold a character. ptr2 is a label that points to the beginning of this sequence of character slots.

    ptr1[0] = 1684234849;
    // We are storing this entire 4-byte integer value into the memory location pointed to by ptr1.

    printf("%i is %c %c %c %c \n", *ptr1, ptr2[0], ptr2[1], ptr2[2], ptr2[3]);
    // *ptr1 prints the value at the memory address. ptr2 array prints out how that 4-byte box was cut up into 1 byte values.
    // each 1 byte value in the box corresponds to a letter's ascii value. By interpreting it as a string, it prints the chars.

    // This is all a lot and is very tough to get. But the ability to carve out only the memory you need
    // is what makes C stand out

    // Reallocating: when you need more memory, you reallocate
    // It saves what's there and moves it to a bigger chunk of reserved memory
    int size = 8;
    int *ptr99 = realloc(ptr1, size);
    // pointer99 points to the start of the new allocation, pointer1 is the start of the old, and size is the new size in bytes.

    // realloc will return a NULL pointer if the new memory cannot be allocated (quite unlikely) but it's good practice to check
    if (ptr99 == NULL) {
        printf("Failed. Unable to resize memory");
    } else {
        printf("Success. %i bytes reallocated at address %p \n", size, ptr99);
        ptr1 = ptr99;  // Update ptr1 to point to the newly allocated memory
      }

    // Freeing memory:
    int *ptr3;  // make a pointer that points to an int (well actually it points nowhere right now, no memory is allocated, it's just prepped here)
    ptr3 = malloc(sizeof(*ptr3));    // allocate enough memory to store the size of what ptr3 points to (int)

    // code that uses ptr3 etc...

    // once finished, free it
    free(ptr3);

    // It's good practice to reset pointers to NULL to prevent accidentally using them and corrupting data that took that spot in RAM
    ptr3 = NULL;

    // Memory Leaks:
    // These happen when dynamic memory is allocated but not freed. 
    int x = 5;  // ok lets say X sits at address 57 (arbitrary madeup address)
    int *ptr4;
    ptr4 = calloc(2, sizeof(*ptr4));    // now we set ptr4 to point to 2 carved out slices of memory, each the size of what ptr4 points to (int)
    // let's say prt4 is pointing to address 62 (also made up) and it's allocated box goes 62-65, 66-69 as per calloc.
    free(ptr4); // Ignore this, I just don't want actual leaks.
    ptr4 = &x;      // now ptr4 points to address 57
    // and the allocated memory from 62-69 is lost (if you ignore the fact I freed it)

    // This can also happen within functions, memory allocated in a function will remain even after the funciton is run
    leakyFunction();    // see function for example
    printf("The function has ended.\n");

    // Leaks can also happen if realloc fails, it'll return a NULL pointer but the original memory stays allocated (good reason to check like in line 96)
    
    // A lot is going on here, but the final example in file 12_MemoryExample.c will be a "real world" sample from the textbook.

    // name pointers better than this btw, this is hard to read lmao
    free(people);
    free(ptr);
    free(ptr2);
    free(ptr99);
    people = NULL;
    ptr = NULL;
    ptr2 = NULL;
    ptr99 = NULL;

   return 0;
}

void leakyFunction() {
    int *ptr;
    ptr = malloc(sizeof(*ptr));
    printf("I am the leaky function, ending my run but not freeing memory! My variables are clear though.\n");
    free(ptr); // ignore this for memory leak example, I just don't want actual leaks.
  }