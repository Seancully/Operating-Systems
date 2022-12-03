// // define a node; declare a node, assign a value to node, print contents of this node including the addres of this node all using functions,
// (basically Q1 of this lab but use functions)
#include <stdio.h>
#include <stdlib.h>

// self-referential structure                       
struct listNode 
{                                      
    int processID;
    int processStatus;
    int processCounter;
    int processAccumulator;
    int processAddress;
    int processPriority;
    struct listNode *nextPtr; // pointer to next node
}; typedef struct listNode ListNode; // synonym for struct listNode

void getData(struct listNode **);
void Display(struct listNode *);

int main(void)
{ 
//   ListNode* startPtr = NULL; // initially there are no nodes

    // create a node and add data to the node
    ListNode *newPtr = NULL; // create node

    getData(&newPtr);
    Display(newPtr);

    // printf("the address of newPtr (the variable that stores the location of the node is): %p\n", &newPtr); 
   
	return 0;
	
} 

void Display(struct listNode *node)
{
    printf("the address of the node is: %p\n\n",node);

	printf("the contents of the node: \n");
    printf("PCB ID: %d\n", node->processID);
    printf("Status (1 - ready; 2 - running; 3 - waiting): %d\n", node->processStatus);
    printf("The state of the process: \n");
    printf("Counter: %d\n", node->processCounter);
    printf("Accumulator: %d\n", node->processAccumulator);
    printf("Location: %d\n", node->processAddress);
    printf("Priority: %d\n", node->processPriority);

    printf("End of run.");

}

void getData(struct listNode **Node)
{
    int ID;
    int status;
    int counter;
    int accumulator;
    int address;
    int priority;

    // create a node and add data to the node
    *Node = malloc(sizeof(ListNode)); // create node
   
    // if nodes is created assign values to node
    if(*Node != NULL)
    {
        // enter a character
	    printf("PCB ID (1 to 3 digits, except 0): " );
	    scanf("%d",&ID);

        printf("PCB Status (1 - ready, 2 - running, 3 - waiting): " );
	    scanf("%d",&status);
   
        printf("Enter process counter: " );
	    scanf("%d",&counter);
   
        printf("Enter value of accumulator: " );
	    scanf("%d",&accumulator);
   
        printf("Enter the address location as integer: " );
	    scanf("%d",&address);
   
        printf("Enter priority (1 - high, 2 - low): " );
	    scanf("%d",&priority);

	    (*Node)->processID = ID;	
        (*Node)->processStatus = status;
        (*Node)->processCounter = counter;
        (*Node)->processAccumulator = accumulator;
        (*Node)->processAddress = address;
        (*Node)->processPriority = priority; 
	    (*Node)->nextPtr = NULL; // node does not link to another node
    }

}

