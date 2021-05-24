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

node* create_BST(Ship);
node* insert_BST(node*, Ship);
node* search_BST(node*, Ship);
node* delete_BST(node*, Ship);
node* find_minimum_BST(node*);
node* find_maximum_BST(node*);
Ship findFloor_BST(node*, Ship);
Ship findSuc_BST(node*, Ship);
void inorder_BST(node*);
bool iterativeSearch_BST(node*, Ship);
#endif //ADATSZERKEZETEK_PROJEKT_3_BST_H
