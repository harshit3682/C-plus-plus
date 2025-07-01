#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

struct stack *createnode(int data)
{
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    if (new == NULL)
    {
        printf("Stack overflow : memory not allocated");
    }
    new->data = data;
    new->next = NULL;
    return new;
}

int isempty(struct stack *s1)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s1, int data)
{
    // struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    struct stack *new = createnode(data);
    if (new == NULL)
    {
        printf("Stack overflow");
        exit(0);
    }

    // new->data = data;
    new->next = top;
    top = new;

    printf("The node with element %d is inserted into stack.", data);
}
int pop(struct stack *s2)
{
    if (isempty(s2))
    {
        printf("Stack underflow\n");
    }
    // struct stack *n = s2;
    // int val = n->data;
    // top = s2->next;
    // free(n);
    // return val;
    struct stack *n = s2;
    top = (s2)->next;
    int x = n->data;
    free(n);
    return x;
}
void display(struct stack *s1)
{
    //  struct stack *temp = s1;
    printf("\nThe elements are as : ");
    while (s1 != NULL)
    {
        printf("%d ", s1->data);
        s1 = s1->next;
    }
}
void main()
{
    int ch, n, val;
    // struct stack *ptr = NULL;
    do
    {
        printf("\n\nStack Operations:\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit ");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &n);
            push(top, n);
            break;

        case 2:
            val = pop(top);
            printf("\nThe popped out element is %d", val);
            break;

        case 3:
            display(top);
            break;

        case 4:
            printf("\nExitting..");
            exit(0);

        default:
            printf("  Plz enter a valid choice ");
        }
    } while (ch != 4);
}