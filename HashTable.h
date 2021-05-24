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

bool insert_HashTable(Hashtable*, int);
int find_HashTable(Hashtable, int);
bool delete_HashTable(Hashtable*, int);
Hashtable create_Hashtable(int);
void print_HashTable(Hashtable);
void free_HashTable(Hashtable*);

#endif //ADATSZERKEZETEK_PROJEKT3_HASHTABLE_H
