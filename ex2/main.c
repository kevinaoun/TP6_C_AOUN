#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

    TreeNode *tree = NULL;
    // printf("Valeur de la racine : ");
    // tree = newNode();    // Saisir la valeur de la racine soit-même
    tree = newNodeAuto(101);
    
    insert(tree,8);
    insert(tree,14);
    insert(tree,129);
    insert(tree,4);
    insert(tree,99);
    insert(tree,13);
    insert(tree,55);
    
    // insertAuto(tree);
    // insertAuto(tree);

    inorder(tree);
    printf("\n");
    freeTree(tree);
    
}