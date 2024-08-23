#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int func(int a[], int n, int k)
{
    int sum = 0;
    int l = 0, r = 0;
    
    while (r < n) 
    {
        sum += a[r];
        if (sum == k)
            return 1;
        
        while (sum > k && l <= r) 
        {
            sum -= a[l];
            l++;
            if (sum == k)
                return 1;
        }

        r++;
    }
    
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int *a;
        a = new int[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        
        cout<<func(a,n,k)<<endl;
    }
    return 0;
}
