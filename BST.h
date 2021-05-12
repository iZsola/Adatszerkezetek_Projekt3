//
// Created by Bibi on 5/12/2021.
//

#ifndef ADATSZERKEZETEK_PROJEKT_3_BST_H
#define ADATSZERKEZETEK_PROJEKT_3_BST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double value;
    int id;
}Ship;

typedef struct{
    Ship ship;
    struct node *left, *right;
}node;

node* create(Ship);
node* insert(node*, Ship);
node* search(node*, Ship);
node* delete(node*, Ship);
node* find_minimum(node*);
node* find_maximum(node*);
Ship findFloor(node*, Ship);
Ship findSuc(node*, Ship);
void inorder(node*);
bool iterativeSearch(node*, Ship);
#endif //ADATSZERKEZETEK_PROJEKT_3_BST_H
