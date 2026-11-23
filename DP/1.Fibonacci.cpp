//1)in this we are gonna code the fibonacci using the memoization method
//2)we are having  a vector(dp array) of n+1 to store the function answer 
//3)for every function we check if we already marked the dp array or not if it marked 
//we are gonna simply return for exaple when f(2) answer 1 in the dp array we will mark 
//the 2nd index as the 1 since which is the answer so when ever we are seeing the f(2) 
//instead of doing recursion again and again we can simply return dp[n] by doing this 
//we can reduce the space complexity

//code using memoization method

#include <bits/stdc++.h>
using namespace std;

int f(int n,vector<int>& dp)
{
    if(n<=1) return 1;

    if(dp[n]!=-1) return dp[n];

    return dp[n]=f(n-1,dp)+f(n-2,dp);
}
int main()
{
    int n;
    cin>>n;

    vector<int>dp(n+1,-1);

    cout<<f(n,dp);
}


//now we are using the tabulation method in this we havnt use the recurion which avoid the 
//space stack of the recursion 
//how this works we know the base condition so the intution starts from there what if 
//had a chance to continue from there we know that when the f(0) gives 0 and f(1) gives 
//1 so have a arrray where dp[0]=0,dp[1]=1 now we start a for loop string from 2 -> n
//dp[i]=dp[0]+dp[1] which gonna give the answer for the d[2] like this conitinue 

//code for this tabualtion method

vector<int>dp_arr(n+1,-1);

dp_arr[0]=0;
dp_arr[1]=1;

for(int i=2;i<=n;i++)
{
    dp_arr[i]=dp_arr[i-1]+dp_arr[i-2];
}

//now we go further step to optimize this space complexity even further where we dont 
//need the external vector w.k.t f(0) and f(1) is 0 and 1 so just have two varaible 
//which holding this value prev=1 and prev2=0 we are gonna use the simple logic 
//of the 
/*
    int temp=a;
    a=b;
    b=temp;
*/

//code for this

#include <bits/stdc++.h>
using namespace std;
int main()
{
int prev=1;
int prev2=0;
int curr=0;
for(int i=2;i<=6;i++)
{
    curr=prev+prev2;
    prev2=prev;
    prev=curr;
}

cout<<curr;

}

//here since we doesn't use any of the array the space complexity is O(1)
