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
    node *root;
    
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
    void ino(node* t,vector<int> &v)
    {
        if (t != NULL)
        {
            ino(t->left,v);
            v.push_back(t->data);
            ino(t->right,v);
        }
    }
    int ith_large(node *t, int ind)
    {
        vector<int> v;
        ino(t,v);
        int n = v.size();
        return v[n-ind];
    }
    int ith_small(node *t, int ind)
    {
        vector<int> v;
        ino(t,v);
        return v[ind-1];
    }
    int sucessor(node *t, int ele)
    {
        if (t == NULL) 
        {
            return -1; 
        }

        node *p = NULL;
        while (t != NULL && ele != t->data)
        {
            if (ele < t->data)
            {
                p = t;
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }

        if (t == NULL) 
        {
            return -1; 
        }

        if (t->right != NULL) 
        {
            t = t->right;
            while (t->left != NULL) 
            {
                t = t->left;
            }
            return t->data;
        }

        if (p != NULL && p->data > t->data) 
        {
            return p->data;
        }

        return 0;
    }

    int predecessor(node *t, int ele)
    {
        if (t == NULL) 
        {
            return -1; 
        }

        node *p = NULL;
        while (t != NULL && ele != t->data)
        {
            if (ele < t->data)
            {
                t = t->left;
            }
            else
            {
                p = t;
                t = t->right;
            }
        }

        if (t == NULL) 
        {
            return -1; 
        }

        if (t->left != NULL) 
        {
            t = t->left;
            while (t->right != NULL) 
            {
                t = t->right;
            }
            return t->data;
        }
        else if (p != NULL && p->data < t->data) 
        {
            return p->data;
        }

        return 0;
    }

    node* deleteNode(node* root, int key)
    {
        if (root == NULL) 
        {
            return root;
        }

        if (key < root->data) 
        {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->data) 
        {
            root->right = deleteNode(root->right, key);
        } 
        else if(key == root->data)
        {
            if(root->left == NULL && root->right == NULL) 
            {
                node* temp = NULL;
                delete root;
                root = NULL;
                return temp;
            }
            else if (root->left == NULL) 
            {
                node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == NULL) 
            {
                node* temp = root->left;
                delete root;
                return temp;
            }

            node* temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
        return root;
    }
    node* maxValueNode(node* t) 
    {
        node* current = t;
        while (current && current->right != NULL) 
        {
            current = current->right;
        }
        return current;
    }
    void insert(int element)
    {
        insert(root, element);
    }
    int ith_large(int ind)
    {
        return ith_large(root,ind);
    }
    int ith_small(int ind)
    {
        return ith_small(root,ind);
    }
    int sucessor(int ele)
    {
        return sucessor(root,ele);
    }
    int predecessor(int ele)
    {
        return predecessor(root,ele);
    }
    node* deleteNode(int ele)
    {
        return deleteNode(root,ele);
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
                cout<<ab.ith_large(ele)<<endl;
                break;
                
            case 3:
                cin>>ele;
                cout<<ab.ith_small(ele)<<endl;
                break;
                
            case 4:
                cin>>ele;
                cout<<ab.sucessor(ele)<<endl;
                break;
                
            case 5:
                cin>>ele;
                cout<<ab.predecessor(ele)<<endl;
                break;
                
            case 6:
                cin>>ele;
                node *p;
                p = ab.deleteNode(ele);
                break;
        }
    }
    return 0;
}
