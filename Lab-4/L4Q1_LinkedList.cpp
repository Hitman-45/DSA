#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class LinkedList
{
  private:
    struct node* head;
    // struct node* last;
    int count = 0;
  public:  
    void append(int x);
    void insertAt(int pos, int val);
    void deleteAt(int pos);
    void updateAt(int pos, int val);
    void reverse();
    void display();
    node* createnode(int val)
    {
        node* p = new node;
        p->data = val;
        p->next = NULL;
        return p;
    }
    ~LinkedList() {
        node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void LinkedList :: append(int val)
{
    struct node* temp;
    node* tail;
    tail = head;
    if(count==0)
    {
        temp = createnode(val);
        head = temp;
    }
    else
    {
        temp = createnode(val);
        while(tail->next) 
        {
            tail = tail->next;
        }
        tail->next = temp;
    }
    
    count++;
}


void LinkedList :: insertAt(int pos, int val)
{
    struct node* tail;
    struct node* temp;
    temp = createnode(val);
    tail = head;
    if(pos==1)
    {
        temp->next = head;
        head = temp;
        count++;
    }
    else
    {
        for(int i=1; i<pos-1 && tail; i++)
        {
            tail = tail->next;
        }
        temp -> next = tail->next;
        tail -> next = temp;
        count++;
    }
}

void LinkedList :: deleteAt(int pos)
{
    struct node* tail;
    struct node* temp;
    tail = head;
    if (pos == 1)
    {
        if (head)
        {
            temp = head;
            head = head->next;
            delete temp;
            count--;
        }
    } 
    else 
    {
        for(int i=1; i<pos-1 && tail; i++)
        {
            tail = tail->next;
        }
        if (tail && tail->next)
        {
            temp = tail->next;
            tail->next = temp->next;
            delete temp;
            count--;
        }
    }
}

void LinkedList :: updateAt(int pos, int val)
{
    struct node* tail;
    tail = head;
    for(int i=1; i<pos && tail; i++)
    {
        tail = tail->next;
    }
    if (tail) 
    {
       tail->data = val;
    }
}

void LinkedList :: reverse()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    else
    {
        node* curr = head;
        node* prev = NULL;
        node* ne = NULL;
        while(curr)
        {
            ne = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ne;
        }

        head = prev;
    }
}
void LinkedList :: display()
{
    struct node* tail = head;
    while(tail)
    {
        cout<<(tail->data)<<" ";
        tail = tail->next;
    }
    
    cout<<endl;
}

int main() {

    int t = 0;
    LinkedList l;
    int val,pos;
    while(t!=7)
    {
        cin>>t;
        switch(t)
        {
            case 1:
                cin>>val;
                l.append(val);
                break;
            case 2:
                cin>>pos>>val;
                l.insertAt(pos,val);
                break;
            case 3:
                cin>>pos;
                l.deleteAt(pos);
                break;
            case 4:
                cin>>pos>>val;
                l.updateAt(pos,val);
                break;
            case 5:
                l.reverse();
                break;
            case 6:
                l.display();
                break;
        }
    }
    
    return 0;
}