#include <stdio.h>
#include <stdlib.h>


void print_tree(node *root);

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

int main(void) {
    node *tree = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }

    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // Add left to list
    n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    // Add left to list
    n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = 3;

    print_tree(tree);

}

void print_tree(node *root)
{
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}