#include <stdio.h>
#include <stdlib.h>

// Declaring the structure of each node
struct Node
{
	int data;
	struct Node *next;
};

// Function to create a single node
struct Node *createNode(struct Node *head)
{
	struct Node *temp, *newNode;

	newNode = (struct Node *)(malloc(sizeof(struct Node)));

	printf("Enter data: ");
	scanf("%d", &newNode->data);

	newNode->next = 0;

	if (head == 0)
	{
		head = newNode;
	}
	else
	{
		temp = head;

		while (temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

	return head;
}

// Function to display all the nodes
void displayAllNodes(struct Node *head)
{
	struct Node *temp;

	temp = head;

	printf("The elements present in the Linked List are: ");

	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

// Function to count the number of nodes present in the Linked List
int countNodes(struct Node *head)
{
	struct Node *temp;
	int count = 0;

	temp = head;
	if (head == 0)
	{
		return 0;
	}

	while (temp != 0)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int main()
{
	struct Node *head;
	int n, i;
	head = 0;

	printf("Enter number of nodes you want to insert: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		head = createNode(head);
	}

	displayAllNodes(head);

	printf("\nNumber of elements present in the Linked List: %d", countNodes(head));
}