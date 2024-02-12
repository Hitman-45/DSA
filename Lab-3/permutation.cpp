#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
void Solution(string s)
{
    int l = s.length();
    for(int i=0; i<l-1; i++)
    {
        for(int j=i+1; j<l; j++)
        {
            if(s[i]>s[j])
            {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    queue<string> q;
    
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
    }
    return 0;
}
