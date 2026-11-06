#include <bits/stdc++.h>
using namespace std;
void f(int i,vector<int>n,vector<int> &arr)
{

    if(i>=n.size())
    {
        for(int x: arr)
            {
                cout<<x<<" ";
            }
        cout<<"\n";
        return;
    }
    arr.push_back(n[i]);
    f(i+1,n,arr);
    arr.pop_back();
    f(i+1,n,arr);
    if(n.size()==0) 
    {
        cout<<"{}";
    }
    
    
    
}
int main()
{
    vector<int>n={3,1,2};
    vector<int>arr;
    f(0,n,arr);
}