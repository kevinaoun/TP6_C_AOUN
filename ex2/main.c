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

TreeNode *insert(TreeNode *tree){
    printf("Element à ajouter : ");
    TreeNode *initiale = tree;
    if (tree == NULL) return newNode();
    
}