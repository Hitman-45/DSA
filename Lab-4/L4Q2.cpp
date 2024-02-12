#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* addNode(int data, Node* tail) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    return newNode;
}

Node* createLinkedList(const string& num) {
    int l = num.length();
    Node* head = new Node(num[l-1] - '0');
    Node* tail = head;

    for (int i = l-2; i >= 0; i--) {
        tail = addNode(num[i] - '0', tail);
    }

    return head;
}

string BigInt(Node* a, Node* b)
{
    string ans = "";
    int carry = 0;
    
    while (a != nullptr || b != nullptr || carry != 0) 
    {
        int sum = carry + (a ? a->data : 0) + (b ? b->data : 0);

        carry = sum / 10;
        ans.push_back(sum%10 + '0');

        if (a) a = a->next;
        if (b) b = b->next;
    }

    reverse(ans.begin(), ans.end()); 
 
    return ans;
}

int main() {
   int t;
    cin>>t;
    while(t--)
    {
        string a,b;

        cin>>a;
        cin>>b;

        if(a.length() < b.length())
        { 
            swap(a, b);
        }


        Node* num1 = createLinkedList(a);
        Node* num2 = createLinkedList(b);

        cout<<BigInt(num1, num2)<<endl;

        while (num1 != nullptr) {
            Node* temp = num1;
            num1 = num1->next;
            delete temp;
        }

        while (num2 != nullptr) {
            Node* temp = num2;
            num2 = num2->next;
            delete temp;
        }
    }

    return 0;
}