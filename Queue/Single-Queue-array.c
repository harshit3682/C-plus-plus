#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int *arr;
    int size;
    int capacity;
    int front;
    int rear;
};
void initialize(struct queue *q1, int cap)
{
    q1->capacity = cap;
    q1->size = 0;
    q1->front = -1;
    q1->rear = -1;
    q1->arr = (int *)malloc(cap * sizeof(int));
    if (q1->arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}
int isfull(struct queue *q1)
{
    if (q1->rear == q1->capacity - 1)
    {
        printf("Queue overflow : ");
        return 1;
    }
    return 0;
}
int isempty(struct queue *q1)
{
    if (q1->front == -1 || q1->front > q1->rear)
    {
        printf("Queue is empty: ");
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q1, int val)
{
    if (isfull(q1))
    {
        printf(" Memory not allocated.");
        return;
    }
    if (isempty(q1))
    {
        q1->front = 0;
        q1->rear = 0;
    }
    else
    {
        q1->rear++;
    }
    q1->arr[q1->rear] = val;
    printf("\nThe value %d is inserted into queue in index %d.", val, q1->rear);
}
int dequeue(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("Underflow ");
        return 0;
    }
    int item = q1->arr[q1->front];
    if (q1->front == q1->rear)
    {
        q1->front = -1;
        q1->rear = -1;
    }
    else
    {
        q1->front++;
    }

    return item;
}
void frontelement(struct queue *q1)
{
    printf("\nElement at front = %d\n Index = %d,", q1->arr[q1->front], q1->front);
}
void display(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("There are no elements in queue.");
        return;
    }
    printf("The elements are as: ");
    for (int i = q1->front; i <= q1->rear; i++)
    {
        printf("%d ", q1->arr[i]);
    }
}

void main()
{
    int cap, ch, n, val;
    printf("Enter the capacity: ");
    scanf("%d", &cap);
    struct queue ptr;
    initialize(&ptr, cap);
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
            enqueue(&ptr, n);
            break;

        case 2:
            val = dequeue(&ptr);
            printf("The dequeued element is %d", val);

            break;

        case 3:
            frontelement(&ptr);
            break;

        case 4:
            display(&ptr);
            break;

        case 5:
            printf("Exitting...");
            exit(0);
        }
    } while (ch != 5);
}