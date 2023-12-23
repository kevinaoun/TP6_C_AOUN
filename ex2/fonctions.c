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
            printf("Pas d'enfant\n");
            free(tree);
            return initiale;
        }

        else if ((tree->left==NULL) && (tree->right!=NULL)) {
            if (tree->val < temp->val) {
                temp->left = tree->right;
            }
            else {      // if (val >= tree->val)
                temp->right = tree->right;
            }
            free(tree);
            return initiale;
        }

        else if ((tree->right==NULL) && (tree->left!=NULL)) {
            if (tree->val < temp->val) {
                temp->left = tree->left;
            }
            else {      // if (val >= tree->val)
                temp->right = tree->left;
            }
            free(tree);
            return initiale;
        }

        else {  // if ((tree->right!=NULL) && (tree->left!=NULL))
                // EN REALITE IL SUFFIT JUSTE DE TROUVER LE PLUS PETIT FILS A DROITE 
                // ET REMPLACER L'ELEMENT A SUPPRIMER PAR CELUI CI (PAS BESOIN DE RECURCIVE) 

            TreeNode *temp2 = tree;
            temp = tree;
            tree = tree->right;

            while (tree->left != NULL) {
                temp2=tree;
                tree = tree->left;
            }
            
            int temp_int = tree->val;
            temp2->left = NULL;
            free(tree);
            temp->val = temp_int;

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