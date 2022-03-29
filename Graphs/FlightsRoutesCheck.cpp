#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> adj, rev_adj;
vector<ll> component, order;
vector<bool> seen;

void dfs1(ll u){
    if(seen[u]) return;
    seen[u] =1;
    for(auto v : adj[u]){
        dfs1(v);
    }
    order.push_back(u);
}
void dfs2(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    component.push_back(u);
    for(auto v: rev_adj[u]){ 
        dfs2(v);
    }
}

int main(){
    ll n,m,a,b;
    cin>>n>>m;
    rev_adj.resize(n+1);
    adj.resize(n+1);
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    seen.assign(n+1,false);
    for(int i = 1; i<=n ;i++){
        if(!seen[i]) dfs1(i);
    }
    seen.assign(n+1,false);
    reverse(order.begin(),order.end());
    dfs2(order[0]);
    if(component.size() == n){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
        sort(component.begin(),component.end());
        for(int i = 1; i<=n ; i++){
            if(component[i-1] != i){
                cout<<i<<" "<<order[0]<<"\n";
                break;
            }
        }
    }
        
}