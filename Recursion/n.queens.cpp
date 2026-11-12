//in this we are using the while loop to check whether it is safe to place the 
//queen correctly or not but there is a optimal solution for this 
//we do that shortly

#include <bits/stdc++.h>
using namespace std;

bool is_solve(int col,int row,vector<string>& board,vector<vector<string>>& ans,int n)
{
    int ref_col=col;
    int ref_row=row;
    while(col>=0 && row>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
    row=ref_row;
    col=ref_col;

    while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
    row=ref_row;
    col=ref_col;

    while(col>=0 && row<n)
        {
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }

    return true;
}
void solve(int col,int n,vector<string> &board,vector<vector<string>>& ans)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++)
        {
            if(is_solve(col,row,board,ans,n))
            {
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
}
int main()
{
    vector<string>board(4);
    string s(4,'.');
    for(int i=0;i<4;i++)
    {
        board[i]=s;
    }
    vector<vector<string>>ans;

    int n=4;

    solve(0,n,board,ans);

    cout << "Number of solutions: " << ans.size() << "\n\n";

    for (auto solution : ans)
    {
        for (auto row : solution)
            {
                cout << row << "\n";
            }
        cout << "\n";
}
     
}