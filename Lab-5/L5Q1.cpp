#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct node
{
    int data;
    char op;
    struct node* left;
    struct node* right;
};

node* createnode(int x)
{
    struct node*p;
    p = new node();
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

node* createnode(char x)
{
    struct node*p;
    p = new node();
    p->op = x;
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
        else if(s[i]>='0' && s[i]<='9'){
            m=m+s[i];
        }
        else if(isspace(s[i]))
        {
            if(m!="")
            {
                int g = stoi(m);
                head = createnode(g);
                x.push(head);
            }
                m="";
        } 
    }
    
    return x.top();
}
int compute(int x, int y, char c)
{
    if(c=='+')
        return x+y;
    else if(c == '-')
        return x-y;
    else if(c== '*')
        return x*y;
    else if(c=='/')
        return x/y;
    else if(c=='^')
        return pow(x,y);

    return 0;
}
int evalution(struct node* p)
{
    int answer;
    if(p->right == NULL && p->left == NULL)
    {
        int x = p->data;
        return x;
    }
    int x = evalution(p->left);
    int y = evalution(p->right);
    answer = compute(x,y,p->op);
    return answer;
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
        cout<<evalution(x)<<endl;
    }
    return 0;
}