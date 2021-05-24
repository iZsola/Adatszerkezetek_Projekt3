//
// Created by Bibi on 5/24/2021.
//
#include "linkedList.h"

void printList(Node* first)
{
    Node* c=first;
    while (c!=NULL)
    {
        printf("%d ", c->info);
        c=c->next;
    }
}

Node* Create(int n)
{
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->info=n;
    return p;
}
bool isEmpty(Node* first)
{
    if (first==NULL)
        return true;
    return false;
}
void addLast(Node* first, int n)
{
    Node* current=first;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    if (current->info==INT_MIN)
        current->info=n;
    else
    {
        current->next= Create(n);
    }
}

void addFirst(Node** first, int n)
{
    Node* new;
    new=Create(n);
    if ((*first)->info==INT_MIN)
        new->next=NULL;
    else
        new->next=(*first);
    (*first)=new;
}

int removeFirst(Node** first)
{
    int retval = -1;
    Node * next_node = NULL;

    if (*first == NULL) {
        return -1;
    }

    next_node = (*first)->next;
    retval = (*first)->info;
    free(*first);
    *first = next_node;

    return retval;
}

int removeIndex(Node** first, int n)
{
    int i = 0, retval=-1;
    Node* current = *first;
    Node* temp_node = NULL;

    if (n == 0) {
        return removeFirst(first);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->info;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

int removeLast(Node* head)
{
    int retval = 0;

    if (head->next == NULL) //If only 1 item in list
    {
        retval = head->info;
        free(head);
        return retval;
    }

    Node * current = head;
    while (current->next->next != NULL) //Go to the one before the last
    {
        current = current->next;
    }

    retval = current->next->info;
    free(current->next);
    current->next = NULL;
    return retval;
}
