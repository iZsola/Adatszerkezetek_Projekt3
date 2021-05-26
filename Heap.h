//
// Created by Bibi on 5/26/2021.
//

#ifndef ADATSZERKEZETEK_PROJEKT3_HEAP_H
#define ADATSZERKEZETEK_PROJEKT3_HEAP_H
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int* elements;
    int nrOfElements;
}MAXHEAP;

MAXHEAP CreateMax_Heap();
void swap_Heap(int*, int*);
void insert_Heap(MAXHEAP*, int);
void printArray_Heap(MAXHEAP);
int deleteRoot_Heap(MAXHEAP*);
void lift_Heap(MAXHEAP*, int);
void sink_Heap(MAXHEAP*, int);
int getMaxValue_Heap(MAXHEAP);
void modifyValue_Heap(MAXHEAP*, int, int);
MAXHEAP concatenate_Heap(MAXHEAP, MAXHEAP);
#endif //ADATSZERKEZETEK_PROJEKT3_HEAP_H
