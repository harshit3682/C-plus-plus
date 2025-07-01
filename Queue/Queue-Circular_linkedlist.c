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
int isempty(struct queue *q1)
{
    return q1->front == NULL;
}
void enqueue(struct queue *q1, int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full!");
        return;
    }
    n->data = val;
    n->next = NULL;
    if (isempty(q1))
    {
        q1->front = q1->rear = n;
        q1->rear->next = q1->front;
    }
    else
    {
        q1->rear->next = n;
        q1->rear = n;
        n->next = q1->front;
    }
    printf("\nInserted element= %d", val);
}
int dequeue(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("Queue is empty!");
        return -1;
    }
    struct node *temp = q1->front;
    int item = temp->data;
    if (q1->front == q1->rear)
    {
        q1->front = q1->rear = NULL;
    }
    else
    {
        q1->front = q1->front->next;
        q1->rear->next = q1->front;
    }
    free(temp);
    return item;
}
void front(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("Queue is empty!");
        return;
    }
    printf("\nFront element= %d", q1->front->data);
}
void display(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("Queue is empty!");
        return;
    }
    struct node *temp = q1->front;
    printf("The elements are as: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q1->front);
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
            enqueue(q1, n);
            break;

        case 2:
            val = dequeue(q1);
            printf("The dequeued element is %d", val);

            break;

        case 3:
            front(q1);
            break;

        case 4:
            display(q1);
            break;

        case 5:
            printf("Exitting...");
            free(q1);
            exit(0);
        }
    } while (ch != 5);
}