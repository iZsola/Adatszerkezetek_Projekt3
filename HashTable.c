//
// Created by user on 20/05/2021.
//

#include "HashTable.h"

Hashtable create_Hashtable(int c)
{
    Hashtable t;
    t.capacity=c;
    t.elements=(int*)malloc(sizeof(int)*c);
    if (!t.elements)
        exit(1);
    for (int i=0;i<c;i++)
        t.elements[i]=-1;
    return t;
}

bool insert_HashTable(Hashtable *t, int value)
{
    if (find_HashTable((*t), value)>=0)
        return false;
    int i=0, j;
    do {
        j=(value+i)%(*t).capacity;
        if ((*t).elements[j]==-1)
        {
            (*t).elements[j]=value;
            return true;
        }
        i++;
    } while (i!=(*t).capacity);

    printf("Tulcsordulas!\n");
    return false;
}

int find_HashTable(Hashtable t, int key)
{
    int j, i=0;
    do {
        j=(key+i)%t.capacity;
        if (t.elements[j]==key)
            return j;
        i++;
    } while (t.elements[j]!=-1 && i!=t.capacity);

    return -1;
}

bool delete_HashTable(Hashtable *t, int value)
{
    int j, i=0;

    do
    {
        j=(value+i)%(*t).capacity;
        if ((*t).elements[j]==value)
        {
            (*t).elements[j]=-1;
            return true;
        }
        i++;
    }while((*t).elements[j]!=-1 && i!=(*t).capacity);
    printf("Hianyzo elem!\n");
    return false;
}

void print_HashTable(Hashtable t)
{
    for (int i=0;i<t.capacity;i++)
        if (t.elements[i]!=-1)
            printf("%d ", t.elements[i]);
    printf("\n");
}

void free_HashTable(Hashtable* t)
{
    free((*t).elements);
}