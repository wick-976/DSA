#include <bits/stdc++.h>
using namespace std;
void print(int a,int n)
{
      if(a>n) return;

      cout<<"Tharan"<<"\n";
      print(a+1,n);
}
int main()
{
    int n;
    cin>>n;
    print(1,n);
}