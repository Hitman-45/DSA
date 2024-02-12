#include<iostream>
#include<stack>
using namespace std;


bool isParanthesis(string s)
{
    int l = s.length();
    stack<char> x;

    for(int i=0; i<l; i++)
    {
        if( s[i]=='[' || s[i]=='{' || s[i]=='(')
        {
            x.push(s[i]);
        }
        else if( s[i]==']' || s[i]=='}' || s[i]==')')
        {
            if(x.empty()) {
                return false;
            }
            char c=x.top();
            if(c=='[' && s[i] == ']')
            {
                x.pop(); 
            }
            else if(c=='{' && s[i] == '}')
            {
                x.pop();
            }
            else if(c=='(' && s[i] == ')')
            {
                x.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if(x.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        cin>>s;
        cout<<isParanthesis(s)<<endl;
    }
    return 0;
}