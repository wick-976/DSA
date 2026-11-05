#include <bits/stdc++.h>

using namespace std;
void print(int i,int n)
{
    if(i>3) return;
    print(i+1,n);
    cout<<i<<"\n";
}
int main()
{
    int n;
    cin>>n;
    print(1,n);
}