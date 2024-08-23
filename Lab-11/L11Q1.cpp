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
    list<int>* adj1;
    vector<int> vec;
    
    public:
    Graph(int x)
    {
        this->V = x; 
        adj = new list<int>[V];
        adj1 = new list<int>[V];
        vec.resize(V);
    }
    
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    
    void DFSUtil(int v, bool visited[], stack<int> &s)
    {
        visited[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                DFSUtil(*i, visited, s);
                s.push(*i);
            }
            // s.push(*i);
        }
    }
    void transpose()
    {
        for(int i=0; i<V; i++)
        {
            list<int>::iterator i1;
            for (i1 = adj[i].begin(); i1 != adj[i].end(); ++i1)
            {
                adj1[*i1].push_back(i);
            }
        }
    }
    void DFSUtil1(int v, bool visited[], int z)
    {
        visited[v] = true;
        vec[v] = z;
        
        list<int>::iterator i;
        for (i = adj1[v].begin(); i != adj1[v].end(); ++i)
        {
            if (!visited[*i])
            {
                DFSUtil1(*i, visited, z);
            }
        }
    }
    void scc()
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        
        stack<int> s;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                DFSUtil(i,visited,s);
                s.push(i);
            }
        }
        
        transpose();
        
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        
        int z = 1;
        
        while(!s.empty())
        {
            int i = s.top();
            s.pop();
            // cout<<visited[i]<<" ";
            
            if(!visited[i])
            {
                // cout<<i<<" ";
                DFSUtil1(i, visited,z);
                z++;
            }
        }
        
    }
    
    int IsSC(int x, int y)
    {
        if(vec[x] == vec[y])
        {
            return 1;
        }
        
        return 0;
    }
    
    
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        Graph G(n);

        for(int i=0; i<m; i++)
        {
            int x, y;
            cin>>x>>y;
            G.addEdge(x, y);
        }
        
        G.scc();
        
        for(int i=0; i<q; i++)
        {
            int x,y;
            cin>>x>>y;
            cout<<G.IsSC(x,y)<<endl;
        }
       
    }
    return 0;
}
