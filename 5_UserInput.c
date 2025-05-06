/* Compile and run commands:
    gcc 5_UserInput.c -o out
    out.exe
*/

#include <stdio.h>

int main() {

    int num;
    printf("Type a number, bro, then press enter (no error checking covered yet, so ints only): \n");
    
    // Get and save the number the user types
    scanf("%i", &num);  // the & points to the address of the variable, more on that in memory section.
    // scanf places user's integer input into num.
    
    // Output it
    printf("Your number is: %i, bro. \n", num);

    // another example:
    char letter;
    printf("Type a number AND a character (space between) and press enter, bro: \n");
    
    // do multiple at once
    scanf("%i %c", &num, &letter);
    
    printf("Your number is: %i\n", num);
    printf("Your character is: %c, bro\n", letter);

    // Input strings (no spaces, scanf ignores those):
    char name[30];  // we allocate 30 spots to be safe, but if the user has a really long name, it'll get cut off.

    printf("Enter your first name: \n");
    scanf("%s", &name);

    printf("Hi %s \n", name);

    // Strings with spaces with fgets:
    char fullName[30];

    printf("Type your full name, sir: \n");
    // Pause.
    // in C, input is stored in the input buffer.
    // so we did scanf for first name and the user pressed "enter".
    // that \n is still in the buffer since scanf ignores \n or \0's or spaces.
    // that means fgets will take that and roll with it, leaving fullName blank.
    // so we must clear the buffer with getchar();
    getchar();

    // now grab the whole line with fgets (\n from enter will come with!):
    fgets(fullName, sizeof(fullName), stdin);
    // fgets(pointer to string buffer, max chars to read, input stream (keyboard))
    printf("Hello %s", fullName);

    return 0;
}