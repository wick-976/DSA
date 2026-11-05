#include <bits/stdc++.h>
using namespace std;

//printing the sum of numbers using the 
//rescursion (parameterized way)
void print(int n,int sum)
{
    if(n<1)
    {
        cout<<sum;
        return;
    }
    print(n-1,sum+n);
}

//this the way of printing the recursion using the functionl way
int f(int n)
{
    if(n==0) return 0;

    return n+f(n-1);
}

int main()
{
    int n;
    cin>>n;
    print(n,0);
    cout<<f(n);
}

//Now Printing using the Funtional way