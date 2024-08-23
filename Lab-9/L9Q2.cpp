#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

bool isom(string s1, string s2)
{
    if(s1.length()!=s2.length())
    {
        return 0;
    }
    unordered_map<char, char> m;
    multiset<char> s;
    for(int i=0; i<(int)s1.length(); i++)
    {
        if(m.find(s1[i]) != m.end() && m[s1[i]] != s2[i]) 
        {
            return 0;
        }
        if(m.find(s1[i]) == m.end() && s.find(s2[i]) != s.end()) 
        {
            return 0;
        }
        m[s1[i]] = s2[i];
        s.insert(s2[i]);
    }
    
    
    return 1;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        cout<<isom(s1,s2)<<endl;
    }
    return 0;
}