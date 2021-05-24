//
// Created by Bibi on 5/12/2021.
//

#include "BST.h"


///Create BST
node* create_BST(Ship x)
{
    node* t;
    t=(node*)malloc(sizeof(node));
    t->ship=x;
    t->left=NULL;
    t->right=NULL;
    return t;
}

///Search in BST
node* search_BST(node *root, Ship x)
{
    if(root==NULL || root->ship.value==x.value) //if root->data is x then the element is found
        return root;
    else if(x.value>root->ship.value) // x is greater, so we will search the right subtree
        return search_BST(root->right, x);
    else //x is smaller than the data, so we will search the left subtree
        return search_BST(root->left,x);
}

///Insert into BST
node* insert_BST(node *root, Ship x)
{
    //searching for the place to insert
    if(root==NULL)
        return create_BST(x);
    if (root->ship.value==x.value)
        return root;
    else if(x.value>root->ship.value) // x is greater. Should be inserted to right
        root->right = insert_BST(root->right, x);
    else // x is smaller should be inserted to left
        root->left = insert_BST(root->left,x);
    return root;
}

///Function to delete a node
node* delete_BST(node *root, Ship x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x.value>root->ship.value)
        root->right = delete(root->right, x);
    else if(x.value<root->ship.value)
        root->left = delete_BST(root->left, x);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

            //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

            //Two Children
        else
        {
            node *temp = find_minimum_BST(root->right);
            root->ship= temp->ship;
            root->right = delete_BST(root->right, temp->ship);
        }
    }
    return root;
}

node* find_minimum_BST(node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // node with minimum value will have no left child
        return find_minimum_BST(root->left); // left most element will be minimum
    return root;
}

node* find_maximum_BST(node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->right != NULL) // node with minimum value will have no right child
        return find_maximum_BST(root->right); // left most element will be minimum
    return root;
}

void inorder_BST(node *root) {
    if (root != NULL) // checking if the root is not null
    {
        inorder(root->left); // visiting left child
        printf("ID=%d, t=%.2lf\n", root->ship.id, root->ship.value); // printing data at root
        inorder_BST(root->right);// visiting right child
    }
}

Ship findFloor_BST(node *root, Ship info) {
    node *curr = root, *ans = NULL;
    while (curr) {
        if (curr->ship.value<= info.value) {
            ans = curr;
            curr = curr->right;
        } else
            curr = curr->left;
    }
    if (ans)
        return ans->ship;
    Ship p;
    p.value=1000;
    p.id=-1;
    return p;
}

///Finds ship which arrives right after given ship
Ship findSuc_BST(node *root, Ship info) {
    node *curr = root, *ans = NULL;
    while (curr) {
        if (curr->ship.value> info.value) {
            ans = curr;
            curr = curr->left;
        } else
            curr = curr->right;
    }
    if (ans)
        return ans->ship;
    Ship p;
    p.value=1000;
    p.id=-1;
    return p;
}


bool iterativeSearch_BST(node* root, Ship info)
{
    // Traverse untill root reaches to dead end
    while (root != NULL) {
        // pass right subtree as new tree
        if (info.value > root->ship.value)
            root = root->right;

            // pass left subtree as new tree
        else if (info.value < root->ship.value)
            root = root->left;
        else
            return true; // if the ship// is found return 1
    }
    return false;
}