#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Heap
{
    private:
    int size;
    int *a;
    int count;
    void heapify(int index)
    {
        int i, left, right, next;
        i = index; left = 2*index; right = 2*index+1;
        
        if(left > count) return;
        else if(left<=count && right<=count)
        {
            if(a[left]<a[right])
                next = left;
            else
                next = right;
            
            if(a[i]>a[next])
            {
                swap(a[i],a[next]);
                heapify(next);
            }
        }
        else if(left<=count)
        {
            if(a[i]>a[left])
            {
                swap(a[left],a[i]);
                heapify(left);
            }
        }
    }
    
    public:
    Heap(int s)
    {
        count = 0;
        size = s;
        a = new int[s+1];
    }
    void Insert(int value)
    {
        int i;
        count++;
        i = count;
        a[i] = value;
        while(i/2 >= 1)
        {
            if(a[i/2]<=a[i]) break;
            if(a[i/2]>a[i])
            {
                swap(a[i],a[i/2]);
                i = i/2;
            }
        }
    }
    int abstMin()
    {
        int temp = a[1];
        a[1] = a[count];
        count--;
        
        if(count>=2)
        {
            heapify(1);
        }
        return temp;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Heap H(n);
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            H.Insert(x);
        }
        for(int i=0; i<n; i++)
        {
            cout<<H.abstMin()<<" ";
        }
        cout<<endl;
    }
    return 0;
}
