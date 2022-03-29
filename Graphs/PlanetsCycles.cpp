#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> order, component, distToCycle;
vector<vector<ll>> adj, rev_adj;
vector<bool> seen;

void dfs1(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    for(auto v : adj[u]){
        dfs1(v);
    }
    order.push_back(u);
}

void dfs2(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    component.push_back(u);
    for(auto v : rev_adj[u]){
        dfs2(v);
    }
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,tt,inf = 1e9;
	cin>>n;
	adj.resize(n+1);
	rev_adj.resize(n+1);
    distToCycle.assign(n+1,inf);
	
	for(int i = 0; i<n; i++){
		cin>>tt;
        if(i+1 == tt) distToCycle[i+1] = 1;
		adj[i+1].push_back(tt);
		rev_adj[tt].push_back(i+1);
	}
    seen.assign(n+1,false);

    for(int i = 1; i<=n; i++){
        if(!seen[i]) dfs1(i);
    }

    reverse(order.begin(),order.end());
    seen.assign(n+1,false);

    set<pair<ll,ll> > pq;
    for(int i = 0; i<n; i++){
        ll u = order[i];
        if(seen[u]) continue;
        dfs2(u);
        if(component.size()>1){
            for(auto v : component){
                seen[v] = 1;
                distToCycle[v] = component.size();
                pq.emplace(distToCycle[v], v);
            }
        }
        else{
            pq.emplace(distToCycle[u],u);
        }
        component.clear();
    }
    seen.assign(n+1,false);

    while(pq.size()){
        auto [d,u] = *pq.begin();
        pq.erase(pq.begin());
        for(auto v : rev_adj[u]){
            if(distToCycle[v] > d+1){
                pq.erase(pq.find({distToCycle[v],v}));
                distToCycle[v] = d+1;
                pq.emplace(distToCycle[v],v);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout<<distToCycle[i]<<" ";
    }
    cout<<"\n";


}