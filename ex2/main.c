#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

    TreeNode *tree = NULL;
    // Demasquer pour saisir la valeur de la racine soit-même
    // printf("Valeur de la racine : ");
    // tree = newNode();
    tree = newNodeAuto(101);    // A masquer si valeur saisie soit-même
    
    insert(tree,8);
    insert(tree,14);
    insert(tree,129);
    insert(tree,4);
    insert(tree,99);
    insert(tree,13);
    insert(tree,55);
    
    // Demasquer pour tester
    // inorder(tree);
    // insertAuto(tree);

    inorder(tree);
    printf("\n");

    deleteNode(tree);
    inorder(tree);
    printf("\n");

    freeTree(tree);
    
}