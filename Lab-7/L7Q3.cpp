#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void black_box(int *a, int *b, int m, int n)
{
    multiset<int> s; 
    int c=0;
    for(int i=0; i<n; i++)
    {
        int k=0;
        for(int j=c; j<b[i]; j++)
        {
            s.insert(a[j]);
            c++;
        }
        set<int>::iterator it;
        it=s.begin();
        while(k<i)
        {
            it++; k++;
        }
        if(k==i) cout<<*it<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int *a;
        int *b;
        a = new int [m];
        b = new int [n];
        for(int i=0; i<m; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        
        black_box(a,b,m,n);
        
        if(t>1)
            cout<<endl;
    }
    return 0;
}
