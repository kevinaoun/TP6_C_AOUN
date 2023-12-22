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

void insert(TreeNode *tree, int val) {
    if (val < tree->val) {
        if (tree->left == NULL) tree->left = newNodeAuto(val);
        else insert(tree->left, val);
    }
    else if (val >= tree->val) {
        if (tree->right == NULL) tree->right = newNodeAuto(val);
        else insert(tree->right, val);
    }
    else {
        printf("Arbre vide\n");
        tree = newNodeAuto(val);
    }
}

void inorder(TreeNode *tree) {

    // if (tree == NULL) {
    //     printf("L'arbre est vide\n") ;
    //     return;
    // }
    // if (tree->left != NULL) {
    //     inorder(tree->left);
    //     if (tree->right != NULL) {
    //         inorder(tree->right);
    //     }
    // }
    // else {  // if (tree->left == NULL)
    //     if (tree->right != NULL) {
    //         inorder(tree->right);
    //     }
    // }
    // printf("%d ",tree->val);

    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ",tree->val);
        inorder(tree->right);
    }

}

void freeTree(TreeNode *tree) {
    TreeNode *temp = tree;
    if (temp != NULL) {
        freeTree(tree->left);
        freeTree(tree->right);
        free(temp);
    }
}

int main() {
    TreeNode *tree = NULL;
    // printf("Valeur de la racine : ");
    // tree = newNodeAuto(101);
    
    insert(tree,101);
    insert(tree,8);
    insert(tree,14);
    insert(tree,129);
    insert(tree,4);
    insert(tree,99);
    insert(tree,13);
    insert(tree,55);

    inorder(tree);
    printf("\n");
    freeTree(tree);
}