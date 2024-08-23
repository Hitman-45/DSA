#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long int binomialCoeff(long long int n, long long int k) 
{
    if (k == 0 || k == n) 
    {
        return 1;
    }
    if(k == n-1 || k == 1)
    {
        return n;
    }
    
    return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}

long long int permu(long long int n, vector<long long int>& a)
{
    vector<long long int> left, right;
    if(n<=2)
    {
        return 1;
    }
    for(long long int i=1; i<n; i++)
    {
        if(a[i]<a[0])
        {
            left.push_back(a[i]);
        }
        else
        {
            right.push_back(a[i]);
        }
    }
    
    long long int ls = left.size();
    long long int rs = right.size();
    
    long long int leftCount = permu(ls, left);
    long long int rightCount = permu(rs, right);
    
    return binomialCoeff(ls+rs, ls) * leftCount * rightCount;
    
}

int main() 
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<long long int> a(n);
        for (long long int i = 0; i < n; ++i) 
        {
            cin >> a[i];
        }

        long long int result = permu(n, a);
        cout << result << endl;
    }
    return 0;
}
