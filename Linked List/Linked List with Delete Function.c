#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *createNodeNode(struct Node *head, int data)
{
	struct Node *newNode, *temp;

	newNode = (struct Node *)malloc(sizeof(struct Node));

	newNode->data = data;
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

void displayNodes(struct Node *head)
{
	struct Node *temp;
	temp = head;

	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

// Function to delete a node from the end
void deleteNode(struct Node *head)
{
	struct Node *temp, *prev;

	temp = head;

	while (temp->next != 0)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = 0;
	free(temp);
}

int main()
{
	struct Node *head;
	int choice = 1;
	int data;

	head = 0;

	while (choice == 1)
	{
		printf("Enter a value: ");
		scanf("%d", &data);

		head = createNodeNode(head, data);

		printf("Do you want to add more values?(0/1) ");
		scanf("%d", &choice);
	}

	printf("The values present in the Linked List: ");
	displayNodes(head);

	deleteNode(head); // Deleting a node from the end

	printf("\nThe Linked List after popping one item from the end: ");
	displayNodes(head);
}