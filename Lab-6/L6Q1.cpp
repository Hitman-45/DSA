#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    struct node* right;
    struct node* left;
};
node* createnode(int x)
{
    struct node *p;
    p = new node();
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

class BST
{
private:
    node* root;

public:
    BST() : root(NULL) {}

    void insert(node* &t, int element)
    {
        if (t == NULL)
        {
            node *p;
            p = createnode(element);
            t = p;
            return;
        }

        if (element < t->data)
        {
            insert(t->left, element);
        }
        else if (element > t->data)
        {
            insert(t->right, element);
        }
    }

    bool search(node* t, int element)
    {
        if (t == NULL)
        {
            return false;
        }

        if (t->data > element)
        {
            return search(t->left, element);
        }
        else if (t->data < element)
        {
            return search(t->right, element);
        }
        else 
        {
            return true;
        }
    }

    int smallest(node* t)
    {
        if (t == NULL)
        {
            cout << "Tree is empty" << endl;
            return -1;
        }

        if (t->left == NULL)
        {
            return t->data;
        }
        else
        {
            return smallest(t->left);
        }
    }

    void preOrder(node* t)
    {
        if (t != NULL)
        {
            cout << t->data << " ";
            preOrder(t->left);
            preOrder(t->right);
        }
    }

    void inOrder(node* t)
    {
        if (t != NULL)
        {
            inOrder(t->left);
            cout << t->data << " ";
            inOrder(t->right);
        }
    }

    void insert(int element)
    {
        insert(root, element);
    }

    bool search(int element)
    {
        return search(root, element);
    }

    int smallest()
    {
        return smallest(root);
    }

    void pre()
    {
        preOrder(root);
        cout << endl;
    }

    void inorder()
    {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    int t;
    cin>>t;
    BST ab;
    while(t--)
    {
        int op;
        cin>>op;
        int ele;
        switch(op)
        {
            case 1:
                cin>>ele;
                ab.insert(ele);
                break;
                
            case 2:
                cin>>ele;
                cout<<ab.search(ele)<<endl;
                break;
                
            case 3:
                cout<<ab.smallest()<<endl;
                break;
                
            case 4:
                ab.pre();
                break;
                
            case 5:
                ab.inorder();
                break;
        }
    }
    return 0;
}
