// Operating and maintaining a queue
#include <stdio.h>
#include <stdlib.h>

// self-referential structure                     
struct queueNode {                                   
   char data; // define data as a char            
   struct queueNode *nextPtr; // queueNode pointer
}; typedef struct queueNode QueueNode;


// function prototypes
void printQueue(QueueNode* currentPtr);
//int isEmpty(QueueNode* headPtr);
char dequeue(QueueNode* *headPtr, QueueNode* *tailPtr); // PREVIOUSLY WAS headPtr, WE CHANGED TO *headPtr as we needed to access it's contents not address WE DEREFERENCED
void enqueue(QueueNode* *headPtr, QueueNode* *tailPtr, char value);
void instructions(void);

// function main begins program execution
int main(void)
{ 
   QueueNode* headPtr = NULL; // initialize headPtr
   QueueNode* tailPtr = NULL; // initialize tailPtr
   char item; // char input by user

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's menu choice
   scanf("%u", &choice);

   // while user does not enter 3
   while (choice != 3) { 

      switch(choice) { 
         // enqueue value
         case 1:
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
         // dequeue value
         case 2:
            // if queue is not empty
            if (headPtr != NULL) { 
               item = dequeue(&headPtr, &tailPtr);
               printf("%c has been dequeued.\n", item);
            } 

            printQueue(headPtr);
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
   printf ("Enter your choice:\n"
           "   1 to add an item to the queue\n"
           "   2 to remove an item from the queue\n"
           "   3 to end\n");
} 

// insert a node at queue tail
void enqueue(QueueNode* *headPtr, QueueNode* *tailPtr, char value)
{ 
   QueueNode* newPtr; 
    
    newPtr= malloc(sizeof(QueueNode));

   if (newPtr != NULL) { // is space available 
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      // if empty, insert node at head
      if (*headPtr == NULL) {
        *headPtr = newPtr;
      } 
      else {
         (*tailPtr)->nextPtr = newPtr;
      } 

      *tailPtr = newPtr;
   } 
   else {

      printf("%c not inserted. No memory available.\n", value);
   } 
} 

// remove node from queue head
char dequeue(QueueNode* *headPtr, QueueNode* *tailPtr)
{ 

   char value = (*headPtr)->data;      
   
  /* 
	The error prevention code (headPtr != NULL)
        is in function main however
	you can also put it here
   */

   QueueNode* tempPtr = *headPtr;              
   *headPtr = (*headPtr)->nextPtr; // AS WE NOW HAVE ACCESS TO CONTENTS OF headPtr VARIABLE AS WE CHANGED ABOVE TO ALLOW THIS,
                                  // WE NOW ASSIGN THE CONTENTS OF headPtr to be nextPtr

   // if queue is empty
   if (*headPtr == NULL) {
      *tailPtr = NULL;
   } 

   free(tempPtr);
   return value;
} 

// print the queue
void printQueue(QueueNode* currentPtr)
{ 
   // if queue is empty
   if (currentPtr == NULL) {
      puts("Queue is empty.\n");
   } 
   else { 
      puts("The queue is:");

      // while not end of queue
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } 

      puts("NULL\n");
   } 
} 
