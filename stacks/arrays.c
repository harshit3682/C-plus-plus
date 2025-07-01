#include <stdio.h>

#define MAX_SIZE 100 // Maximum stack size

// Define the stack structure
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *ptr)
{
    ptr->top = -1; // Initialize the top index to -1
}

// Function to check if the stack is empty
int isEmpty(struct Stack *ptr)
{
    return ptr->top == -1;
}
// Function to check if the stack is full
int isFull(struct Stack *ptr)
{
    return ptr->top == MAX_SIZE - 1;
}

// taking elements at compile time
// Function to push an element onto the stack
// void push(struct Stack *ptr, int elements[], int numElements)
// {
//     for (int i = 0; i < numElements; i++)
//     {
//         if (isFull(ptr))
//         {
//             printf("Stack overflow! Cannot push %d.\n", elements[i]);
//             break;
//         }
//         else
//         {
//             ptr->top++;                         // Increment the top index
//             ptr->arr[ptr->top] = elements[i]; // Push the element onto the stack
//             printf("Pushed %d onto the ptr.\n", elements[i]);
//         }
//     }
// }

// taking elements one at a time
//  void push(struct Stack *ptr)
//  {
//      int element;
//      if (isFull(ptr))
//      {
//          printf("Stack overflow! Cannot push more elements.\n");
//      }
//      else
//      {
//          printf("Enter an element to push onto the stack: ");
//          scanf("%d", &element);
//          ptr->top++;                     // Increment the top index
//          ptr->arr[ptr->top] = element; // Push the element onto the stack
//          printf("Pushed %d onto the stack.\n", element);
//      }
//  }

// taking elements by loop
void push(struct Stack *ptr)
{
    int num;
    printf("enter the no. of elements to enter:\n");
    scanf("%d", &num);
    int elements[num];
    printf("enter the elements: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d element: ", i + 1);
        scanf("%d", &elements[i]);
    }
    for (int i = 0; i < num; i++)
    {
        if (isFull(ptr))
        {
            printf("Stack overflow! Cannot push %d.\n", elements[i]);
            break;
        }
        else
        {
            ptr->top++;                       // Increment the top index
            ptr->arr[ptr->top] = elements[i]; // Push the element onto the stack
            printf("Pushed %d onto the stack.\n", elements[i]);
        }
    }
}
void pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty. Cannot pop.\n");
    }
    else
    {
        int element = ptr->arr[ptr->top]; // Get the top element
        ptr->top--;                       // Decrement the top index
        printf("Popped %d from the stack.\n", element);
    }
}

// Function to display the entire stack
void display(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        int count = 0;
        printf("Stack elements: ");
        for (int i = 0; i <= ptr->top; i++)
        {
            count++;

            printf("%d ", ptr->arr[i]);
        }
        printf("\nCount: %d", count);
        printf("\n");
    }
}

int main()
{
    struct Stack ptr;
    initialize(&ptr);

    int choice;
    do
    {
        // int elements[] = {1, 2, 3, 4, 5};
        // int numElements = sizeof(elements) / sizeof(elements[0]);

        printf("\nStack Operations:\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Display stack\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //  push(&ptr, elements, numElements);
            push(&ptr);
            break;
        case 2:
            pop(&ptr);
            break;
        case 3:
            display(&ptr);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
