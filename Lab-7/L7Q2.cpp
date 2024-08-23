#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int n;
    cin>>n;
    while(n)
    {
        multiset<int> s;
        int count=0;
        multiset<int>::iterator it1,it2;
        for(int i=0; i<n; i++)
        {
            int t;
            cin>>t;
            while(t--)
            {
                int x;
                cin>>x;
                s.insert(x);
            }
            
            it1 = s.begin();
            it2 = s.end();
            it2--;
            count += (*it2)-(*it1);
            s.erase(it1);
            s.erase(it2);
        }
        cout<<count<<endl;
        cin>>n;
    }
    return 0;
}
