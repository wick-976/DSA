//in this problem there will be n*m matrix where we need to return theh unique path 
// to reach from m[0][0] to m[n-1][m-1] but there are obstacles which is placed in the 
//one of the cell marked as -1 if we found -1 mean we cant use that path 
//and we have return the answer in %1e9+7

//for that we use recursion->memoization->tabulation->sapce optimization

//here we have the code to the space optimization

#include <bits/stdc++.h>
using namespace std;



int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<long long>prev(m,0);
    const int MOD = 1e9 + 7;

    vector<long long>curr(m,0);
    
    for(long long i =0;i<n;i++)
    {
        for(long long j=0;j<m;j++)
        {
            if(mat[i][j]==-1) curr[j]=0;

            else if(i==0 && j==0) curr[j]=1;

            else{
                long long up=0;
                long long left=0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];

                curr[j]=(up+left)%MOD;
            }
        }
        prev=curr;
    }

    return prev[m-1];
}