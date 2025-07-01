#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};

int insertatbegin(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*head == NULL)
    {
        *head = ptr;
        *tail = ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
        return 0;
    }
    ptr->next = *head;
    ptr->prev = (*head)->prev;
    (*head)->prev->next = ptr;
    *head = ptr;
    (*tail) = (*head)->prev;
}
int insertatend(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*head == NULL)
    {
        *head = ptr;
        *tail = ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
        return 0;
    }
    ptr->prev = (*head)->prev;
    ptr->next = *head;
    (*head)->prev->next = ptr;
    (*head)->prev = ptr;
}

int insert_before_value(struct node **head, struct node **tail, int value, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*head == NULL)
    {
        *head = ptr;
        *tail = ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
        return 0;
    }
    struct node *temp = *head;
    do
    {
        if (temp->data == value)
        {
            break;
        }
        temp = temp->next;
    } while (temp != *head);
    ptr->next = temp;
    ptr->prev = temp->prev;
    temp->prev->next = ptr;
    temp->prev = ptr;
}
int insert_after_value(struct node **head, struct node **tail, int value, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*head == NULL)
    {
        *head = ptr;
        *tail = ptr;
        ptr->prev = ptr;
        ptr->next = ptr;
        return 0;
    }
    struct node *temp = *head;
    do
    {
        if (temp->data == value)
        {
            break;
        }
        temp = temp->next;
    } while (temp != *head);
    ptr->prev = temp;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    temp->next = ptr;
}

void print(struct node *head)
{
    struct node *temp = head;
    // way1:
    /*while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);*/

    // way2:
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    insertatbegin(&head, &tail, 3);
    printf("\n\nList after inserting at the start: ");
    print(head);
    insertatbegin(&head, &tail, 2);
    printf("\nList after inserting at the start: ");
    print(head);
    insertatbegin(&head, &tail, 1);
    printf("\nList after inserting at the start: ");
    print(head);

    insertatend(&head, &tail, 8);
    printf("\n\nList after inserting at the end: ");
    print(head);
    insertatend(&head, &tail, 9);
    printf("\nList after inserting at the end: ");
    print(head);
    insertatend(&head, &tail, 10);
    printf("\nList after inserting at the end: ");
    print(head);

    insertaftervalue(&head, &tail, 3, 4);
    printf("\n\nList after inserting node after the given value: ");
    print(head);
    insertaftervalue(&head, &tail, 4, 5);
    printf("\nList after inserting node after the given value: ");
    print(head);

    insertbeforevalue(&head, &tail, 8, 7);
    printf("\n\nList after inserting node before the given value: ");
    print(head);
    insertbeforevalue(&head, &tail, 7, 6);
    printf("\nList after inserting node before the given value: ");
    print(head);
}