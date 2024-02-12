#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class mystack
{
    private:
        int data[1000];
        int topindex;
    
    public:
    mystack()
    {
        topindex = -1;
    }
    void push(int x)
    {
        topindex++;
        data[topindex] = x;
    }
    void pop()
    {
        topindex--;            
    }
    int top()
    {
        return data[topindex];
    }
    int size()
    {
        return topindex+1;
    }
    bool isempty()
    {
        if(topindex == -1)
        {
            return true; 
        }
        
        return false;
    }
};

            
int ans(string s)
{
    mystack x;
    string m = "";
    for(int i=0; s[i]; ++i)
    {
        if(isspace(s[i]))
        {
            if(m!="")
            {
                int g = stoi(m); 
                x.push(g);
            }
                m="";
        }
        
        if(s[i]>='0' && s[i]<='9'){
            m=m+s[i];
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            int operand2 = x.top();
            x.pop();
            int operand1 = x.top();
            x.pop();
            switch (s[i])
            {
                case '+':
                    x.push(operand1 + operand2);
                    break;
                case '-':
                    x.push(operand1 - operand2);
                    break;
                case '*':
                    x.push(operand1 * operand2);
                    break;
                case '/':
                    x.push(operand1 / operand2);
                    break;
                case '^':
                    x.push(pow(operand1, operand2));
                    break;
            }
        }
    }
    
    return x.top();
}

int main() {  
    int t;
    cin >> t;
    cin.ignore(); 
    string expression;
    while (t--) 
    {
        getline(cin, expression);
        int result = ans(expression);
        cout << result << endl;
    }
    return 0;
}