#include <iostream>
#include <vector>
using namespace std;

class Relation
{
    private:
        int n;
        vector<vector<bool>> R;

    public:
        void init(int k)
        {
            n = k;
            R.resize(n, std::vector<bool>(n, false));
        }
        void add(int x, int y)
        {
            if(x > 0 && x <= n && y > 0 && y <= n)
            {
                R[x-1][y-1] = true;
            }
            else
            {
                cout<<"Given pair is invalid";
            }
            
        } 
        bool isReflexive()
        {
            for(int i=0; i<n; i++)
            {
                if (!R[i][i]) 
                {
                    return false;
                }
            }

            return true;
        } 
        bool isSymmetric()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(R[i][j] != R[j][i])
                    {
                        return false;
                    }
                }
            }
            return true;
        } 
};

int main()
{
    Relation R;
    R.init(3);
    R.add(1,2);
    R.add(2,2);
    R.add(1,1);
    R.add(3,3);
    R.add(2,1);
    cout<<"Given relation is "<<(R.isReflexive() ? "Reflexive":"Not Reflexive")<<endl;
    cout<<"Given relation is "<<(R.isSymmetric() ? "Symmetric":"Not Symmetric")<<endl;
    return 0;
}