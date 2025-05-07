/* Compile and run commands:
    gcc 8_Files.c -o out
    out.exe
*/

#include <stdio.h>

int main() {

    // To open files, we create a pointer of type FILE:
    FILE *fptr;
    // then we use fopen to open it
    // fptr = fopen(filename, mode);
    // filename is the name of file and extension (must be in same directory as program, otherwise put the file path)
    // if you need filepath with backslashes, remember escape sequence \\
    // mode is either "r" for read, "w" for write, "a" for append (add data to existing)
    // if file does not exist, C creates it for you.
    fptr = fopen("sample.txt", "w");

    // Write to file (if existing data is there it'll be overwritten in 'w' mode):
    fprintf(fptr, "Some text from my program.\n");

    // Always close files when done to prevent leaks, data losses, etc.
    fclose(fptr);
    
    // Reading files:
    fptr = fopen("sample.txt", "r");

    // make an array to store file contents
    char contents[100]; // max leng 100

    // check if file exists, this is good practice when reading
    if(fptr != NULL) {

        // read the content into the string and print it
        while(fgets(contents, 100, fptr)) {
            printf("File says: %s\n", contents);
        }
      
    // if the file does not exist,
    } else {
        printf("Not able to open the file.\n");
    }
      
    // close
    fclose(fptr);

    // CSV's:
    /*
    CSV files, comma seperated values, are pretty useful
    you can open them in excel and use C to manipulate them
    Ex: Name, ID, Date
        John, 124, May 6
        Bill, 920, April 2
    could be a csv of strings.
    Below we make a csv, fill it with some numbers, and read them back in
    The trick is that we don't know the size of the CSV, so we use creative
    problem solving to make the program dynamically read the file.
    */

    // Writing CSV:
    FILE *fp = fopen("example.csv", "w");

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; j++) {
            fprintf(fp, "%i", j+i);   // write j+i to file
            if (j < 10 - 1) {
                fprintf(fp, ",");   // seperate by commas (minus one since the last number on row needs no comma, and indexing starts at 0)
            }
        }
        fprintf(fp, "\n"); // Add a newline for the next row
    }

    fclose(fp);
    printf("Numbers written to file successfully.\n");

    // Reading CSV:
    FILE *fp2 = fopen("example.csv", "r");
    if (fp2 == NULL) {
        perror("Error opening csv for reading");
    }

    int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];  // max buffer size. 1024 is a nice power of 2, but:
    // you need to adjust this based on the expected file length.
    // smaller buffer will conserve memory (ex embedded systems with low memory)
    // larger is faster because more all at once
    // but knowing what kind of input to expect, or constraining the input file size can be a good approach

    char character; 
    printf("Numbers read from %s:\n", "example.csv");
    while ((character = fgetc(fp2)) != EOF) {
        if (character == ',') {
            printf(" - "); // print dashes because why not
        } else if (character == '\n') {
            printf("\n"); // newline for row separation
        } else {
            printf("%c", character); // print each read character if not comma or \n
        }

    /*
    This is just one example. It's pretty tough if you don't know the type of data you're csv is
    or how long it may be, but stackoverflow is you're friend.
    C can get pretty hard to read at times, but that's due to shortcuts and optimizations.
    */
    }

    fclose(fp2);

    return 0;
}