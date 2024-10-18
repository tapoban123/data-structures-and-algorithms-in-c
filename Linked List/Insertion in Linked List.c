#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

int countAllNodes(struct Node *head)
{
	struct Node *temp;
	int count = 0;
	temp = head;

	while (temp != 0)
	{
		temp = temp->next;
		count++;
	}

	return count;
}

struct Node *insertAtBeginning(struct Node *head)
{
	struct Node *newNode;

	newNode = (struct Node *)(malloc(sizeof(struct Node)));

	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);

	newNode->next = head;

	return newNode;
}

void insertAtEnd(struct Node *head)
{
	struct Node *newNode, *temp;

	newNode = (struct Node *)(malloc(sizeof(struct Node)));

	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);

	newNode->next = 0;

	temp = head;

	while (temp->next != 0)
	{
		temp = temp->next;
	}

	temp->next = newNode;
}

void insertAfterSpecificPosition(struct Node *head, int pos)
{
	struct Node *temp, *newNode;
	int count = 1, numOfNodes;

	temp = head;
	newNode = (struct Node *)(malloc(sizeof(struct Node)));

	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);
	newNode->next = 0;

	while (count < pos)
	{
		temp = temp->next;
		count++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void displayAllNodes(struct Node *head)
{
	struct Node *temp;
	int numOfNodes;

	numOfNodes = countAllNodes(head);

	if (numOfNodes == 0)
	{
		printf("No data present in Linked List.");
	}
	else
	{
		temp = head;
		printf("The values present in the Linked List: ");
		while (temp != 0)
		{
			printf("%d ", temp->data);
			;
			temp = temp->next;
		}
	}
}

void menu()
{
	printf("OPERATIONS:");
	printf("\nEnter 1 to add a node at the beginning.");
	printf("\nEnter 2 to add a node at the end.");
	printf("\nEnter 3 to add a node after a given position.");
	printf("\nEnter 4 to display data of all the nodes.");
	printf("\nEnter 5 to view the number of nodes.");
	printf("\nEnter 6 to Exit.");
}

int main()
{
	struct Node *head;
	int choice, pos, numOfNodes;

	head = (struct Node *)(malloc(sizeof(struct Node)));

	printf("Enter data for head node: ");
	scanf("%d", &head->data);

	head->next = 0;

	menu();

	while (choice > 0 || choice <= 5)
	{
		numOfNodes = countAllNodes(head);

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			head = insertAtBeginning(head);
		}
		else if (choice == 2)
		{
			insertAtEnd(head);
		}
		else if (choice == 3)
		{
			if (numOfNodes == 0)
			{
				printf("You cannot insert a node in an empty Linked List.");
			}
			else
			{
				printf("Enter the position where you want to insert: ");
				scanf("%d", &pos);
				printf("%d", numOfNodes);
				if (pos > 0 && pos <= numOfNodes)
				{

					insertAfterSpecificPosition(head, pos);
				}
				else
				{
					printf("Invalid position.");
				}
			}
		}
		else if (choice == 4)
		{
			displayAllNodes(head);
		}
		else if (choice == 5)
		{
			printf("Number of nodes present in the Linked List = %d", countAllNodes(head));
		}
		else if (choice == 6)
		{
			printf("Program executed Successfully.");
			break;
		}
		else
		{
			printf("Invalid choice. Exiting program.");
			break;
		}
	}
}