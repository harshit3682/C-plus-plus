#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int cap;
    int size;
    int top;
    int *arr;
};
void initialize(struct stack *s1, int cap)
{
    s1->cap = cap;
    s1->size = 0;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(int));
}

int isfull(struct stack *s1)
{
    if (s1->cap == s1->size)
    {
        return 1;
    }
    return 0;
}

int isempty(struct stack *s1)
{
    if (s1->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s1, int val)
{
    if (isfull(s1))
    {
        printf("stack overflow ");
        // exit(0);
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
    printf("The value %d is inserted into the stack. ", val);
}
// void push(struct stack *s1, int elements[], int num)
// {
//     for (int i = 0; i < num; i++)
//     {
//         if (isfull(s1))
//         {
//             printf("Stack overflow! ");
//             return;
//         }

//         s1->top++;
//         s1->arr[s1->top] = elements[i];
//         s1->size++;
//         printf("Pushed %d onto the stack.\n", elements[i]);
//     }
// }

int pop(struct stack *s1)
{
    if (isempty(s1))
    {
        printf("Stack underflow");
        return 0;
    }
    int data = s1->arr[s1->top];
    s1->top--;
    s1->size--;
    return data;
}
void print(struct stack *s1)
{
    printf("The elements of stack are as: ");
    for (int i = 0; i <= s1->top; i++)
    {
        printf("%d ", s1->arr[i]);
    }
}

void main()
{
    struct stack ptr;
    // int elements[] = {1, 2, 3, 4, 5};
    // int num = sizeof(elements) / sizeof(elements[0]);

    int n, choice, temp, ele;
    printf("enter the capacity: ");
    scanf("%d", &n);
    initialize(&ptr, n);
    do
    {
        printf("\nStack Operations:\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit ");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element to insert into the stack: ");
            scanf("%d", &ele);
            push(&ptr, ele);
            // push(&ptr, elements, num);
            break;

        case 2:
            temp = pop(&ptr);
            if (temp)
            {
                printf("The popped out element is %d.", temp);
            }

            break;

        case 3:
            print(&ptr);

            break;

        case 4:
            printf("\nExiting...");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}