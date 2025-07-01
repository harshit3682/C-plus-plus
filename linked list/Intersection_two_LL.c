#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *next;
};

void intersection(struct node **head1, struct node **head2)
{
        struct node *ptr = *head2;
        while (ptr != NULL)
        {
                struct node *temp = *head1;
                while (temp != NULL)
                {
                        if (temp->data == (ptr)->data)
                                printf("%d ", (ptr)->data);
                        temp = temp->next;
                }
                ptr = (ptr)->next;
        }
}

void insertatend(struct node **head, int data)
{
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
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
                struct node *p = *head;
                while (p->next != NULL)
                {
                        p = p->next;
                }
                p->next = ptr;
        }
}

void traversal(struct node **head)
{
        if (*head == NULL)
        {
                printf("None elements to display!");
                return;
        }
        struct node *ptr = *head;
        printf("Elements are as: ");
        while (ptr != NULL)
        {
                printf("%d ", ptr->data);
                ptr = ptr->next;
        }
}
int main()
{
        int ch;
        struct node *head1 = NULL;
        struct node *head2 = NULL;

        do
        {
                printf("\n\n1.Insert elements in head1\n2.Insert elements in head2 \n3.Display both L.L.\n");
                printf("4.Intersection\n5.Exit\n ");
                printf("Enter choice: ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                {
                        int n1, val, i = 0;
                        printf("\nEnter no. of elements: ");
                        scanf("%d", &n1);
                        while (i < n1)
                        {
                                printf("Value: ");
                                scanf("%d", &val);
                                insertatend(&head1, val);
                                i++;
                        }
                        break;
                }

                case 2:
                {
                        int n2, val1, j = 0;
                        printf("\nEnter no. of elements: ");
                        scanf("%d", &n2);
                        while (j < n2)
                        {
                                printf("Value: ");
                                scanf("%d", &val1);
                                insertatend(&head2, val1);
                                j++;
                        }
                        break;
                }

                case 3:
                        printf("\n\nElements of 1st Linked list: ");
                        traversal(&head1);
                        printf("\nElements of 2nd linked list: ");
                        traversal(&head2);
                        break;

                case 4:
                        printf("\nCommon elements are as: ");
                        intersection(&head1, &head2);

                        break;

                case 5:
                        printf("Exitting..");
                        exit(0);
                }
        } while (ch != 5);
}