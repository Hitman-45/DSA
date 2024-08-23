#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words, int k) 
{
    unordered_map<char, unordered_set<char>> g;
    vector<int> indegree(k);
    
    for (const string& word : words) 
    {
        for (char c : word) 
        {
            indegree[c-'a'] = 0;
        }
    }
    
    for (int i = 0; i < (int)words.size() - 1; ++i) 
    {
        string curr = words[i];
        string next = words[i + 1];
        int minLength = min(curr.size(), next.size());
        
        for (int j = 0; j < minLength; ++j) 
        {
            char currChar = curr[j];
            char nextChar = next[j];
            if (currChar != nextChar) 
            {
                if(!g[currChar].count(nextChar))
                {
                    g[currChar].insert(nextChar);
                    indegree[nextChar-'a']++;
                }
                break;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < (int)indegree.size() ; ++i) 
    {
        if (indegree[i] == 0) 
        {
            q.push(i);
        }
    }
    
    string result = "";
    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();
        result += (char)(curr+97);
        vector<int> v;
        for (char neighbor : g[curr+'a']) 
        {
            indegree[neighbor-'a']--;
            if (indegree[neighbor-'a'] == 0) 
            {
                v.push_back(neighbor-'a');
            }            
        }
        sort(v.begin(),v.end());
        for(int i=0; i<(int)v.size(); i++)
        {
            q.push(v[i]);
        }
    }

    return result;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cin.ignore();
        vector<string> words(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> words[i];
        }
        cout <<alienOrder(words,k)<< endl;
    }
    return 0;
}
