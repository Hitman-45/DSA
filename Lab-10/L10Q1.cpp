#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    int V;
    list<int>* adj;
    
    public:
    Graph(int x)
    {
        this->V = x; 
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int connected()
    {
        int ans = 0;
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < V; i++) 
        {
            if (visited[i] == false) 
            {
                DFSUtil(i, visited);
                ans += 1;
            }
        }

        return ans;
    }

    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                DFSUtil(*i, visited);
            }
        }
    }
};
 
int main() {
    
    int n, m;
    cin>>n>>m;
    Graph G(n);

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        G.addEdge(x, y);
    }

    cout<<G.connected()<<endl;
    return 0;
}
