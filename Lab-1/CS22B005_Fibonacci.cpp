#include<iostream>
#include<chrono>
using namespace std;

int fib1(int n)
{
    if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        return fib1(n-1) + fib1(n-2);
    }
}

int fib2(int n)
{
    int a[n];
    a[0] = 1;
    a[1] = 1;
    for(int i=2; i<n; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n-1];
}

int main()
{
    int n;
    long long result1, result2;

    cin>>n;

    auto start1 = std::chrono::high_resolution_clock::now();
    result1 = fib1(n);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    result2 = fib2(n);
    auto end2 = std::chrono::high_resolution_clock::now();

    cout<<"(with recursion) fibonaci num is: "<<result1<<"\n";
    cout<<"(with loop) fibonaci num is: "<<result2<<"\n";

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

    cout<<duration1<<" nano seconds"<<endl;
    cout<<duration2<<" nano seconds"<<endl;

    return 0;
}