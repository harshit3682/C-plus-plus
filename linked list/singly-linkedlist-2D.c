#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert_first(struct Node **head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory not allocated!");
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        ptr->next = *head;
        *head = ptr;
    }

    printf("Inserted element=%d", ptr->data);
}
void insert_last(struct Node **head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory not allocated!");
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct Node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }

    printf("Inserted element=%d", ptr->data);
}
void insert_after_value_k(struct Node **head, int k)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory not allocated!");
        return;
    }
    int val;
    printf("\nEnter the value to be inserted in node: ");
    scanf("%d", &val);

    ptr->data = val;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        printf("\nInserted first value");
        return;
    }
    struct Node *temp = *head;
    while (temp != NULL && temp->data != k)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->data == k)
    {
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Node value inserted before %d(k)=%d", k, ptr->data);
    }
    else
    {
        printf("\nNode with value k not found,thus inserting at last.");
        insert_last(head, val);
    }
}
void insert_before_value_k(struct Node **head, int k)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory not allocated!");
        return;
    }
    int val;
    printf("\nEnter the value to be inserted in node: ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        printf("\nInserted first value");
        return;
    }
    if ((*head)->data == k)
    {
        ptr->next = *head;
        *head = ptr;
        printf("Node value inserted before %d(k)=%d", k, ptr->data);
        return;
    }

    struct Node *prev = *head;
    struct Node *temp = (*head)->next;
    while (temp != NULL && temp->data != k)
    {
        temp = temp->next;
        prev = prev->next;
    }
    if (temp != NULL && temp->data == k)
    {
        prev->next = ptr;
        ptr->next = temp;
        printf("Node value inserted before %d(k)=%d", k, ptr->data);
    }
    else
    {
        printf("\nNode value not found,thus inserting at front.\n");
        insert_first(head, val);
    }
}
void delete_first(struct Node **head)
{
    if (*head == NULL)
    {
        printf("None elements to delete!");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element=%d", temp->data);
    free(temp);
}
void delete_last(struct Node **head)
{
    if (*head == NULL)
    {
        printf("None elements to delete!");
        return;
    }
    if ((*head)->next == NULL)
    {
        printf("Deleted element=%d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    struct Node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted element=%d", temp->data);
    free(temp);
}
void delete_value_k(struct Node **head, int k)
{
    if (*head == NULL)
    {
        printf("None elements to delete!");
        return;
    }
    struct Node *prev = *head;
    struct Node *temp = (*head)->next;
    while (temp->data != k && temp->next != NULL)
    {
        temp = temp->next;
        prev = prev->next;
    }
    if (temp->data == k)
    {
        prev->next = temp->next;
        printf("Node value deleted=%d", temp->data);
        free(temp);
    }
    else
    {
        printf("\nNode value deleted at front.\n");
        delete_first(head);
    }
}

void traversal(struct Node **head)
{
    if (*head == NULL)
    {
        printf("None elements to display!");
        return;
    }
    struct Node *ptr = *head;
    int cnt=0;
    printf("Elements are as: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        cnt++;
    }
        printf("Count is: %d",cnt);

}
int main()
{
    struct Node *head = NULL;
    int ch, n1, n2, k;
    do
    {
        printf("\n\n1.Insert at front.\n2.Insert at last\n3.Delete from front\n");
        printf("4.Delete from last\n5.Delete with given value\n6.Insertion before value k\n");
        printf("7.Insertion after value K\n8.Display\n9.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &n1);
            insert_first(&head, n1);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &n2);
            insert_last(&head, n2);
            break;
        case 3:
            delete_first(&head);
            break;
        case 4:
            delete_last(&head);
            break;
        case 5:
            printf("Enter value whose node to be deleted: ");
            scanf("%d", &k);
            delete_value_k(&head, k);
            break;
        case 6:
            printf("Enter value before which new node to be inserted: ");
            scanf("%d", &k);
            insert_before_value_k(&head, k);
            break;
        case 7:
            printf("Enter value after which new node to be inserted: ");
            scanf("%d", &k);
            insert_after_value_k(&head, k);
            break;

        case 8:
            traversal(&head);
            break;
        case 9:
            printf("Exitting...");
            free(head);
        }
    } while (ch != 9);
}