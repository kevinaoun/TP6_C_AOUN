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
    if (tree == NULL) {
        printf("L'arbre est vide\n") ;
        return;
    }

    if (tree->left != NULL) {
        // printf("enfant gauche, %d\n",tree->left->val);
        inorder(tree->left);
    }
    else {  // if (tree->left == NULL)
        // printf("%d ",tree->val);         // affichage double
        if (tree->right != NULL) {
            inorder(tree->right);
        }
    }
    printf("%d ",tree->val);
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
    printf("Valeur de la racine : ");
    tree = newNode();
    
    insert(tree,5);
    insert(tree,4);
    insert(tree,3);
    insert(tree,8);
    insert(tree,6);
    insert(tree,7);
    insert(tree,11);
    insert(tree,10);
    insert(tree,13);
    insert(tree,12);

    inorder(tree);
    printf("\n");
    freeTree(tree);
}