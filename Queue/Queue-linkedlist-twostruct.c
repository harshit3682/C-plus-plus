#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front;
    struct node *rear;
} *q1;
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full!\n");
        return;
    }

    n->data = val;
    n->next = NULL;

    if (q1->front == NULL)
    {
        q1->front = q1->rear = n;
        printf(" \n%d is inserted into queue.", val);
    }
    else
    {
        q1->rear->next = n;
        q1->rear = n;
        printf(" \n%d is inserted into queue. ", val);
    }
}
int dequeue()
{
    if (q1->front == NULL)
    {

        printf("Queue is empty!\n");
        return 0;
    }
    else
    {
        struct node *temp = q1->front;
        int item = temp->data;
        q1->front = q1->front->next;
        free(temp);
        if (q1->front == NULL)
        {
            q1->rear = NULL;
        }
        return item;
    }
}
void frontelement()
{
    if (q1->front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front element= %d", q1->front->data);
}
void display()
{
    if (q1->front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("The elements are as: ");
    struct node *temp = q1->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    q1 = (struct queue *)malloc(sizeof(struct queue));
    q1->front = q1->rear = NULL;

    int ch, n, val;
    do
    {
        printf("\n\nQueue operations:\n1.Enqueue\n2.Dequeue\n3.Front Element\n4.Display\n5.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("Enter the value to enter: ");
            scanf("%d", &n);
            enqueue(n);
            break;

        case 2:
            val = dequeue();
            printf("The dequeued element is %d", val);

            break;

        case 3:
            frontelement();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exitting...");
            exit(0);
        }
    } while (ch != 5);
}