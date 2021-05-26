//
// Created by Bibi on 5/26/2021.
//

#ifndef ADATSZERKEZETEK_PROJEKTHEAP_INTARRAY_H
#define ADATSZERKEZETEK_PROJEKTHEAP_INTARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int* elements;
    int size;
}intArray;

void create_IntArray(intArray*);
void read_IntArray(const char*, intArray*);
void fill_IntArray(intArray*, int, int);
void print_IntArray(intArray);
void printArrayToFile_IntArray(const char*, intArray);
void sort_IntArray(intArray*);
int cmpfunc_IntArray (const void*, const void*);
int findElement_IntArray(intArray, int);
int minimum_IntArray(intArray);
int maximumFunc_IntArray(intArray);
int linearSearch_IntArray(intArray, int);
int binarySearchUtil_IntArray(intArray, int);
int binarySearch_IntArray(intArray, int, int, int);
void copy_IntArray(intArray, intArray*);
void deleteElement_IntArray(intArray*, int);
#endif //ADATSZERKEZETEK_PROJEKTHEAP_INTARRAY_H
