#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
int insertbeforevalue(struct node **head, struct node **tail, int value, int data)
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

    struct node *temp = *head;
    //  struct node *temp1 = (*head)->next;
    // struct node *temp1 = NULL;

    while ((temp->data != value) && (temp != NULL))
    {
        temp = temp->next;
        // temp1 = temp1->next;
    }

    // temp1 = temp->prev;

    ptr->next = temp;
    ptr->prev = temp->prev;
    if (temp->prev != NULL)
    {
        temp->prev->next = ptr;
    }

    else
    {
        *head = ptr;
        return 0;
    }
    temp->prev = ptr->next;
}
int insertaftervalue(struct node **head, struct node **tail, int value, int data)
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

    struct node *temp = *head;
    //  struct node *temp1 = (*head)->next;
    struct node *temp1 = NULL;
    while ((temp->data != value) && (temp != NULL))
    {
        temp = temp->next;
        // temp1 = temp1->next;
    }
    temp1 = temp->next;
    if (temp1 != NULL)
    {
        ptr->prev = temp;
        ptr->next = temp1;
        temp->next = ptr;
        temp1->prev = ptr;
        return 1;
    }
    else
    {
        (*tail)->next = ptr;
        ptr->prev = *tail;
        *tail = (*tail)->next;
        return 0;
    }
}
int insertatendtail(struct node **head, struct node **tail, int data)
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

    if ((*head != NULL) || (*tail != NULL))
    {
        (*tail)->next = ptr;
        ptr->prev = *tail;
        *tail = (*tail)->next;
        return 1;
    }
    else
    {
        *head = ptr;
        *tail = ptr;
        return 0;
    }
}
int insertatend(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    // think a bit
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if ((*head != NULL) || (*tail != NULL))
    {
        temp->next = ptr;
        ptr->prev = temp;
        *tail = (*tail)->next;
        return 1;
    }
    else
    {
        *head = ptr;
        *tail = ptr;
        return 0;
    }
}

// Insert at start :
int insertatstart(struct node **head, struct node **tail, int data)
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
    if (!(*head))
    {
        // printf("\n 1 : %d", tail);
        *head = ptr;
        *tail = ptr;
        // printf("\n2: %d", tail);
        return 0;
    }
    // printf("\n %d", tail);
    ptr->next = *head;
    (*head)->prev = ptr;
    *head = ptr;
}

void print(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
void main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    insertatstart(&head, &tail, 3);
    printf("\nList after inserting at the start: ");
    print(&head);
    insertatstart(&head, &tail, 2);
    printf("\nList after inserting at the start: ");
    print(&head);
    insertatstart(&head, &tail, 1);
    printf("\nList after inserting at the start: ");
    print(&head);

    insertatend(&head, &tail, 8);
    printf("\n\nList after inserting at the end: ");
    print(&head);
    insertatend(&head, &tail, 9);
    printf("\nList after inserting at the end: ");
    print(&head);
    insertatendtail(&head, &tail, 10);
    printf("\nList after inserting at the end: ");
    print(&head);

    insertaftervalue(&head, &tail, 3, 4);
    printf("\n\nList after inserting after value: ");
    print(&head);
    insertaftervalue(&head, &tail, 4, 5);
    printf("\nList after inserting after value: ");
    print(&head);

    insertbeforevalue(&head, &tail, 8, 7);
    printf("\n\nList after inserting node before the value: ");
    print(&head);
    insertbeforevalue(&head, &tail, 7, 6);
    printf("\nList after inserting node before the value: ");
    print(&head);
}