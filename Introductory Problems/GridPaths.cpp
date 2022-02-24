#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
 
    vector<vector<char>>grid;
    vector<vector<int>>dp;
 
    for(int i=0;i<n;i++)
    {
        vector<int>q(n,0);
        vector<char>p(n);
 
        for(auto &x:p)
        cin>>x;
        grid.push_back(p);
        dp.push_back(q);
    }
    if(grid[n-1][n-1]!='*')
    dp[n-1][n-1]=1;
    
    for(int i=n-2;i>=0;i--)
    {
        if(grid[i][n-1]!='*')
        dp[i][n-1]=dp[i+1][n-1];
    }
 
    for(int i=n-2;i>=0;i--)
    {
        if(grid[n-1][i]!='*')
        dp[n-1][i]=dp[n-1][i+1];
    }
 
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            if(grid[i][j]!='*')
            dp[i][j]=(dp[i][j+1]+dp[i+1][j])%mod;
        }
    }
 
    cout<<dp[0][0]<<endl;
}
