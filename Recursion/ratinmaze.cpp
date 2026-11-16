#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, int n,
           vector<vector<int>>& maze,
           vector<string>& ans,
           vector<int>& row_i,
           vector<int>& col_j,
           string str,
           vector<vector<int>>& vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(str);
        return;
    }

    string order = "DLRU";

    for (int k = 0; k < 4; k++)
    {
        int ni = i + row_i[k];
        int nj = j + col_j[k];

        if (ni >= 0 && nj >= 0 &&
            ni < n && nj < n &&
            !vis[ni][nj] &&
            maze[ni][nj] == 1)
        {
            vis[ni][nj] = 1;

            solve(ni, nj, n, maze, ans,
                  row_i, col_j,
                  str + order[k], vis);

            vis[ni][nj] = 0; // backtrack
        }
    }
}

int main()
{
    vector<vector<int>> maze =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();

    vector<vector<int>> vis(n, vector<int>(n, 0));

    vector<int> row_i = {1, 0, 0, -1}; // D L R U
    vector<int> col_j = {0, -1, 1, 0};

    vector<string> ans;

    if (maze[0][0] == 1)
    {
        vis[0][0] = 1;
        solve(0, 0, n, maze, ans,
              row_i, col_j, "", vis);
    }

    for (string path : ans)
    {
        cout << path << endl;
    }

    return 0;
}