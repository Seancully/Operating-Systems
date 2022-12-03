// A simple stack program
#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct stackNode
{
   int data;                  // define data as an int
   struct stackNode *nextPtr; // stackNode pointer
};

typedef struct stackNode StackNode; // synonym for struct stackNode

// prototypes
void push(StackNode **topPtr, int info); // PREVIOUSLY WAS (*topPtr), NEEDED TO BE CHANGED TO (**topPtr) DOUBLE POINTER TO ACCESS CONTENTS OF PTR
                                        // NOT ADDRESS OF PTR WE DEREFERENCED BY ADDING A DOUBLE POINTER INSTEAD OF A NORMAL POINTER
int pop(StackNode **topPtr);
void printStack(StackNode *currentPtr);
void instructions(void);

// function main begins program execution
int main(void)
{
   StackNode *stackPtr = NULL; // points to stack top
   int value;                  // int input by user

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's menu choice
   scanf("%u", &choice);

   // while user does not enter 3
   while (choice != 3)
   {

      switch (choice)
      {
      // push value onto stack
      case 1:
         printf("%s", "Enter an integer: ");
         scanf("%d", &value);
         push(&stackPtr, value); // '&' WAS ADDED TO ALLOW THE PASSING OF StackPtr ADDRESS
         printStack(stackPtr);
         break;
      // pop value off stack
      case 2:
         // if stack is not empty
         if (stackPtr != NULL)
         {
            printf("The popped value is %d.\n", pop(&stackPtr));
         }

         printStack(stackPtr);
         break;
      default:
         puts("Invalid choice.\n");
         instructions();
         break;
      } // end switch

      printf("%s", "? ");
      scanf("%u", &choice);
   }

   puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
   puts("Enter choice:\n"
        "1 to push a value on the stack\n"
        "2 to pop a value off the stack\n"
        "3 to end program");
}

// insert a node at the stack top
void push(StackNode **tPtr, int info)
{
   StackNode *newPtr = malloc(sizeof(StackNode));

   // insert the node at stack top
   if (newPtr != NULL)
   {
      newPtr->data = info;
      newPtr->nextPtr = *tPtr;
      *tPtr = newPtr;
   }
   else
   { // no space available
      printf("%d not inserted. No memory available.\n", info);
   }
}

// remove a node from the stack top
int pop(StackNode **tPtr)
{
   StackNode *tempPtr = *tPtr;
   int popValue = (*tPtr)->data;
   *tPtr = (*tPtr)->nextPtr;
   free(tempPtr);
   return popValue;
}

// print the stack
void printStack(StackNode *currentPtr)
{
   // if stack is empty
   if (currentPtr == NULL)
   {
      puts("The stack is empty.\n");
   }
   else
   {
      puts("The stack is:");

      // while not the end of the stack
      while (currentPtr != NULL)
      {
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      puts("NULL\n");
   }
}


