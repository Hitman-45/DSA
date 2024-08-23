#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

class binaryTree
{
    private:
        node *root;
    
    public:
        binaryTree()
        {
            root = NULL;
        }

        void createTree(int *input,int *randomInput,int total_nodes)
        {
            int j = 0;
            for(int i=0;i<total_nodes;i++)
            {
                insertNode(input[i],randomInput,&j);
            }
        }

        void insertNode(int key,int *randomInput, int *j)
        {
            node *temp = new node();
            temp->data = key;
            temp->right = NULL;
            temp->left = NULL;

            if(root!=NULL)
            {
                bool inserted = false;
                node *p = root;
                while(!(inserted))
                {
                    int currRandom = randomInput[*j];
                    *j = *j + 1;

                    if(currRandom == 0)
                    {
                        if(p->left == NULL)
                        {
                            p->left = temp;
                            inserted = true;
                        }
                        else
                        {
                            p = p->left;
                        }
                    }
                    else
                    {
                        if(p->right == NULL)
                        {
                            p->right = temp;
                            inserted = true;
                        }
                        else
                        {
                            p = p->right;
                        }
                    }
                }    
            }    
            else
            {
                root = temp;
            }    
        }

        void toBST()
        {
            vector<int> v1;
            int t=0;
            inorder(root,v1);
            sort(v1.begin(),v1.end());
            inorder1(root,v1,&t);
        }
        void inorder1(struct node*t,vector<int> &v,int *x)
        {
            if (t != NULL)
            {
                inorder1(t->left,v,x);
                t->data = v[*x];
                (*x)++;
                inorder1(t->right,v,x);
            }
        }
        void inorder(struct node*t,vector<int> &v)
        {
            if (t != NULL)
            {
                inorder(t->left,v);
                v.push_back(t->data);
                inorder(t->right,v);
            }
        }
        void pre(struct node*t,vector<int> &v)
        {
            if(t!=NULL)
            {
                v.push_back(t->data); 
                pre(t->left,v);
                pre(t->right,v);
            }
        }
        void inorder()
        {
            vector<int> v;
            inorder(root,v);
            for(int i=0; i<(int)v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
        }
        void preorder()
        {
            vector<int> v;
            pre(root,v);
            for(int i=0; i<(int)v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
        }
};

int main()
{
    binaryTree T;
    int total_nodes,seq_size,*input,*randomInput;
    cin>>total_nodes>>seq_size;

    input = (int*)malloc(sizeof(int)*total_nodes);
    randomInput = (int*)malloc(sizeof(int)*seq_size);

    for(int i=0;i<total_nodes;i++)
    {
        cin>>input[i];
    }

    for(int i=0;i<seq_size;i++)
    {
        cin>>randomInput[i];
    }

    T.createTree(input,randomInput,total_nodes);
    T.toBST();
    T.inorder();
    cout<<endl;
    T.preorder();

}