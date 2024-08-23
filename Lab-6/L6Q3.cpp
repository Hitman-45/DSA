#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
using namespace std;


int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        
        istringstream iss(s);
        map<string, int> wordFreq;
        
        string word;
        while (iss >> word) {
            ++wordFreq[word];
        }
        
        set<string> uniqueWords;
        for (const auto& pair : wordFreq) {
            uniqueWords.insert(pair.first);
        }

        for (const auto& word : uniqueWords) {
            cout << word << " " << wordFreq[word] <<endl;
        }
        
        cout<<endl;
    }
    return 0;
}
