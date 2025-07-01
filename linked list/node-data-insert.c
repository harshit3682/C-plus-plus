#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next, *prev;
};
struct node *create(int data)
{

    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    (new)->data = data;
    (new)->next = NULL;
    (new)->prev = NULL;

    // printf("%d", new->data);
}
int insertatstart(struct node **head, struct node **tail, int data)
{
    // int ptr;
    struct node *ptr = create(data);
}