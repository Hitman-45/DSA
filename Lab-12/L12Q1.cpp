#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    struct TrieNode* child[60];
    bool eow;
};

struct TrieNode* createnode()
{
    struct TrieNode* pNode = new TrieNode;
    pNode->eow = false;
    
    for (int i = 0; i < 60; i++)
        pNode->child[i] = NULL;
 
    return pNode;
}

void insert(struct TrieNode* t, string word)
{
    int i;
    for(char c : word)
    {
        i = c-'A';
        if(t->child[i] == NULL)
        {
            t->child[i] = createnode();
        }
        t = t->child[i];
    }
    t->eow = true;
}

bool isLast(struct TrieNode* root)
{
    for (int i = 0; i < 60; i++)
        if (root->child[i])
            return 0;
    
    return 1;
}

void suggestions(struct TrieNode* root, string pre)
{
    if (root->eow)
        cout << pre << endl;
 
    for (int i = 0; i < 60; i++)
    {
        if (root->child[i]) 
        {
            char ch = 'A' + i;
            suggestions(root->child[i], pre + ch);
        }
    }
}

int print(TrieNode* root, const string query)
{
    struct TrieNode* temp = root;
    for (char c : query) 
    {
        int ind = c-'A';
        if (!temp->child[ind])
            return 0;
 
        temp = temp->child[ind];
    }
    if(isLast(temp) == 1) 
    {
        cout << query << endl;
        return 1;
    }
    suggestions(temp, query);
    return 1;
}

int main() {
    int n,q;
    cin>>n>>q;
    struct TrieNode* root = createnode();
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        insert(root, s);
    }
    
    for(int i=0; i<q; i++)
    {
        string s;
        cin>>s;
        int comp = print(root,s);
        
        if(comp == 0)
        {
            cout<<"not found"<<endl;
            if(i != q-1)
                cout<<endl;
        }
        else if(i != q-1)
        {
            cout<<endl;
        }
    }
    
    return 0;
}
