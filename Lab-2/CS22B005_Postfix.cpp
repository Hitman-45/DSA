#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

int ans(const string& expression)
{
    stack<int> x;
    
    stringstream ss(expression);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            x.push(stoi(token));
        } 
        else
        {
            int operand2 = x.top();
            x.pop();
            int operand1 = x.top();
            x.pop();

            switch (token[0]) {
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
    cin>>t;
    cin.ignore(); 
    while(t--)
    {
        string expression;
        getline(cin, expression);
        
        cout<<ans(expression)<<endl;
    }
    return 0;
}
