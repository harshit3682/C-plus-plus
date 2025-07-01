#include <stdio.h>
#include <stdlib.h>
struct node
{
        int data;
        struct node *left;
        struct node *right;
};

struct node *createNode(int data)
{
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
}
struct node *insertNode(struct node *root, int val)
{

        if (root == NULL)
                return createNode(val);

        else if (val > root->data)
                root->right = insertNode(root->right, val);

        else
                root->left = insertNode(root->left, val);

        return root;
}

void searchTree(struct node *root, int val)
{
        if (root == NULL)
        {
                printf("Value not found");
                return;
        }
        if (val == root->data)
        {
                printf("%d is present", val);
                return;
        }
        else if (val < root->data)
        {
                searchTree(root->left, val);
        }
        else
        {
                searchTree(root->right, val);
        }
}

struct node *minimumNode(struct node *root)
{
        if (root == NULL)
        {
                return NULL;
        }
        else if (root->left != NULL)
        {
                return minimumNode(root->left);
        }
        return root;
}
struct node *deleteNode(struct node *root, int val)
{
        if (root == NULL)
        {
                printf("\nNo such Node present with value %d", val);
                return root;
        }
        if (val > root->data)
                root->right = deleteNode(root->right, val);
        else if (val < root->data)
                root->left = deleteNode(root->left, val);
        else
        {
                // Leaf Node
                if (root->left == NULL && root->right == NULL)
                {
                        printf("\n\nThis[%d] is leaf Node..", val);
                        free(root);
                        return NULL;
                }
                // One Child Node
                else if (root->left == NULL || root->right == NULL)
                {
                        if (root->left != NULL) // root->right is NULL
                        {
                                struct node *temp = root->left;
                                free(root);
                                return temp;
                        }
                        else // root->left is NULL
                        {
                                struct node *temp = root->right;
                                free(root);
                                return temp;
                        }
                }
                // Two Child Node
                else
                {
                        struct node *temp = minimumNode(root->right);
                        root->data = temp->data;
                        root->right = deleteNode(root->right, temp->data);
                }
        }
        return root;
}

void inorder(struct node *root)
{
        if (root != NULL)
        {
                inorder(root->left);
                printf(" %d ", root->data);
                inorder(root->right);
        }
}
void print_level_order(struct node *root)
{
        printf("\n");
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
        }
}
void main()
{
        struct node *root = NULL;
        root = createNode(100);
        // insertNode(root, 100);
        insertNode(root, 20);
        insertNode(root, 200);
        insertNode(root, 10);
        insertNode(root, 30);
        insertNode(root, 150);
        insertNode(root, 300);
        // insertNode(root, 4);
        // insertNode(root, 9);
        // insertNode(root, 6);
        searchTree(root, 30);

        printf("\nINORDER TRAVERSAL: ");
        inorder(root);
        printf("\nLEVEL ORDER TRAVERSAL:");
        print_level_order(root);

        // deleteNode(root, 150);
        deleteNode(root, 20);
        deleteNode(root, 1);

        printf("\n\n\nINORDER TRAVERSAL: ");
        inorder(root);
        printf("\nLEVEL ORDER TRAVERSAL:");
        print_level_order(root);
        // deleteNode(root, 17);
        // deleteNode(root, 6);

        // inorder(root);
        // print_level_order(root);
}