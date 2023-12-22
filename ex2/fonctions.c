#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*******************************************************************************/

// Ajouter un noeud à l'arbre dont la valeur est saisie par l'utilisateur
TreeNode *newNode() {
    TreeNode *Node = malloc(sizeof(TreeNode));
    int val;
    //printf("Rentrer une valeur : ");
    scanf("%d", &val);
    Node->val=val;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}

/*******************************************************************************/

// Ajouter un noeud à l'arbre dont la valeur est prise en paramètre de fonction
TreeNode *newNodeAuto(int val) {
    TreeNode *Node = malloc(sizeof(TreeNode));
    Node->val=val;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}

/*******************************************************************************/

// Inserer une valeur (prise en paramètre) à sa place dans l'arbre
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

/*******************************************************************************/

// Inserer une valeur (saisie par l'utilisateur) à sa place dans l'arbre
void insertAuto(TreeNode *tree) {
    int val;
    printf("Saisir la valeur à insérer : ");
    scanf("%d",&val);
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

/*******************************************************************************/

// Afficher les valeurs de l'arbre dans l'ordre croissant
void inorder(TreeNode *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ",tree->val);
        inorder(tree->right);
    }
}

/*******************************************************************************/

// Libérer l'espace alloué pour l'arbre
void freeTree(TreeNode *tree) {
    TreeNode *temp = tree;
    if (temp != NULL) {
        freeTree(tree->left);
        freeTree(tree->right);
        free(temp);
    }
}

/*******************************************************************************/