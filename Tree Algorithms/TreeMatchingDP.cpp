#include <bits/stdc++.h>
#define ll long long 

using namespace std;

vector<vector<ll>> adj;
const ll mxN = 2e5+5;
ll dp[mxN][2]; //dp[k][0] = max matching that does not include k
               //dp[k][1] = max matching that includes k 

void dfs(ll u, ll p){
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
    }
    for(auto v : adj[u]) {
        if(v == p) continue;
        dp[u][1] = max(dp[u][1], 1+dp[u][0]+dp[v][0] - max(dp[v][0],dp[v][1]));
        // 1 = (u,v), dp[u][0] = biggest matching that didn't include u 
        // dp[v][0] = biggest matching that included v 
        // We need to subtract the amount that the we used to get from v before
    }
}


int main () {
    ll n;
    cin>>n;
    adj.resize(n);
    for(int i = 0; i<n-1; i++){
        ll a ,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    cout<<max(dp[0][0],dp[0][1]);
}