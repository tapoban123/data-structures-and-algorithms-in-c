#include <stdio.h>
#include <stdlib.h>

// Declaring the structure of each node
struct node
{
	int data;
	struct node *next;
};

// Function to create a new node
struct node *createNewNode(struct node *head, struct node *lastNode)
{
	struct node *newNode;

	newNode = (struct node *)(malloc(sizeof(struct node))); // Allocating memory for new node

	printf("Enter data: ");
	scanf("%d", &newNode->data);

	if (head->data == 0)
	{
		head->data = newNode->data;
		return head;
	}
	else
	{
		lastNode->next = newNode;
		return newNode;
	}
}

// Display all nodes
void displayAllNodes(struct node *head)
{
	struct node *temp;

	temp = head;

	printf("The elements present in the Linked List are: ");

	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct node *head, *lastNode = 0;
	int n, i;

	head = (struct node *)(malloc(sizeof(struct node))); // Allocating memory for head node
	head->data = 0;

	printf("How many elements do you want to enter: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		lastNode = createNewNode(head, lastNode);
	}

	displayAllNodes(head);
}