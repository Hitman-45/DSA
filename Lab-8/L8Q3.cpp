#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> h;
        vector<vector<int>> a;
        int total = 0;
        a.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a[i].resize(x+1);
            total += x;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<(int)a[i].size()-1; j++)
            {
                cin>>x;
                a[i][j] = x;
            }
            int z = a[i].size()-1;
            a[i][z] = 100000;
            h.push({a[i][0],{i,0}});
        }
        
        for(int i=0; i<total; i++)
        {
            cout<<h.top().first<<" ";
            int x = h.top().second.first;
            int y = h.top().second.second;
            h.pop();
            h.push({a[x][y+1],{x,y+1}});
        }
        
        cout<<endl;
    }
    return 0;
}
