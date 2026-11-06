#include <bits/stdc++.h>
using namespace std;

void subsequence(int idx,int sum,vector<int>arr,int s,vector<int> & sum_arr)
{
    if(idx==arr.size())
    {
        if(s==sum)
        {
            for(int x: sum_arr)
                {
                    cout<<x<<" ";
                }
            cout<<endl;
          
        }

    return;
    }

        sum_arr.push_back(arr[idx]);
        s+=arr[idx];
        subsequence(idx+1,sum,arr,s,sum_arr);

        s-=arr[idx];
        sum_arr.pop_back();
        subsequence(idx+1,sum,arr,s,sum_arr);
        

        
    }

int main()
{
    int sum=2;
    int s=0;

    vector<int>arr={1,2,1};
    vector<int>sum_arr;

    subsequence(0,sum,arr,s,sum_arr);
}