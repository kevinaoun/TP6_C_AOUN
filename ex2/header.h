#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode_{
    int val;
    struct TreeNode_ *left;
    struct TreeNode_ *right;
}TreeNode;

// Ajouter un noeud à l'arbre dont la valeur est saisie par l'utilisateur
TreeNode *newNode();
// Ajouter un noeud à l'arbre dont la valeur est prise en paramètre de fonction
TreeNode *newNodeAuto(int val);

// Inserer une valeur (prise en paramètre) à sa place dans l'arbre
void insert(TreeNode *tree, int val);
// Inserer une valeur (saisie par l'utilisateur) à sa place dans l'arbre
void insertAuto(TreeNode *tree);

// Afficher les valeurs de l'arbre dans l'ordre croissant
void inorder(TreeNode *tree);

// 
TreeNode *deleteNode(TreeNode* tree);

// Libérer l'espace alloué pour l'arbre
void freeTree(TreeNode *tree);