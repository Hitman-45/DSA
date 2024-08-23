#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool ABC(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2)
        return false;
 
    sort(str1.begin(), str1.end());
    
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;
 
    return true;
}

int main() {
    int n;
    cin>>n;
    vector<string> v;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    
    string target;
    cin>>target;
    sort(target.begin(), target.end());
    
    int w = 0;
    for(int i=0; i<n; i++)
    {
        if(ABC(v[i],target))
        {
            w = 1;
            cout<<i<<" ";
        }
    }
    
    if(w==0)
    {
        cout<<"-1";
    }
    cout<<endl;
    return 0;
}
