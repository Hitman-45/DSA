#include <iostream>
#include <vector>
using namespace std;

class SortedArray 
{
    private:
        vector<int> arr;

    public:
        void reserve(int k)
        {
            arr.reserve(k);
        }

        int size() 
        {
            return arr.size();
        }

        void insert(int x) 
        {
            auto it = lower_bound(arr.begin(), arr.end(), x);
            arr.insert(it, x);
        }

        void remove(int x)
        {
            auto it = std::lower_bound(arr.begin(), arr.end(), x);
            for(int i = 0; i< arr.size(); i++) 
            {
                if(arr.at(i) == x)
                {
                    arr.erase(it);                    
                }
            }

            
        }

        bool search(int x) 
        {
             for(int i = 0; i< arr.size(); i++) 
            {
                if(arr.at(i) == x)
                {
                    return true;
                }
            }

            return false;
        }

        void display() {
            for (int num : arr) 
            {
                cout << num << " ";
            }
            cout<<endl;
        }
};

int main() {
    SortedArray S;
    
    S.reserve(10);
    S.insert(5);
    S.insert(3);
    S.insert(8);
    S.insert(1);
    cout << "Size: " << S.size() <<endl;
    cout << "Search for 8: " <<(S.search(8)? "True" : "False")<<endl;
    S.display();
    S.remove(3);
    cout << "Size after deleting 3: " << S.size() <<endl;
    S.display();

    return 0;
}