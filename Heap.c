//
// Created by Bibi on 5/26/2021.
//

#include "Heap.h"
MAXHEAP CreateMax_Heap()
{
    MAXHEAP newNode;
    newNode.elements=(int*)malloc(sizeof(int));
    if (!newNode.elements)
        exit(2);
    newNode.nrOfElements=0;
    return newNode;
}

void swap_Heap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void insert_Heap(MAXHEAP* maxHeap, int value)
{
    (*maxHeap).nrOfElements++;
    (*maxHeap).elements=(int*)realloc((*maxHeap).elements, (*maxHeap).nrOfElements*sizeof(int));
    (*maxHeap).elements[(*maxHeap).nrOfElements-1]=value;
    lift(maxHeap, (*maxHeap).nrOfElements-1);
}

void printArray_Heap(MAXHEAP maxHeap)
{
    for (int i = 0; i < maxHeap.nrOfElements; ++i)
        printf("%d ", maxHeap.elements[i]);
    printf("\n");
}

int deleteRoot_Heap(MAXHEAP* maxHeap)
{
    int x=(*maxHeap).elements[0];
    swap(&(*maxHeap).elements[0], &(*maxHeap).elements[(*maxHeap).nrOfElements-1]);

    (*maxHeap).nrOfElements--;
    (*maxHeap).elements= realloc((*maxHeap).elements, (*maxHeap).nrOfElements);
    sink(&(*maxHeap), 0);
    return x;
}

void lift_Heap(MAXHEAP* maxheap, int index)
{
    while (index>=0 && (*maxheap).elements[index/2]< (*maxheap).elements[index])
    {
        swap(&(*maxheap).elements[index/2], &(*maxheap).elements[index]);
        index=index/2;
    }
}

void sink_Heap(MAXHEAP* maxheap, int index)
{
    while(2*index<(*maxheap).nrOfElements)
    {
        int j=2*index;
        if (j+1<(*maxheap).nrOfElements && (*maxheap).elements[j] < (*maxheap).elements[j+1])//choosing max children
            j++;
        if ((*maxheap).elements[j]<=(*maxheap).elements[index])
            break;
        swap(&(*maxheap).elements[index], &(*maxheap).elements[j]);
        index=j;
    }
}

int getMaxValue_Heap(MAXHEAP maxHeap)
{
    if (maxHeap.nrOfElements!=0)
        return maxHeap.elements[0];
    printf("Empty heap!\n");
    return -1;
}

void modifyValue_Heap(MAXHEAP* maxHeap, int from, int to)
{
    int index=0;
    while (index<(*maxHeap).nrOfElements && (*maxHeap).elements[index]!=from)
        index++;
    if (index<(*maxHeap).nrOfElements)
    {
        (*maxHeap).elements[index]=to;
        if (from < to)
            lift(&(*maxHeap), index);
        else
            sink(&(*maxHeap), index);
    }
    else
        printf("No such value found!\n");
}

MAXHEAP concatenate_Heap(MAXHEAP h1, MAXHEAP h2)
{
    MAXHEAP res=CreateMaxHeap();
    for (int i=0;i<h1.nrOfElements;i++)
        insertToHeap(&res, h1.elements[i]);

    for (int i=0;i<h2.nrOfElements;i++)
        insertToHeap(&res, h2.elements[i]);
    return res;
}