//
// Created by user on 20/05/2021.
//

#include "HashTable.h"

Hashtable createHashtable(int c)
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

bool insertToHashTable(Hashtable *t, int value)
{
    if (findInHashTable((*t), value)>=0)
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

bool insertToHashTable_2(Hashtable* t, int value)
{
    if (findInHashTable((*t), value)>=0)
        return false;
    int i=1, j;
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

int findInHashTable(Hashtable t, int key)
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

bool deleteFromHashTable(Hashtable *t, int value)
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

void printHashTable(Hashtable t)
{
    for (int i=0;i<t.capacity;i++)
        if (t.elements[i]!=-1)
            printf("%d ", t.elements[i]);
    printf("\n");
}

void freeHashTable(Hashtable* t)
{
    free((*t).elements);
}