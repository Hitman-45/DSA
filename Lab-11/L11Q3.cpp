#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void dfs(vector<int> adj[], int V, vector<int>& vis, int i, int curr)
{
    vis[curr] = 1;
    for (auto x : adj[curr]) {
        if (x != i) {
            if (!vis[x]) {
                dfs(adj, V, vis, i, x);
            }
        }
    }
}

void DFSUtil(int v, bool visited[], vector<int> adj[])
{
    stack<int> a;
    a.push(v);
    while (!a.empty()) 
    {
        int current = a.top();
        a.pop();
        if (visited[current]) 
        {
            continue;
        }
        visited[current] = true;
        for (int i : adj[current]) 
        {
            a.push(i);
        }
    }
}

int compo(vector<int> adj[], int V)
{
    int ans = 0;
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) 
    {
        if (!visited[i]) 
        {
            DFSUtil(i, visited, adj);
            ans += 1;
        }
    }

    return ans;
}

void connected(vector<int> adj[], int V)
{
    vector<int> cutV;
    int before = compo(adj,V);
    for (int i = 0; i<V; i++) 
    {
        int components = 0;
        vector<int> vis(V, 0);

        for (int j = 0; j<V; j++) 
        {
            if (j != i) 
            {
                if (!vis[j]) 
                {
                    components++;
                    dfs(adj, V, vis, i, j);
                }
            }
        }
        
        if (components > before) 
        {
            cutV.push_back(i);
        }
    }
    
    cout<<cutV.size()<<endl;
    if(cutV.size() != 0)
    {
        for (int i = 0; i<(int)cutV.size(); i++) 
        {
            cout<<cutV[i]<<" ";
        }
        cout<<endl;
    }
    
}

bool isCutEdge(vector<int> adj[], int V, int u, int v)
{
    int before = compo(adj,V);
    
    vector<int> adj1[V];

    for (int i = 0; i < V; ++i) 
    {
        for (int j : adj[i]) 
        {
            if ((i != u || j != v) && (i != v || j != u)) 
            {
                adj1[i].push_back(j);
            }
        }
    } 
    
    int after = compo(adj1,V);
    return after > before;
}

void printCutEdges(vector<int> adj[], int u)
{
    set<pair<int,int>> s;
     for (int i = 0; i < u; i++) 
     {
        for (int j = 0; j <(int)adj[i].size(); j++) 
        {
            int v = adj[i][j];
            if (i < v && isCutEdge(adj, u, i, v)) 
            {
                s.insert({min(i, v), max(i, v)});
            }
        }
    }
    
    cout <<  s.size() << endl;
    if(s.size() != 0){
        for (auto edge : s) {
            cout << edge.first << " " << edge.second << endl;
        }    
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        addEdge(adj,x, y);
    }
    
    connected(adj,n);
    printCutEdges(adj,n);
    return 0;
}
