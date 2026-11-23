//this code has the code ninjas problem ninjas traing 
//consisting of
//1)recuriosn
//2)Memoization create a N*4 dp size array 
//3)Tabulation N*4 dp size array with out recursion stack
//4)Space optimization only dp array of size 4


//recurison way
#include <bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>& points)
{
    if(day==0)
    {
        int maxi=0;

        for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    maxi =max(maxi,points[day][task]);
                }
            }
        return maxi;
    }

    int maxi=0;

    for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                int pois=points[day][task]+f(day-1,task,points);
                maxi=max(maxi,pois);
            }
        }

    return maxi;
}
int main()
{
    vector<vector<int>>points={
        {10,40,70},
        {20,50,80},
        {30,60,90}
    };

    cout<<f(points.size()-1,3,points);
}


//next one is memoization in this we are gonna create the n*4 size dp array 
//and my question is why there is n* 4 size array because we know that there are only
//3 task sice it is zero sized indexing there three respective task like 0 1 2 but why are we creating 4 because remeber this when we are checking the n-1 index we are 
//setting the last as 3 in the first call it is becauce we know that in three there is no restiction but we have to pass something in last right for that we are creating the dp of 
//size n*4

#include <bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp)
{
    if(day==0)
    {
        int maxi=0;

        for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    maxi =max(maxi,points[day][task]);
                }
            }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];

    int maxi=0;

    for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                int pois=points[day][task]+f(day-1,task,points,dp);
                maxi=max(maxi,pois);
            }
        }

    return dp[day][last]=maxi;
}
int main()
{
    vector<vector<int>>points={
        {10,40,70},
        {20,50,80},
        {30,60,90}
    };

    vector<vector<int>>dp(3,vector<int>(4,-1));

    cout<<f(points.size()-1,3,points,dp);
}

//next one is tabulation which is nothing but a bottom  up apporaoch 
//we develop up from the base case we know the base case when ever the day reaches 0
//the possibilites are points[0][0] points[0][1] points[0][2] points[0][3] for these 
//we have to return the maximum acroding to the last index 
// and second step is to declare the dp size array that we used in the memoization metheod
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    int n = points.size();

    // DP array of size N x 4
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case for day 0

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0],
                   max(points[0][1], points[0][2]));

    // Calculate values from day 1 to day n-1

    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int activity =
                        points[day][task] +
                        dp[day - 1][task];

                    dp[day][last] =
                        max(dp[day][last], activity);
                }
            }
        }
    }

    cout << dp[n - 1][3];

    return 0;
}


//now we are gonna move into the tabulation method 

//inteed of using the n*4 size dp arrau we are gonna just use the simple 1 D array of size 4 since we know the 


#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    // Base Case
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0],
                  max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);

        for(int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    temp[last] = max(
                        temp[last],
                        points[day][task] + prev[task]
                    );
                }
            }
        }

        prev = temp;
    }

    return prev[3];
}

int main()
{
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    int n = points.size();

    cout << ninjaTraining(n, points);

    return 0;
}