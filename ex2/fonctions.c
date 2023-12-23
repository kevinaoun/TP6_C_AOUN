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

TreeNode *deleteNode(TreeNode* tree) {

    if (tree == NULL){
        printf("Arbre vide, ERREUR\n");
        return tree;
    }

    int val;
    printf("Saisir la valeur à effacer de l'arbre : ");
    scanf("%d",&val);

    TreeNode *initiale = tree;
    TreeNode *temp = NULL;

    while (val != tree->val) {

        if (val < tree->val) {
            if (tree->left == NULL) {
                printf("La valeur à effacer n'est pas dans l'arbre\n");
                return initiale;
            }
            else {
                temp = tree;
                tree = tree->left;
            }
        }
        else {      // if (val >= tree->val)
            if (tree->right == NULL) {
                printf("La valeur à effacer n'est pas dans l'arbre\n");
                return initiale;
            }
            else {
                temp = tree;
                tree = tree->right;
            }
        }

    }

    if (tree->val == val) {

        if ((tree->right == NULL) && (tree->left == NULL)) {
            if (tree->val < temp->val) {
                temp->left = NULL;
            }
            else {      // if (val >= tree->val)
                temp->right = NULL;
            }
            free(tree);
            return initiale;
        }

        // ######### ATTENTION A CETTE PARTIE, FAIRE PLUS SIMPLE AVEC ADRESSES AU LIEU DE REMPLACER PUIS SUPPR ############
        else if ((tree->left==NULL) && (tree->right!=NULL) && (tree->right->right==NULL) && (tree->right->left==NULL)) {
            tree->val = tree->right->val;
            tree->right = NULL;
            free(tree->right);
            return initiale;
        }

        else if ((tree->right==NULL) && (tree->left!=NULL) && (tree->left->right==NULL) && (tree->left->left==NULL)) {
            tree->val = tree->left->val;
            tree->left = NULL;
            free(tree->left);
            return initiale;
        }
        // ########## PLUS GENERAL, FAIRE EN MEME TEMPS LE CAS OU PLUSIEURS ENFANTS EN DESSOUS DU MEME ENFANT #############

        else {
            // if ((tree->left==NULL) && (tree->right!=NULL)) {
            //     tree->val = tree->right->val;
            //     if ((tree->right->right == NULL) && (tree->right->left == NULL)) {
            //         free(tree->right);
            //         free(temp);
            //         return initiale;
            //     }
            //     free(tree->right);
            // }
            
            // ((tree->right==NULL) && (tree->left!=NULL))) {
            
            printf("ERREUR SMR ELSE\n");
            return initiale;
        }

    }

    printf("MESSAGE ERREUR\n");
    return initiale;

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