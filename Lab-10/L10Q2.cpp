#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int shortestChainLen(string start, string target, set<string>& D)
{
    if(start == target)
        return 0;
    
    if(D.find(target)==D.end())
        return 0;
    
    int level = 0, wordlength = start.size();
    queue<string> Q;
    Q.push(start);
    
    while (!Q.empty()) {
        
        ++level;
        int sizeofQ = Q.size();

        for (int i = 0; i < sizeofQ; ++i) 
        {
            string word = Q.front();
            Q.pop();
            
            for (int pos = 0; pos < wordlength; ++pos) 
            {
                char orig_char = word[pos];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[pos] = c;
 
                    if (word == target)
                        return level;
 
                    if (D.find(word) == D.end())
                        continue;
                    
                    
                    D.erase(word);
                    Q.push(word);
                }
                word[pos] = orig_char;
            }
        }
    }
    
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<string> D;
        string start, target, x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            D.insert(x);
        }
        cin>>start>>target;
        
        cout <<shortestChainLen(start, target, D)<<endl;
    }
    return 0;
}
