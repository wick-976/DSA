class Solution {
public:
    bool ispalindrome(int start,int end,vector<vector<string>>& ans,vector<string>& ds,string s)
    {
    while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
    return true;
    }

    void sub(int idx,int size,vector<vector<string>> &ans,vector<string>& ds,string s)
   {
    if(idx==size)
    {
        ans.push_back(ds);
        return;
    }

    for(int i=idx;i<size;i++)
        {
            if(ispalindrome(idx,i,ans,ds,s))
            {
                ds.push_back(s.substr(idx,i-idx+1));
                sub(i+1,size,ans,ds,s);
                ds.pop_back();
            }
        }
    }   
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        sub(0,s.size(),ans,ds,s);
        return ans;
    }
};