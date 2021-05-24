//
// Created by user on 20/05/2021.
//

#ifndef ADATSZERKEZETEK_PROJEKT3_HASHTABLE_H
#define ADATSZERKEZETEK_PROJEKT3_HASHTABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int* elements;
    int capacity;
}Hashtable;

bool insertToHashTable(Hashtable*, int);
int findInHashTable(Hashtable, int);
bool deleteFromHashTable(Hashtable*, int);
Hashtable createHashtable(int);
void printHashTable(Hashtable);
void freeHashTable(Hashtable*);

#endif //ADATSZERKEZETEK_PROJEKT3_HASHTABLE_H
