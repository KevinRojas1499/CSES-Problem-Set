#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll mxN = 2e5+5;
vector<vector<ll>> neigh(mxN);
vector<ll> dp(mxN), seen(mxN);

void dfs(ll cur, ll p){
    if(seen[cur]) return;
    seen[cur] = 1;
    for(auto v : neigh[cur]){
        if(v == p) continue;
        dfs(v,cur);
        dp[cur]+= 1+dp[v];
    }
}


int main () {
    ll n;
    cin>>n;
    for(int i = 2; i<=n; i++){
        ll a;
        cin>>a;
        neigh[a].push_back(i);
    }
    dfs(1,-1);
    for(int i = 0; i<n; i++){
        cout<<dp[i+1]<<"\n";
    }
}