#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int capacity;
    int size;
    int *arr;
    int front;
    int rear;
};
void initialize(struct Queue *q1, int cap)
{
    q1->capacity = cap;
    q1->size = 0;
    q1->front = q1->rear = -1;
    q1->arr = (int *)malloc(cap * sizeof(int));
}

// Function to check if the q1 is empty
int isempty(struct Queue *q1)
{
    return (q1->front == -1);
}

// Function to check if the q1 is full
int isfull(struct Queue *q1)
{
    return ((q1->rear + 1) % q1->capacity == q1->front);
}

// Function to enqueue an element into the q1
void enqueue(struct Queue *q1, int value)
{
    if (isfull(q1))
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    else
    {
        if (isempty(q1))
        {
            q1->front = 0;
            q1->rear = 0;
        }
        else
        {
            q1->rear = (q1->rear + 1) % q1->capacity;
        }
        q1->arr[q1->rear] = value;
        printf("The element %d is inserted into queue. ", value);
    }
}

// Function to dequeue an element from the q1
int dequeue(struct Queue *q1)
{
    int value;
    if (isempty(q1))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value
    }
    else
    {
        value = q1->arr[q1->front];
        if (q1->front == q1->rear)
        {
            q1->front = -1;
            q1->rear = -1;
        }
        else
        {
            q1->front = (q1->front + 1) % q1->capacity;
        }
        return value;
    }
}
void front(struct Queue *q1)
{
    if (isempty(q1))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nThe front most element is %d at index %d", q1->arr[q1->front], q1->front);
}
// void display(struct Queue *q1)
// {
//     printf("The elements are as: ");
//     if (q1->front < q1->rear)
//     {
//         for (int i = q1->front; i <= q1->rear; i++)
//         {
//             printf("%d ", q1->arr[i]);
//         }
//     }
//     else
//     {
//         for (int i = 0; i <= q1->rear; i++)
//         {
//             printf("%d ", q1->arr[i]);
//         }
//         for (int i = q1->front; i <= q1->capacity - 1; i++)
//         {
//             printf("%d ", q1->arr[i]);
//         }
//     }
// }
void display(struct Queue *q1)
{
    printf("The elements are as: ");
    if (q1->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = q1->front;
    do
    {
        printf("%d ", q1->arr[i]);
        i = (i + 1) % q1->capacity;
    } while (i != (q1->rear + 1) % q1->capacity);
    printf("\n");
}
void deallocate(struct Queue *q1)
{
    free(q1->arr);
}
void main()
{
    int cap, n, val, ch;
    struct Queue ptr;
    printf("Enter the capacity: ");
    scanf("%d", &cap);
    initialize(&ptr, cap);

    do
    {
        printf("\n\nStack Operations:");
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &n);
            enqueue(&ptr, n);
            break;
        case 2:
            val = dequeue(&ptr);
            printf("The popped out element is %d.", val);
            break;
        case 3:
            front(&ptr);
            break;
        case 4:
            display(&ptr);
            break;
        case 5:
            printf("Exiting....");
            deallocate(&ptr);
            exit(0);
        default:
            printf("Plz enter a valid choice..");
        }
    } while (ch != 5);
}