#pragma once
#include "Friend.h"

class node
{
public:
    Friend key;
    int prio;
    node* left, * right;
    node(Friend key)
    {
        this->key = key;
        prio = rand() % 100;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Treap
{
private:
    node* root;
    void leftRotate(node*& n);
    void rightRotate(node*& n);
public:
    Treap();
    node*& getRoot();
    void insert(node*& root, Friend key);
    void deleteNode(node*& root, Friend key);
    bool searchByUsername(node*& root, string username);
    void print(node* root);
};

