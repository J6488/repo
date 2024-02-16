#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int i = 0;
	//initialize length to 0
	node* tmp = head;
	//create temporary list equal to head
	//loops until end of list
	while(tmp != NULL){
		i++;
		//adds 1 to the length
		tmp = tmp->next;
		//moves to next node
	}
	return i;
	//once loops till end of list, all nodes have been counted and length is returned
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int listLength = length(head), i = 0;\
	//gets length of list and initialises i to 0
	char* string = (char*)malloc((listLength + 1) * sizeof(char));
	//allocates memory for string
	node* tmp = head;
	//creates temporary list equal to head
	//loops through list until end
	while(tmp != NULL){
		string[i] = tmp->letter;
		//sets string at position i to the character at the same position in list
		tmp = tmp->next;
		//moves to next node
		i++;
		//increments i
	}
	string[i] = '\0';
	//ends string with null character
	return string;
	//returns string from list
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newChar = (node*)malloc(sizeof(node));
	//initializes node of new character and allocates memory for it
	node* tmp = *pHead;
	//creates temporary node and sets it equal to the head pointer
	newChar->letter = c;
	//sets the new characters value to 'c'
	newChar->next = NULL;
	//new character points to nothing
	//checks if head pointer is null
	if(*pHead == NULL){
		*pHead = newChar;
		//points to the new charcter
	}
	else{
		//loops till end of list
		while(tmp->next != NULL){
			tmp = tmp->next;
			//passes through list
		}
		tmp->next = newChar;
		//at end of list insert the new charcter
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmp = *pHead;
	//initializes temporary node
	//loops till end of list
	while(tmp != NULL){
		node* tmpNext = tmp->next;
		//creates new node and sets it to the next temporary node
		free(tmp);
		//frees the temporary node
		tmp = tmpNext;
		//passes to next node
	}
	*pHead = NULL;
	//sets the head pointer to null
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}