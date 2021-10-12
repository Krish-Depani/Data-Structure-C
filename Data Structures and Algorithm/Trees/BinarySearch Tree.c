#include "stdio.h"
#include "stdlib.h"

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node NODE;
NODE *root = NULL;

NODE *insertElement(NODE *, int);
void preorderTraversal(NODE *);
void inorderTraversal(NODE *);
void postorderTraversal(NODE *);
NODE *findSmallestElement(NODE *);
NODE *findLargestElement(NODE *);
NODE *deleteElement(NODE *, int);
NODE *mirrorImage(NODE *);
int totalNodes(NODE *);
int totalExternalNodes(NODE *);
int totalInternalNodes(NODE *);
int Height(NODE *);
NODE *deleteTree(NODE *);
NODE *minvaluenode(NODE *);

int main()
{
    int option, val;
    NODE *ptr;

    do
    {
        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Find the smallest element");
        printf("\n 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\n 8. Count the total number of nodes");
        printf("\n 9. Count the total number of external nodes");
        printf("\n 10. Count the total number of internal nodes");
        printf("\n 11. Determine the height of the tree");
        printf("\n 12. Find the mirror image of the tree");
        printf("\n 13. Delete the tree");
        printf("\n 14. Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the value of the new NODE : ");
                scanf("%d", &val);
                root = insertElement(root, val);
                break;
            case 2:
                printf("\n The elements of the tree are : \n");
                preorderTraversal(root);
                break;
            case 3:
                printf("\n The elements of the tree are : \n");
                inorderTraversal(root);
                break;
            case 4:
                printf("\n The elements of the tree are : \n");
                postorderTraversal(root);
                break;
            case 5:
                ptr = findSmallestElement(root);
                printf("\nSmallest element is %d\n", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(root);
                printf("\nLargest element is %d\n", ptr->data);
                break;
            case 7:
                printf("\n Enter the value to be deleted : ");
                scanf("%d", &val);
                root = deleteElement(root, val);
                break;
            case 8:
                printf("\nTotal Number of nodes are %d\n", totalNodes(root));
                break;
            case 9:
                printf("\nTotal Number of external nodes are %d\n", totalExternalNodes(root));
                break;
            case 10:
                printf("\nTotal Number of internal nodes are %d\n", totalInternalNodes(root));
                break;
            case 11:
                printf("\nHeight of tree is %d\n", Height(root));
                break;
            case 12:
                root = mirrorImage(root);
                break;
            case 13:
                root = deleteTree(root);
                break;
        }
    }while(option!=14);
    return 0;
}

NODE *insertElement(NODE *tree, int val)
{
    if(tree == NULL){
        NODE *ptr = malloc(sizeof(NODE));
        ptr->left = NULL;
        ptr->data = val;
        ptr->right = NULL;
        tree = ptr;
    }
    else{
        if(val < tree->data)
            tree->left = insertElement(tree->left, val);
        else
            tree->right = insertElement(tree->right, val);
    }
    return tree;
}

void preorderTraversal(NODE *ptr)
{
    if(ptr != NULL){
        printf(" %d ", ptr->data);
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }
}

void postorderTraversal(NODE *ptr)
{
    if(ptr != NULL){
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf(" %d ", ptr->data);
    }
}

void inorderTraversal(NODE *ptr)
{
    if(ptr != NULL){
        inorderTraversal(ptr->left);
        printf(" %d ", ptr->data);
        inorderTraversal(ptr->right);
    }
}

NODE *findSmallestElement(NODE *tree)
{
    if(tree == NULL || tree->left == NULL){
        return (tree);
    }
    else{
        return findSmallestElement(tree->left);
    }
}

NODE *findLargestElement(NODE *tree)
{
    if(tree == NULL || tree->right == NULL){
        return (tree);
    }
    else{
        return findLargestElement(tree->right);
    }
}

NODE *mirrorImage(NODE *tree)
{
    NODE *temp;

    if(tree != NULL){
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
}

int totalNodes(NODE *tree)
{
    if(tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

int totalExternalNodes(NODE *tree)
{
    if(tree == NULL)
        return 0;
    else if(tree->right == NULL && tree->left == NULL)
        return 1;
    else
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}

int totalInternalNodes(NODE *tree)
{
    if(tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 0;
    else
        return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}

int Height(NODE *tree)
{
    int lheight, rheight;

    if(tree == NULL)
        return 0;
    else {
        lheight = Height(tree->left);
        rheight = Height(tree->right);
        if(lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

NODE *deleteTree(NODE *tree)
{
    if(tree != NULL){
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
        tree = NULL;
    }
    return tree;
}

NODE *deleteElement(NODE *tree, int val)
{
    if(tree == NULL)
        return tree;
    else if(val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if(val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else{
        if(tree->left == NULL){
            NODE *temp = tree->right;
            free(tree);
            return temp;
        }
        else if(tree->right == NULL){
            NODE *temp = tree->left;
            free(tree);
            return temp;
        }
        NODE *temp = minvaluenode(tree->right);
        tree->data = temp->data;
        free(tree->right);
        tree->right = NULL;
    }
    return tree;
}

NODE *minvaluenode(NODE *tree)
{
    NODE *curr = tree;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}