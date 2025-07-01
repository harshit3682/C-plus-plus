#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct stack
{
    int size;
    int capacity;
    int *arr;
    int top1;
    int top2;
};
void initialize(struct stack *s1, int cap)
{
    s1->capacity = cap;
    s1->top1 = -1;
    s1->top2 = cap;
    s1->size = 0;
    s1->arr = (int *)malloc(cap * sizeof(int));
}

void push_first(struct stack *s1, int val)
{
    if ((s1->top2 - s1->top1) > 1)
    {
        s1->top1++;
        s1->arr[s1->top1] = val;
        s1->size++;
        printf("The element %d is inserted into the stack.", val);
    }
    else
    {
        printf("stack overflow");
        return;
    }
}
void push_last(struct stack *s1, int val)
{
    if ((s1->top2 - s1->top1) > 1)
    {
        s1->top2--;
        s1->arr[s1->top2] = val;
        s1->size++;
        printf("The element %d is inserted into the stack.", val);
    }
    else
    {
        printf("stack overflow");
        return;
    }
}
int isempty(struct stack *s1)
{
    if (s1->top1 == -1 && s1->top2 == s1->capacity)
    {
        printf("Stack is empty");
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop_start(struct stack *s1)
{
    if (isempty(s1))
    {
        return -1;
    }
    if (s1->top1 == -1)
    {
        printf("Stack pointing to front is empty\n");
        return -1;
    }
    int x = s1->arr[s1->top1];
    s1->top1--;
    s1->size--;
    return x;
}
int pop_end(struct stack *s1)
{
    if (isempty(s1))
    {
        return -1;
    }
    if (s1->top2 == s1->capacity)
    {
        printf("\nStack pointing to end is empty\n");
        return -1;
    }
    int x = s1->arr[s1->top2];
    s1->top2++;
    s1->size--;
    return x;
}
void display(struct stack *s1)
{
    if (isempty(s1))
    {
        return;
    }
    for (int i = 0; i < s1->size; i++)
    {
        printf("%d ", s1->arr[i]);
    }
}
void main()
{ // jab ptr lenge struct stack ka tab memory allocate karni padegi
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    int cap, ch, n, val;
    printf("Enter the capacity: ");
    scanf("%d", &cap);
    initialize(ptr, cap);
    do
    {
        printf("\n\nStack Operations:\n 1. Push at start\n 2. Push at end\n 3. Pop from front\n 4. Pop from end\n 5. Display\n 6. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &n);
            push_first(ptr, n);
            break;

        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &n);
            push_last(ptr, n);
            break;

        case 3:
            val = pop_start(ptr);
            printf("\nThe popped out element is %d", val);
            break;

        case 4:
            val = pop_end(ptr);
            printf("\nThe popped out element is %d", val);
            break;

        case 5:
            display(ptr);
            break;

        case 6:
            printf("\nExitting..");
            exit(0);

        default:
            printf("  Plz enter a valid choice ");
        }
    } while (ch != 6);
    getch();
}
