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

struct node *polymul(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    if (ptr1 == NULL && ptr2 == NULL)
    {
        printf("\nZero Polynomial\n");
        return head3;
    }

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    printf("\nBefore adding same power expressions:\n ");
    print(head3);

    struct node *ptr3 = head3;
    struct node *temp = NULL;
    while (ptr3->next != NULL)
    {
        if (ptr3->expo == ptr3->next->expo)
        {
            ptr3->coeff = ptr3->coeff + ptr3->next->coeff;
            temp = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(temp);
        }
        else
        {
            ptr3 = ptr3->next;
        }
    }

    // printf("\n\nFinal Multiplication Output:\n ");
    // print(head3);

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

    struct node *head3 = polymul(head1, head2);
    printf("\n\nFinal Multiplication Output:\n ");
    print(head3);

    return 0;
}
