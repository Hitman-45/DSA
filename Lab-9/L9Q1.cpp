#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *a;
        int ans = 0;
        a = new int[n];
        unordered_set<int> h;
        
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            h.insert(a[i]);
        }
        int x = 0;
        for(auto it = h.begin(); it != h.end(); it++)
        {
            x = 0;
            int val = *it;
            if(h.find(val-1) == h.end())
            {
                while(h.find(val)!=h.end())
                {
                    x++;
                    val++;
                }
                
                ans = max(x, ans);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}