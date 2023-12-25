#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){

    printf("Valeur de la racine : ");
    ListNode *racine = newNode();
    printList(racine);

    insertEnd(racine);
    printList(racine);
    
    racine = insertBeginning(racine);
    printList(racine);
    
    racine = insertMiddle(racine);
    printList(racine);
    
    racine = deleteNode(racine);
    printList(racine);

    searchNode(racine);

    printf("Avant trie, ");
    printList(racine);
    sorterList(&racine);
    printf("Après trie, ");
    printList(racine);

    freeListe(racine);
    return 0;

}