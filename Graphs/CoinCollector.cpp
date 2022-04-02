#include <bits/stdc++.h>
#define ll long long


using namespace std;

vector<vector<ll>> adj, rev_adj, adj_scc;
vector<ll> coins, order, component, rep, maxCoins;
vector<bool> seen;
void dfs1(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    for(auto v : adj[u])
        dfs1(v);
    order.push_back(u);
}

void dfs2(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    component.push_back(u);
    for(auto v : rev_adj[u])
        dfs2(v);
}

void dfs3(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    for(auto v : adj_scc[u]){
        dfs3(v);
    }
    order.push_back(u);
    
}

void dfs4(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    ll res =  maxCoins[u];
    for(auto v : adj_scc[u]){
        dfs4(v);
        res = max(res, maxCoins[u]+ maxCoins[v]);
    }
    maxCoins[u] = res;

}

int main(){
    ll n,m,a,b;
    cin>>n>>m;
    adj.resize(n+1);
    rev_adj.resize(n+1);
    adj_scc.resize(n+1);
    coins.resize(n+1);
    seen.assign(n+1,false);
    maxCoins.resize(n+1);
    rep.resize(n+1);
    for(int i = 0; i<n; i++){
        cin>>coins[i+1];
    }
    for(int i = 0; i<m; i++){
        cin>>a>>b; 
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        if(!seen[i]) dfs1(i);
    }
    seen.assign(n+1,false);
    reverse(order.begin(),order.end());

    for(auto u : order){
        if(!seen[u]){
            dfs2(u);
            ll count = 0;
            for(auto v : component){
                rep[v] = u;
                count+= coins[v];
            }   
            maxCoins[u] = count;
            component.clear();
        }
    }

    for(int i= 1; i<=n ;i++){
        for(auto v : adj[i]){
            if(rep[i] != rep[v]){
                adj_scc[rep[i]].push_back(rep[v]);
            }
        }
    }

    seen.assign(n+1,false);
    order.clear();
    for(int i = 1; i<=n; i++){
        ll u = rep[i];
        if(!seen[u]){
            dfs3(u);
        }
    }
    ll res = -1;
    reverse(order.begin(),order.end());
    seen.assign(n+1,false);

    for(int i = 0; i < (ll) order.size(); i++){
       ll u = order[i];
       if(!seen[u]) {
           dfs4(u);
       }
       res = max(maxCoins[u],res);
    }


    cout<<res<<"\n";

    
}