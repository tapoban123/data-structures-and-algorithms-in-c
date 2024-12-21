#include <stdio.h>
#include <stdlib.h>

// Insertion happens from front end and deletion happens from rear end.

struct queue
{
    int front;
    int *values;
    int rear;
};

void enqueue(int x, struct queue *qu, int maxLength)
{
    if (qu->front == -1 && qu->rear == -1)
    {
        qu->rear = qu->front = 0;

        qu->values[qu->rear] = x;
    }
    else if (qu->rear == maxLength - 1)
    {
        // Here is the drawback of linear queue that is solved by circular queue.
        // We always update the front value of linear queue when we delete a value. 
        // So once a linear queue is full, it remains full forever, untill we remove all its value. 
        // Even after deleting elements from the front, we cannot insert a new element from the rear.
        printf("Overflow!");
    }
    else
    {
        qu->rear++;
        qu->values[qu->rear] = x;
    }
}

void dequeue(struct queue *qu)
{
    if (qu->front == -1 && qu->rear == -1)
    {
        printf("Underflow!");
    }
    else if (qu->front == qu->rear)
    {
        qu->front = qu->rear = -1;
    }
    else
    {
        qu->front++;
    }
}

void display(struct queue *qu)
{
    if (qu->front == -1 && qu->rear == -1)
    {
        printf("Empty queue!");
    }
    else
    {
        int i;

        printf("The values of the queue are:\n");
        for (i = qu->front; i < qu->rear + 1; i++)
        {
            printf("%d ", qu->values[i]);
        }
    }
}

void peek(struct queue *qu)
{
    if (qu->front == -1 && qu->rear == -1)
    {
        printf("Empty queue!");
    }
    else
    {
        printf("Top -> %d", qu->values[qu->front]);
    }
}

int main()
{
    struct queue qu;
    int maxLength = 5;

    qu.front = qu.rear = -1;
    qu.values = (int *)malloc(maxLength * sizeof(int));

    enqueue(21, &qu, maxLength);
    enqueue(52, &qu, maxLength);
    enqueue(3, &qu, maxLength);
    enqueue(10, &qu, maxLength);

    display(&qu);
    printf("\n");
    peek(&qu);
    printf("\n");

    dequeue(&qu);

    display(&qu);
}