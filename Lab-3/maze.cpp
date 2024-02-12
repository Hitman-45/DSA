#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
bool issolution(int** a,int m,int n,int r1,int c1,int r2,int c2)
{
    int b[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            b[i][j] = 0;
        }
    }
    if(r2<r1 || c2<c1)
    {
        return false;
    }
    
    queue<pair<int,int>> q;
    q.push({r1,c1});
    b[r1][c1] = 1;
    int z = m*n;
    while(z--)
    {
        int x = q.front().first;
        int y = q.front().second;
        if(x==r2 && y==c2)
        {
            return true;
        }
        if(x < r2 && y < c2 && a[x][y]== 1)
        {
            if(x+1<=r2 && a[x+1][y]==1 && b[x+1][y]==0)
            {
                b[x+1][y]=1;
                q.push({x+1,y});
            }
            if(y+1<=c2 && a[x][y+1]== 1 && b[x][y+1]==0)
            {
                b[x][y+1]=1;
                q.push({x+1,y});
            }
            q.pop();
        }
    }
    
    return false;
}


int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int *a[m];
        for(int i=0; i<m; i++)
        {
           a[i] = new int[n]; 
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        int r1,c1,r2,c2;
        cin>>r1>>c1;
        cin>>r2>>c2;
        
        bool ab = issolution(a,m,n,r1,c1,r2,c2);
        
        if(ab)
           cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        
        for(int i=0; i<m; i++)
        {
           delete []a[i]; 
        }
    }
    return 0;
}
