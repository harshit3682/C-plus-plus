#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *left;
        struct node *right;
};
struct node *create_tree(struct node *root)
{
        int data;
        printf("\nEnter the data: ");
        scanf("%d", &data);

        if (data == -1)
        {
                return NULL;
        }

        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;

        printf("\nEnter the element in left of %d: ", data);
        root->left = create_tree(root->left);

        printf("\nEnter the element in right of %d: ", data);
        root->right = create_tree(root->right);
        return root;
}

void print_level_order(struct node *root)
{
        struct node *q[20];
        int front = 0, rear = 0;
        q[rear] = root; // enqueue(q, q->arr[q->front]);
        rear++;         // q->rear++;
        q[rear] = NULL; // q->arr[q->rear] = NULL;

        while (front != rear) // while (!is_empty(q))
        {
                struct node *temp = q[front]; // q->arr[q->front];
                front++;                      // dequeue(q);
                if (temp == NULL)
                {
                        // printf("hi1");
                        printf("\n");
                        if (front != rear) // if (!(is_empty(&q)))
                        {
                                rear++;
                                q[rear] = NULL;
                        }
                }

                else
                {
                        printf("%d ", temp->data);
                        if (temp->left != NULL)
                        {
                                rear++;
                                q[rear] = temp->left; // enqueue(q, temp->left);
                        }
                        if (temp->right != NULL)
                        {
                                rear++;
                                q[rear] = temp->right; // enqueue(q, temp->right);
                        }
                }
                // if (rear == 20)
                // {
                //         printf("\n");
                //         if (front != rear)
                //         {
                //                 q[rear++] = NULL;
                //         }
                // }
        }
} // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main()
{
        struct node *root = NULL;
        root = create_tree(root);

        printf("\nLevel order traversal of the tree is:\n ");
        print_level_order(root);

        return 0;
}