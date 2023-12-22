#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode_{
    int val;
    struct TreeNode_ *left;
    struct TreeNode_ *right;
}TreeNode;

TreeNode *newNode(){
    TreeNode *Node = malloc(sizeof(TreeNode));
    int val;
    //printf("Rentrer une valeur : ");
    scanf("%d", &val);
    Node->val=val;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}

TreeNode *newNodeAuto(int val){
    TreeNode *Node = malloc(sizeof(TreeNode));
    Node->val=val;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}

TreeNode *insert(TreeNode *tree) {  // SANS RECURSIVITE
    printf("Element à ajouter : ");
    TreeNode *initiale = tree;
    if (tree == NULL) return newNode();

    TreeNode *node = newNode();
    while (node->val < tree->val){
        if (tree->left == NULL) {
            tree->left = node;
            return initiale;
        }
        tree = tree->left;
    }
    while (node->val >= tree->val){
        if (tree->right == NULL) {
            tree->right = node;
            return initiale;
        }
        tree = tree->right;
    }

    printf("MESSAGE ERREUR\n");
    return initiale;
}

void inorder(TreeNode *tree) {     // SANS RECURSIVITE
    while (tree->left != NULL) {
        tree = tree->left;
    }
    while (tree->right != NULL) {
        printf("%d ",tree->val);
        tree = tree->right;
    }
    printf("%d",tree->val);
    if (tree->left != NULL) printf("\nDernier enfant à droite\n");
    else printf("\nArrivé à la feuille\n");
}

void freeTree(TreeNode *tree) {
    TreeNode *temp;
    while (tree != NULL) {
        if (tree->left != NULL) {
            temp = tree;
            tree = tree->left;
            free(temp);
        }
        else if (tree->right != NULL) {
            temp = tree;
            tree = tree->right;
            free(temp);
        }
    }
    printf("L'espace alloué a bien été libéré\n");
}

int main() {
    TreeNode *tree = NULL;
    printf("Valeur de la racine : ");
    tree = newNode(tree);
    insert(tree);
    insert(tree);
    insert(tree);
    insert(tree);
    inorder(tree);
    freeTree(tree);
}