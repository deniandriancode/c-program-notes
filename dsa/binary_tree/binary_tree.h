#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void binary_tree_demo ();
void insert (struct node **, int);
void print_preorder (struct node *);
void print_inorder (struct node *);
void print_postorder (struct node *);
struct node* search (struct node **, int);
void deltree (struct node *);

/* insert an element */
void
insert (struct node **tree, int value)
{
    struct node *tmp = NULL;
    if (!(*tree)) {
        tmp = (struct node*) malloc (sizeof (struct node));
        tmp->left = tmp->right = NULL;
        tmp->data = value;
        *tree = tmp;
        return;
    }

    if (value < (*tree)->data) {
        insert (&(*tree)->left, value);
    } else if (value > (*tree)->data) {
        insert (&(*tree)->right, value);
    }
}

/* print tree preorder */
void
print_preorder (struct node *tree)
{
    if (tree) {
        printf ("%d -> ", tree->data);
        print_preorder (tree->left);
        print_preorder (tree->right);
    }
}

/* print tree inorder */
void
print_inorder (struct node *tree)
{
    if (tree) {
        print_inorder (tree->left);
        printf ("%d -> ", tree->data);
        print_inorder (tree->right);
    }
}

/* print tree postorder */
void
print_postorder (struct node *tree)
{
    if (tree) {
        print_postorder (tree->left);
        print_postorder (tree->right);
        printf ("%d -> ", tree->data);
    }
}

/* search for a node */
struct node*
search (struct node **tree,
        int value)
{
    if (!(*tree)) {
        return NULL;
    }

    if (value == (*tree)->data) {
        return *tree;
    } else if (value < (*tree)->data) {
        search (&((*tree)->left), value);
    } else if (value > (*tree)->data) {
        search (&((*tree)->right), value);
    }
}

/* delete an node */
void
deltree (struct node *tree)
{
    if (tree) {
        deltree (tree->left);
        deltree (tree->right);
        free (tree);
    }
}

void
binary_tree_demo ()
{
    struct node *mytree;
    mytree = (struct node*)malloc (sizeof (struct node));
    mytree->data = 4;
    insert (&mytree, 2);
    insert (&mytree, 3);
    insert (&mytree, 5);
    insert (&mytree, 7);
    insert (&mytree, 6);
    insert (&mytree, 8);
    print_preorder (mytree);
    printf ("\n");
}
