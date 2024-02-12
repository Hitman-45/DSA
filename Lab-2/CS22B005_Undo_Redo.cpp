#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
#include <cctype>  // Include for std::toupper and std::tolower

class undo_redo
{
private:
    std::string s;
    std::stack<std::pair<int, int>> s1, bin;

public:
    void init(const std::string& x);
    void changeCase(int i, int j);
    void undo();
    void redo();
    void display();
    void clearStack();
};

void undo_redo::clearStack()
{
    while (!bin.empty())
    {
        bin.pop();
    }
}

void undo_redo::init(const std::string& x)
{
    s = x;
    clearStack();
    while (!s1.empty())
    {
        s1.pop();
    }
}

void undo_redo::changeCase(int i, int j)
{  
        s1.push({i, j});
        for (int k = i; k <= j; k++)
        {
            s[k] = isupper(s[k]) ? std::tolower(s[k]) : std::toupper(s[k]);
        }
}

void undo_redo::undo()
{
    if (!s1.empty())
    {
        // changeCase(s1.top().first, s1.top().second);
        // clearStack();
        for (int k = s1.top().first; k <= s1.top().second; k++)
        {
            s[k] = isupper(s[k]) ? std::tolower(s[k]) : std::toupper(s[k]);
        }
        bin.push({s1.top().first, s1.top().second});
        s1.pop();
    }
}

void undo_redo::redo()
{
    if (!bin.empty())
    {
        //changeCase(bin.top().first, bin.top().second);
        for (int k = bin.top().first; k <= bin.top().second; k++)
        {
            s[k] = isupper(s[k]) ? std::tolower(s[k]) : std::toupper(s[k]);
        }
        s1.push({bin.top().first, bin.top().second});
        clearStack();
    }
}

void undo_redo::display()
{
    std::cout << s << std::endl;
}

int main()
{
    undo_redo x;
    std::string s;
    int a;
    std::cin >> a;
    int t;
    while (a--)
    {
        std::cin >> t;
        switch (t)
        {
        case 1:
            std::cin.ignore();
            // std::getline(std::cin, s);
            cin>>s;
            x.init(s);
            x.clearStack();
            break;
        case 2:
            int i, j;
            std::cin >> i >> j;
            x.changeCase(i, j);
            x.clearStack();
            break;
        case 3:
            x.undo();
            break;
        case 4:
            x.redo();
            x.clearStack();
            break;
        case 5:
            x.display();
            break;
        }
    }
    return 0;
}