#pragma once
#include "User.h"

class Node {
public:
    User content;
    Node* previous;
    Node* next;
    Node() {
        this->previous = NULL;
        this->next = NULL;
    }
};

class UserLinkedList
{
private:
    Node* head;
public:
    UserLinkedList();
    void Insertback(User itm);

    void InsertFront(User itm);
    void Insert(int i, User itm);
    int len();
    void deletelast();
    void deletenode(int i);
    void deleteFront();

    User* get(int i);
    User* get(string username);
    void display();

    
};

