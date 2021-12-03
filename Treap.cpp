#include "Treap.h"

Treap::Treap()
{
    root = nullptr;
}

node*& Treap::getRoot()
{
	return root;
}

void Treap::leftRotate(node*& n)
{
    node* R = n->right;
    node* X = n->right->left;
    R->left = n;
    n->right = X;

    n = R;
}

void Treap::rightRotate(node*& n)
{
    node* L = n->left;
    node* Y = n->left->right;
    L->right = n;
    n->left = Y;
    n = L;
}

void Treap::insert(node*& root, Friend key)
{
    if (root == nullptr)
    {
        root = new node(key);
        return;
    }
    if (key < root->key)
    {
        this->insert(root->left, key);

        // rotate right if heap property is violated
        if (root->left != nullptr && root->left->prio > root->prio)
        {
            this->rightRotate(root);
        }
    }
    else
    {

        this->insert(root->right, key);

        if (root->right != nullptr && root->right->prio > root->prio)
        {
            this->leftRotate(root);
        }
    }
}

void Treap::deleteNode(node*& root, Friend key)
{
    if (root == nullptr)
    {
        return;
    }
    if (key < root->key)
    {
        this->deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        this->deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left && root->right)
        {
            if (root->left->prio < root->right->prio)
            {
                this->leftRotate(root);
                this->deleteNode(root->left, key);
            }
            else {
                this->rightRotate(root);
                this->deleteNode(root->right, key);
            }
        }
        else {

            node* child = (root->left) ? root->left : root->right;
            node* curr = root;

            root = child;


            delete curr;
        }
    }
}

bool Treap::searchByUsername(node*& root, string username)
{
    if (root == nullptr)
        return false;
    if (root->key.getUsername() == username)
        return true;
    if (username < root->key.getUsername())
        return this->searchByUsername(root->left, username);
    else return this->searchByUsername(root->right, username);
}

void Treap::print(node* root)
{
    if (root != nullptr)
    {
        print(root->left);
        cout << root->key << endl;
        print(root->right);
    }
}
