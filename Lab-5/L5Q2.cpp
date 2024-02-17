#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

node* createnode(char x)
{
    struct node*p;
    p = new node();
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

node *tree(string s)
{
    struct node*head;
    stack<struct node*> x;
    string m = "";
    int l = s.length();
    for(int i=0; i<l; ++i)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            
            head = createnode(s[i]);
            x.push(head);
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            struct node* tail;
            tail = createnode(s[i]);
            struct node* operand2 = x.top();
            x.pop();
            struct node* operand1 = x.top();
            x.pop();
            
            tail->left = operand1;
            tail->right = operand2;
            x.push(tail);

        }
    }

    return x.top();
}
void pre(struct node*p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" "; 
        pre(p->left);
        pre(p->right);
    }
}

void post(struct node*t)
{
    if(t!=NULL)
    {
        post(t->left);
        post(t->right);
        cout<<t->data<<" ";
    }
}

void inorder(struct node*t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        struct node*x;
        x = tree(s);
        inorder(x);
        cout<<endl;
        pre(x);
        cout<<endl;
        post(x);
        cout<<endl;
    }
    return 0;
}