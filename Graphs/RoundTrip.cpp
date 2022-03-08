#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 1e5+5;
vector<vector<ll>> adj;
ll before[mxN],seen[mxN];
bool possible = false;
ll cycleStart = 0;

void dfs(ll cur, ll previous){
	if(possible) return;
	if(!possible && seen[cur]){
		possible = true;
		cycleStart = cur;
		before[cur] = previous;
		vector<ll> cities;
		cities.push_back(cur);
		cur = before[cur];
		while(cur!= cycleStart){
			cities.push_back(cur);
			cur = before[cur];
		}
		cout<<cities.size()+1<<"\n";
		for(int i = 0; i< cities.size(); i++){
			cout<<cities[i]<<" ";
		}
		cout<<cities[0]<<"\n";
		return;
	}
	seen[cur] = 1;
	before[cur] = previous;
	for(auto neigh: adj[cur]){
		if(neigh == previous) continue;
		dfs(neigh,cur);
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
	
	memset(seen,0,sizeof seen);
	memset(before,0,sizeof before);
	
	for(int i = 1; i<=n; i++) {
		if(!possible && !seen[i]) dfs(i,0);
	}
	if(!possible) cout<<"IMPOSSIBLE\n";
}
