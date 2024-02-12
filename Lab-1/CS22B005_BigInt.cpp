#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

string BigInt(string a, string b)
{
    a.erase(0, min(a.find_first_not_of('0'), a.size()-1));
    b.erase(0, min(b.find_first_not_of('0'), b.size()-1));

    int max, min;
    string ans = "";
    if(a.length() < b.length()){ 
        swap(a, b);
    }

    max = a.length();
    min = b.length();

    int carry = 0;
    int diff = max-min;
    for(int i=min-1; i>=0; i--)
    {
        int sum = ((a[i+diff]-'0')+(b[i]-'0')+carry);
        ans.push_back(sum%10 + '0'); 
        carry = sum/10;
    }

    for (int i=diff-1; i>=0; i--) 
    { 
        int sum = ((a[i]-'0')+carry); 
        ans.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
 
    if (carry) 
        ans.push_back(carry+'0');

    reverse(ans.begin(), ans.end()); 
 
    return ans;
}

int main()
{
    string a,b;
    cout<<"enter your 1st String: ";
    cin>>a;
    cout<<"enter your 2st String: ";
    cin>>b;

    cout<<"Answer: "<<BigInt(a,b);
    return 0;
}