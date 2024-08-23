#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class ABC{
private:
    vector<int> parent;
    vector<int> rank;

public:
    ABC(int n) 
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;  
    }

    int find(int x) 
    {
        if (parent[x] == x) 
        {
            return parent[x];
        }
        
        return parent[x] = find(parent[x]);
    }

    void union_sets(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) 
        {
            if (rank[rootY] > rank[rootX]) 
            {
                parent[rootX] = rootY;
                rank[rootY]++;
            } 
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    ABC uf(n);

    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        uf.union_sets(u, v);
    }

    for (int i = 0; i < n; i++) 
    {
        int r = uf.find(i);
        cout<<r<< " ";
    }
    
    cout<< endl;
    return 0;
}
