#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string comp(int n, int b[])
{
    stack<int> s;
    int j=0;
    for(int i=1; i<=n; i++)
    {
        s.push(i);
        while(s.size()>0 && s.top()==b[j])
        {
            s.pop();
            j++;
        }
    }
    
    if(s.size() == 0)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main() {
    int n; 
    
    while (cin >> n && n != 0) 
    {
        int coaches[n];
        while(true)
        {
            int z=0;
            for (int i = 0; i < n; i++) 
            {
                cin >> coaches[i];
                if(coaches[i]==0)
                {
                    z=1;
                    break;
                }
            }
            if(z==1)
            {
                cout<<endl;
                break;
            }
            cout << comp(n, coaches)<<endl;
        }
    }
    return 0;
}
