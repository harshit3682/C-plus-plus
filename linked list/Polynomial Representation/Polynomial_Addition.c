#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *insert(struct node *head, int coff, int exo)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff = coff;
    new->expo = exo;
    new->next = NULL;

    if (head == NULL || exo > head->expo)
    {
        new->next = head;
        head = new;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL && temp->expo > new->expo)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}

struct node *create()
{
    int n, e;
    int c;
    struct node *head = NULL;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nCoefficient = ");
        scanf("%d", &c);
        printf("Exponential power = ");
        scanf("%d", &e);

        head = insert(head, c, e);
    }
    return head;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
}

struct node *polyadd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr2->expo > ptr1->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }

    return head3;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("First polynomial:\n");
    head1 = create();

    printf("\nSecond polynomial:\n ");
    head2 = create();

    struct node *head3 = polyadd(head1, head2);
    printf("\nAdded polynomial is: ");
    print(head3);

    return 0;
}
