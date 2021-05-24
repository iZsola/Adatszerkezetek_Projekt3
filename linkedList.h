//
// Created by Bibi on 5/24/2021.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Node{
    int info;
    struct Node* next;
}Node;

void printList(Node*);
Node* Create(int);
bool isEmpty(Node*);
void addLast(Node*, int);
void addFirst(Node**, int);
int removeFirst(Node**);
int removeLast(Node*);
int removeIndex(Node**, int);

#endif //ADATSZERKEZETEK_PROJEKT333_LINKEDLIST_H
