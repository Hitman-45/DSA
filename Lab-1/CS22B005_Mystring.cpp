#include<iostream>
#include <string>
#include <string.h>
using namespace std;

class Mystring
{
    private:
    string s;

    public:
    void set(string t);
    int s_length();
    void init(string p);
    void upper();
    void display();
};

void Mystring::set(string t)
{
    s = t;
}

int Mystring::s_length()
{
    int i = 0, count = 0;

    for(i=0;s[i]!='\0';++i)
	{
	    count++;
	}
    
    return count;
}

void Mystring::init(string p)
{
    s = p+s;
}

void Mystring::upper()
{
    int x = s_length();
    
    for (int i = 0; i < x; i++) 
    { 
        if(s[i]>= 'a' && s[i]<= 'z')
        {
            s[i] = s[i]-32;
        }
    }
}

void Mystring::display()
{
    cout<<s<<endl;
}

int main()
{
    Mystring S;
    string a;
    cin>>a;

    S.set(a);

    
    cout<<"String length: "<<S.s_length()<<endl;
    cout<<"Display : ";
    S.display();
    cout<<"init: ";
    S.init("hello ");
    S.display();
    cout<<"Upper: ";
    S.upper();
    S.display();
    return 0;
}