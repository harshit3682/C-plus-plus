#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertaftervalue(struct node **head, struct node **tail, int k, int data)
{
    struct node *current = *head;
    while (current != NULL)
    {
        if (current->data == k)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            if (ptr != NULL)
            {
                ptr->data = data;

                ptr->next = current->next;
                current->next = ptr;
                if (current == *tail)
                {
                    *tail = ptr;
                }
                break;
            }
        }
        current = current->next;
    }
}
void insertBeforeValue(struct node **head, struct node **tail, int k, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    ptr->data = data;
    ptr->next = NULL;

    struct node *current = *head;
    struct node *prev = NULL;

    while (current != NULL && current->data != k)
    {
        prev = current;
        current = current->next;
    }

    // add node at the end if k is not found
    if (current == NULL)
    {
        if (*tail == NULL)
        {
            *head = ptr;
            *tail = ptr;
        }
        else
        {
            (*tail)->next = ptr;
            *tail = ptr;
        }
        return;
    }

    // If k is found, insert the new node before it
    if (prev == NULL)
    { // Insert at the beginning
        ptr->next = *head;
        *head = ptr;
    }
    else
    { // Insert before k node value
        prev->next = ptr;
        ptr->next = current;
    }
}

void insertatbegin(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr != NULL)
    {
        ptr->data = data;
        // ptr->next = NULL;

        ptr->next = *head;
        *head = ptr;
        if (*tail == NULL)
        {
            *tail = ptr;
        }
    }
}

void insertatend(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr != NULL)
    {
        ptr->data = data;
        ptr->next = NULL;

        if (*tail == NULL)
        {
            *head = ptr;
            *tail = ptr;
        }
        else
        {
            (*tail)->next = ptr;
            *tail = ptr;
        }
    }
}

void printList(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    insertatend(&head, &tail, 5);
    insertatend(&head, &tail, 10);
    insertatend(&head, &tail, 15);
    printf("\nList after inserting at the end: ");
    printList(head);

    insertatbegin(&head, &tail, 2);
    printf("\nList after inserting at the start: ");
    printList(head);

    insertBeforeValue(&head, &tail, 5, 24);
    printf("\nList before inserting  at value: ");
    printList(head);
    insertaftervalue(&head, &tail, 10, 65);
    printf("\nList after inserting at the value: ");
    printList(head);
}