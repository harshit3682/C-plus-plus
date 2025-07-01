#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int *stack;
    int cap;
} *s1;
void initialize(int l)
{
    s1 = (struct Stack *)malloc(sizeof(struct Stack));
    s1->top = -1;
    s1->cap = l;
    s1->stack = (int *)malloc(l * sizeof(int));
}
int isfull()
{
    return s1->top == s1->cap - 1;
}
int isempty()
{
    return s1->top == -1;
}
int isoperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    return 0;
}
int isprecedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;

    case '*':
    case '/':
        return 2;
        break;

    case '^':
        return 3;
        break;

    default:
        return -1;
    }
}
int push(char ch)
{
    if (isfull())
    {
        printf("Stack is full\n");
        return -1;
    }
    s1->top++;
    s1->stack[s1->top] = ch;
}
int pop()
{
    if (isempty())
    {
        printf("stack is empty,can't pop.");
        return 1;
    }
    char temp = s1->stack[s1->top];
    s1->top--;
    return temp;
}
char *convert_infix_to_postfix(char *exp)
{
    int l = strlen(exp);
    initialize(l);
    int i = 0, j = -1;
    for (i, j; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (isoperand(exp[i]))
        {
            exp[++j] = exp[i];
        }
        else if (isoperator(exp[i]))
        {

            while (s1->top > -1 && isprecedence(s1->stack[s1->top]) >= isprecedence(exp[i]))
            {
                exp[++j] = pop();
            }
            push(exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (s1->top > -1 && s1->stack[s1->top] != '(')
            {
                exp[++j] = pop();
            }
            if (s1->top == -1 && s1->stack[s1->top] != '(')
            {
                return "Parentheses unmatched!\n";
                free(s1->stack);
                free(s1);
            }
            else
                s1->top--;
        }
    }
    while (!isempty())
    {
        if (s1->stack[s1->top] == '(')
        {
            return "Parentheses Unmatched , extra opening parentheses. ";
        }
        exp[++j] = pop();
    }
    exp[++j] = '\0';
    return exp;
}

void main()
{
    char expression[] = "(c*(a+b/d))";
    char *exp = convert_infix_to_postfix(expression);
    printf("%s", exp);
}