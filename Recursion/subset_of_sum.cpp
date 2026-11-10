//this is not a fully completed one we stil need to put the sum into vector
//and then sort it in begin to end print one by one which is easy peasy 
//this is enogh for this
#include <bits/stdc++.h>
using namespace std;
void comb(int start,int end,vector<int>& arr,int sum)
{
    if(start==end)
    {
        cout<<sum<<"\n";
        return;
    }

    comb(start+1,end,arr,sum+arr[start]);

    comb(start+1,end,arr,sum);
}

int main()
{
    vector<int>arr={3,1,2};
    int sum=0;
    comb(0,arr.size(),arr,sum);
}
