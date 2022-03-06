#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 1e5+5;
ll seen[mxN];
vector<vector<ll>> adj;

void dfs(ll cur){
	if(seen[cur]) return;
	seen[cur] = 1;
	for(auto neigh: adj[cur]){
		dfs(neigh);
	}
}

int main(){
	ll n,m,u,v;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i = 0; i<m; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll> components;
	memset(seen,0,sizeof seen);
	for(int i = 1; i<=n; i++){
		if(!seen[i]){
			dfs(i);
			components.push_back(i);
		}
	}
	ll k = components.size();
	cout<<k-1<<"\n";
	for(int i = 1; i<k; i++){
		cout<<components[0]<<" "<<components[i]<<"\n";
	}
			
}
