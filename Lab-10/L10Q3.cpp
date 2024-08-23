#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct cell 
{
    int x, y, dis;
    cell() {}
    cell(int _x, int _y, int _dist) : x(_x), y(_y), dis(_dist) {}
};

bool isvalid(int x, int y, int N) {
    if(x >= 1 && y >= 1 && x <= N && y <= N)
        return true;
    return false;
}

int short_dis(int N, int r1, int c1, int r2, int c2)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    
    queue<cell> q;
    
    bool visit[N + 1][N + 1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
    
    int x, y;
    q.push(cell(r1, c1, 0));
    visit[r1][c1] = true;
    
    while(!q.empty())
    {
        cell t = q.front();
        q.pop();
        
        if (t.x == r2 && t.y == c2)
            return t.dis;
 
        for (int i = 0; i < 8; i++) 
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
 
            if (isvalid(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
        
    }
    
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int r1, r2, c1, c2;
        cin>>r1>>c1>>r2>>c2;
        
        cout << short_dis(n, r1, c1, r2, c2)<<endl;
    }
    return 0;
}
