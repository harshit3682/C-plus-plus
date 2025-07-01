#include <stdio.h>
#include <stdlib.h>
struct node
{
        int data;
        struct node *left;
        struct node *right;
};
struct queue
{
        struct node **arr;
        int cap;
        int front;
        int rear;
};
void initialize(struct queue **q, int cap)
{
        (*q)->cap = cap;
        (*q)->front = 0;
        (*q)->rear = 0;
        (*q)->arr = (struct node **)malloc(((*q)->cap) * sizeof(struct node *));
        for (int i = 0; i < cap; i++)
        {
                (*q)->arr[i] = NULL;
        }
}
struct node *insert_tree(struct node *root)
{
        int data;
        printf("\nEnter the data: ");
        scanf("%d", &data);

        if (data == -1)
        {
                return NULL;
        }

        root = (struct node *)malloc(sizeof(struct node));
        if (root == NULL)
        {
                printf("Memory not allocated!");
                exit(0);
        }
        root->data = data;

        printf("\nEnter the data to left of node %d", root->data);
        root->left = insert_tree(root->left);

        printf("\nEnter the data to right of node %d", root->data);
        root->right = insert_tree(root->right);

        return root;
}
void print_level_order(struct node *root, struct queue *q)
{
        q->arr[q->rear] = root;
        q->rear++;

        while (q->front != q->rear)
        {
                struct node *temp = q->arr[q->front];
                q->front++;

                if (temp == NULL)
                {
                        printf("\n");
                        if (q->front != q->rear)
                        {
                                q->rear++;
                                q->arr[q->rear] = NULL;
                        }
                }
                else
                {

                        printf("%d ", temp->data);
                        if (temp->left != NULL)
                        {
                                q->rear++;
                                q->arr[q->rear] = temp->left;
                        }
                        if (temp->right != NULL)
                        {
                                q->rear++;
                                q->arr[q->rear] = temp->right;
                        }
                }
        }
} // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// Printing elements in a  ROW:
/*void print_level_order(struct node *root, struct queue *q)
{
        q->arr[q->rear] = root;
        q->rear++;
        printf("\nElements: ");
        while (q->front != q->rear)
        {
                struct node *temp = q->arr[q->front];
                q->front++;
                printf("%d ", temp->data);
                if (temp->left != NULL)
                {
                        q->arr[q->rear] = temp->left;
                        q->rear++;
                }
                if (temp->right != NULL)
                {
                        q->arr[q->rear] = temp->right;
                        q->rear++;
                }
        }
}*/
void main()
{
        int cap;

        struct queue *q;
        printf("Enter the no. of elements to insert in tree: ");
        scanf("%d", &cap);
        initialize(&q, cap);

        struct node *root = NULL;
        root = insert_tree(root);

        printf("\nLevel order traversal of the tree is:\n ");
        print_level_order(root, q);
}