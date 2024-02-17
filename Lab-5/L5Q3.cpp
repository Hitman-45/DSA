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
void pre(struct node*t)
{
    if(t==NULL)
        return;

    stack<node*> x;
    x.push(t);

    while (!x.empty())
    {
        struct node* temp = x.top();
        cout << temp->data << " ";
        x.pop();

        if (temp->right)
            x.push(temp->right);
        if (temp->left)
            x.push(temp->left);
    }
}
void post(struct node*t)
{
    if(t==NULL)
        return;

    stack<node*> x;
    x.push(t);
    stack<char> out;
    while (!x.empty())
    {
        struct node* temp_node = x.top();
        x.pop();
        out.push(temp_node->data);

        if (temp_node->left)
            x.push(temp_node->left);
        if (temp_node->right)
            x.push(temp_node->right);
    }

    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
void inorder(struct node*t)
{
    if(t==NULL)
        return;

    stack<node*> x;
    node* current = t;

    while (current != NULL || !x.empty())
    {
        while (current != NULL)
        {
            x.push(current);
            current = current->left;
        }

        current = x.top();
        x.pop();

        cout << current->data << " ";

        current = current->right;
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