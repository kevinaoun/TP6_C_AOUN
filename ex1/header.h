#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode_{
    int val;
    struct ListNode_ *dest;
}ListNode;

ListNode *newNode();
ListNode *newNodeAuto(int val);

ListNode *insertEnd(ListNode *liste);
ListNode *insertBeginning(ListNode *liste);
ListNode *insertMiddle(ListNode *liste);

ListNode *deleteNode(ListNode *liste);

void searchNode(ListNode *liste);

//ListNode *sorterList(ListNode *liste);

void printList(ListNode *liste);

void freeListe(ListNode *liste);