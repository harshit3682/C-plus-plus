#include <stdio.h>
#include <stdlib.h>
struct deque
{
    int *arr;
    int size;
    int capacity;
    int front;
    int rear;
} *d1;
void initialize(int cap)
{
    d1->size = 0;
    d1->capacity = cap;
    d1->front = d1->rear = -1;
    d1->arr = (int *)malloc(cap * sizeof(int));
}
int isfull()
{
    return d1->size == d1->capacity;
}
int isempty()
{
    return d1->front == -1;
}
void enqueuefront(int val)
{
    if (isfull())
    {
        printf("Queue is full!");
        return;
    }
    if (isempty())
    {
        d1->front = d1->rear = 0;
    }
    else if (d1->front == 0)
    {
        printf("Deque is full, Can't insert at front.");
        return;
    }
    else
    {
        d1->front--;
    }
    d1->size++;
    d1->arr[d1->front] = val;
    printf("Inserted element at front= %d", val);
}
void enqueuerear(int val)
{
    if (isfull())
    {
        printf("Queue is full!");
        return;
    }
    if (isempty())
    {
        d1->front = d1->rear = 0;
    }
    else if (d1->rear == d1->capacity - 1)
    {
        printf("Deque is full, can't insert at rear.");
        return;
    }
    else
    {
        d1->rear++;
    }
    d1->size++;
    d1->arr[d1->rear] = val;
    printf("Element inserted at rear= %d", val);
}
void dequeuefront()
{
    if (isempty())
    {
        printf("DEque is empty!");
        return;
    }
    int item = d1->arr[d1->front];
    if (d1->front == d1->rear)
    {
        d1->front = -1;
        d1->rear = -1;
    }
    else
    {
        d1->front++;
    }
    d1->size--;
    printf("Dequeued element from front=%d", item);
}
void dequeuerear()
{
    if (isempty())
    {
        printf("DEque is empty!");
        return;
    }
    int item = d1->arr[d1->rear];
    if (d1->front == d1->rear)
    {
        d1->front = -1;
        d1->rear = -1;
    }
    else
    {
        d1->rear--;
    }
    d1->size--;
    printf("Dequeued element from rear=%d", item);
}
void front()
{
    if (isempty())
    {
        printf("DEque is empty!");
        return;
    }
    printf("Front element =%d", d1->arr[d1->front]);
}
void display()
{
    if (isempty())
    {
        printf("DEque is empty!");
        return;
    }
    int i;
    printf("The elements are as: ");
    for (i = d1->front; i <= d1->rear; i++)
    {
        printf("%d ", d1->arr[i]);
    }
}

void input_deque()
{
    int n1;
    int choice;
    do
    {
        printf("\n\n1.Insert at rear\n");
        printf("2.Delete from front\n");
        printf("3.Delete from rear\n");
        printf("4.Front\n");
        printf("5.Display\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &n1);
            enqueuerear(n1);
            break;
        case 2:
            dequeuefront();
            break;
        case 3:
            dequeuerear();
            break;
        case 4:
            front();
            break;
        case 5:
            display();
            break;

        case 6:
            printf("Exitting...");
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 6);
}
/*End of input_que*/

/*Begin of output_que*/
void output_deque()
{
    int n1, n2;
    int choice;
    do
    {
        printf("\n\n1.Insert at rear\n");
        printf("2.Insert at front\n");
        printf("3.Delete from front\n");
        printf("4.Display\n");
        printf("5.Front\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &n1);
            enqueuerear(n1);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &n2);
            enqueuefront(n2);
            break;
        case 3:
            dequeuefront();
            break;
        case 4:
            display();
            break;
        case 5:
            front();
            break;
        case 6:
            printf("Exitting...");
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 6);
}
/*End of output_que*/

/*Begin of main*/
void main()
{
    int cap;
    printf("\nEnter the capacity: ");
    scanf("%d", &cap);
    d1 = (struct deque *)malloc(sizeof(struct deque));
    initialize(cap);
    int choice;
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("3.Exit");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        input_deque();
        break;
    case 2:
        output_deque();
        break;
    case 3:
        printf("Exitting:");
        exit(0);
    default:
        printf("Wrong choice\n");
    }
}