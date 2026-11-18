//this is similar to the fibonacci 
//at each step we can take 1 step or two step untill we reach the nth step 

#include <bits/stdc++.h>
using namespace std;

int walk_the_stairs(int n,vector<int>& mom)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (mom[n]!=-1) return mom[n];

    return mom[n]=walk_the_stairs(n - 1,mom) +
           walk_the_stairs(n - 2,mom);
}

int main()
{
    int n;
    cin >> n;
    vector<int>mom(n+1,-1);

    cout << walk_the_stairs(n,mom);

    return 0;
}
