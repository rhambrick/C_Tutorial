#include <stdio.h>
#include <stdlib.h>

struct list {
    int *data; // Points to the memory where the list items are stored
    int numItems; // Indicates how many items are currently in the list
    int size; // Indicates how many items fit in the allocated memory
  };
  
void addToList(struct list *MyList, int item);

int main() {
    struct list MyList;
    int amount;

    // Create a list and start with enough space for 10 items
    MyList.numItems = 0;
    MyList.size = 10;
    MyList.data = malloc(MyList.size * sizeof(int));

    // Find out if memory allocation was successful
    if (MyList.data == NULL) {
        printf("Memory allocation failed");
        return 1; // Exit the program
    }

    // Add however many items are in amount variable
    amount = 44;
    for (int i = 0; i < amount; i++) {
        addToList(&MyList, i + 1);  // addToList parameters are a pointer to a list struct, and an integer item
    }

    // Display the contents of the list
    for (int j = 0; j < MyList.numItems; j++) {
        printf("%d ", MyList.data[j]);
    }

    // Free the memory when it is no longer needed
    free(MyList.data);
    MyList.data = NULL;

    return 0;
    }

    // We are passing in the address of MyList and an item number.
    void addToList(struct list *MyList, int item) {

    // If the list is full then we will resize the memory to fit 10 more items
    // 10 is arbitrary. If you need to save memory like crazy, this can be 1 item at a time
    // But you can save processing power by increasing this to not have to run it so often
    // Tradeoffs between memory and speed.
    // MyList is a pointer and it points to a struct. MyList->numItems is similar to MyList.numItems.
    // I will comment more on that at the bottom.
    if (MyList->numItems == MyList->size) {
        MyList->size += 10;
        MyList->data = realloc( MyList->data, MyList->size * sizeof(int) );
    }

    // Add the item to the end of the list
    // Ex: if MyList has 0 items, the item goes at MyList[0].
    // then next time the item goes MyList[1]. etc.
    MyList->data[MyList->numItems] = item;
    MyList->numItems++;
}

/*
    Comment about MyList->numItems vs MyList.numItems:
    Say our function didn't bring in a pointer, it brought in the whole list:
    void addToList(struct list MyListInFunction, int item) {}
    In there we drag in a whole structure, which is fine and will work, but takes a good bit of processing power
    since that new structure is basically copied into the memory area of the function if that makes sense.
    Ex: MyList originally at address 450. addToList runs and MyListInFunction has the same stuff as MyList, but new address.
    Doing it that way means we have to return our MyListStruct and copy it over into MyList
    When we drag in a pointer to the list,
    void addToList(struct list *MyList, int item) {}
    We're able to set the pointer to the address of MyList, not needing to drag over a whole new structure to the funciton.
    Hopefully that makes sense, the function is able to directly manipulate our list instead of using a second one temporarily.

    I am no expert though, this could be a bad analogy.
    But that's it! I took a crash course on C and put all the code into files based on the chapters.
    This is the beginning of the powerful C language.

    Anyway I think I prefer C++. Bye bye!
*/