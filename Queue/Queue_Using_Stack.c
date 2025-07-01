#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push.\n");
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    else
    {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
}
