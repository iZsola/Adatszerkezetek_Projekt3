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

void print_LinkedList(Node*);
Node* Create_LinkedList(int);
bool isEmpty_LinkedList(Node*);
void addLast_LinkedList(Node*, int);
void addFirst_LinkedList(Node**, int);
int removeFirst_LinkedList(Node**);
int removeLast_LinkedList(Node*);
int removeIndex_LinkedList(Node**, int);

#endif //ADATSZERKEZETEK_PROJEKT333_LINKEDLIST_H
