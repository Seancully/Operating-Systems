// Nodes to store process control block
//  // define a node; declare a node, assign a value to node, print contents of this node including the addres of this node

#include <stdio.h>
#include <stdlib.h>

// self-referential structure
// Added PCB data into this structure
struct listNode
{
	int processID;
	int processStatus;
	int processCounter;
	int processAccumulator;
	int processAddress;
	int processPriority;
	struct listNode *nextPtr; // pointer to next node
};
typedef struct listNode ListNode; // synonym for struct listNode

int main(void)
{
	//   ListNode* startPtr = NULL; // initially there are no nodes
	// same var's as structure up above
	int ID;
	int Status;
	int Counter;
	int Accumulator;
	int Address;
	int Priority;

	// create a node and add data to the node
	ListNode *newPtr = malloc(sizeof(ListNode)); // create node

	// enter the values
	printf("PCB ID (1 to 3 digits, except 0) : ");
	scanf("%d", &ID);

	printf("PCB Status (1 - ready, 2 - running, 3 - waiting) : ");
	scanf("%d", &Status);

	printf("enter process counter : ");
	scanf("%d", &Counter);

	printf("enter value of accumulator : ");
	scanf("%d", &Accumulator);

	printf("enter the address location as integer : ");
	scanf("%d", &Address);

	printf("enter priority ( 1 - high, 2 - low) : ");
	scanf("%d", &Priority);

	printf("the address of the node is %p\n\n", *newPtr);

	// if nodes is created assign values to node ptr points to structures variables and assigns them values of main()'s user input for that var
	if (newPtr != NULL)
	{
		newPtr->processID = ID;
		newPtr->processStatus = Status;
		newPtr->processCounter = Counter;
		newPtr->processAccumulator = Accumulator;
		newPtr->processAddress = Address;
		newPtr->processPriority = Priority;
		newPtr->nextPtr = NULL; // node does not link to another node
	}

	// ***********************************print contents of node **********************************************

	printf("PCB ID: %d\n", ID);
	printf("status(1:ready;2 running;3 finished) : %d\n", Status);
	printf("the state of process\n");
	printf(" counter       : %d\n", Counter);
	printf(" accumulator \n");
	printf("Location : %d  %d\n", Accumulator, Address);
	printf("priority (1 high; 2 low) : %d\n", Priority);
	printf("End of run");

	return 0;
}
