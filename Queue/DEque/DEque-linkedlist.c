#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct deque
{
    struct node *front;
    struct node *rear;
} *d1;
int isempty()
{
    return d1->front == NULL;
}
void enqueue_front(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("DEque is full");
        return;
    }
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    if (isempty())
    {
        d1->front = d1->rear = n;
        // n->next = n;
        // n->prev = n;
    }
    else
    {
        n->next = d1->front;
        //  n->prev = d1->rear;
        // d1->rear->next = n;
        d1->front->prev = n;
        d1->front = n;
        // d1->rear = d1->rear->next;
    }
    printf("Inserted node value=%d", val);
}
void enqueue_rear(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("DEque is full");
        return;
    }
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    if (isempty())
    {
        d1->front = d1->rear = n;
        // n->next = n;
        // n->prev = n;
    }
    else
    {
        // n->next = d1->rear->next;
        n->prev = d1->rear;
        d1->rear->next = n;
        // d1->front->prev = n;
        d1->rear = n;
    }
    printf("Inserted node value=%d", val);
}
void dequeue_front()
{
    if (isempty())
    {
        printf("DEque is empty!");
        return;
    }
    struct node *temp = d1->front;
    if (d1->front == d1->rear)
    {
        d1->front = NULL;
        d1->rear = NULL;
    }
    else
    {
        d1->front = d1->front->next;
        // d1->rear->next = d1->front;
        d1->front->prev = NULL;
    }
    printf("Dequeued element from front=%d", temp->data);
    free(temp);
}
void dequeue_rear()
{
    if (isempty())
    {
        printf("DEque is empty!");
        return;
    }
    struct node *temp = d1->rear;
    if (d1->front == d1->rear)
    {
        d1->front = NULL;
        d1->rear = NULL;
    }
    else
    {
        d1->rear = d1->rear->prev;
        d1->rear->next = NULL;
    }
    printf("Dequeued element from rear=%d", temp->data);
    free(temp);
}
void front()
{
    if (isempty())
    {
        printf("Deque is empty, can't find front.\n");
        return;
    }
    printf("\nThe front element is: %d ", d1->front->data);
}
void display()
{
    struct node *ptr = d1->front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void main()
{
    d1 = (struct deque *)malloc(sizeof(struct deque));
    d1->front = d1->rear = NULL;
    int choice, n1, n2;
    do
    {
        printf("\n\n1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete from front\n");
        printf("4.Delete from rear\n");
        printf("5.Front\n");
        printf("6.Display\n");
        printf("7.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &n2);
            enqueue_front(n2);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &n1);
            enqueue_rear(n1);
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            front();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exitting...");
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 7);
}
