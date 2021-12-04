#include "UserLinkedList.h"

UserLinkedList::UserLinkedList()
{  
   this->head = NULL;
}

void UserLinkedList::Insertback(User itm)
{
    Node* node = new Node[1];
    node->content = itm;
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node* tmp = head;
    Node* previous = new Node();
    while (tmp->next != NULL) {
        previous = tmp;
        tmp = tmp->next;
    }
    tmp->next = node;
    tmp->previous = previous;
}

void UserLinkedList::InsertFront(User itm)
{
    Node* node = new Node[1];
    node->content = itm;
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node* tmp = head;
    Node* previous = new Node();
    while (tmp->next != NULL) {
        previous = tmp;
        tmp = tmp->next;
    }
    tmp->next = node;
    tmp->previous = previous;
}

void UserLinkedList::Insert(int i, User itm)
{
    if (i > len() || i < 0) {

        return;
    }
    Node* node = new Node[1];
    node->content = itm;
    int cnt = 0;
    Node* tmp = head;
    while (tmp != NULL && cnt < i) {
        if (cnt == i - 1) {
            if (tmp->next != NULL) {
                node->next = tmp->next;
            }
            tmp->next = node;
            node->previous = tmp;

            break;
        }
        cnt++;
        tmp = tmp->next;
    }
}

int UserLinkedList::len()
{
    int l = 0;
    Node* tmp = head;
    while (tmp != NULL) { l++; tmp = tmp->next; }
    return l;
}

void UserLinkedList::deletelast()
{
    if (head == NULL) {

        return;
    }
    if (head->next == NULL) {
        head = NULL;

        return;
    }

    Node* tmp = head;
    while (tmp != NULL) {
        if (tmp->next->next == NULL) {
            tmp->next = NULL;

            break;
        }
        tmp = tmp->next;
    }
}

void UserLinkedList::deletenode(int i)
{
    if (head == NULL) {

        return;
    }
    if (i >= len() || i < 0) {

        return;
    }
    if (i == 0) {
        deleteFront();

        return;
    }
    int cnt = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        if (cnt == i - 1) {
            tmp->next = tmp->next->next;

            break;
        }
        cnt++;
        tmp = tmp->next;
    }
}

void UserLinkedList::deleteFront()
{
    if (head == NULL) {

        return;
    }
    head = head->next;
    head->next->previous = head;
}

User* UserLinkedList::get(int i)
{
    if (i == 0) {
        return &head->content;
    }
    int cnt = 0;
    User* result = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        if (cnt++ == i) {
            result = &tmp->content;
            break;
        }
        tmp = tmp->next;
    }
    return result;
}

User* UserLinkedList::get(string username)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        if (temp->content.getUsername() == username)
            return &temp->content;
        temp = temp->next;
    }
	return nullptr; //if the user isn't found in the list.
}

void UserLinkedList::display()
{
    for (int i = 0; i < this->len(); i++) {
        cout << this->get(i) << " ";
    }
}

