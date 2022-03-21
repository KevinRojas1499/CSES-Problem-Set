#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll mxN = 1e5+5;
const ll UNVISITED = 0, VISITED = 1, EXPLORED = 2;
//Explored means we've visited all of it's subtree
ll parent[mxN], status[mxN];
ll cycle = false;
vector<ll> res;
vector<vector<ll>> adj;
ll t = 0;
void dfs(ll cur, ll before){
	if(cycle) return;
	if(status[cur] == VISITED){
		res.push_back(cur);
		for(ll x = before; ; x = parent[x]){
			res.push_back(x);
			if(res.size()>0 && x == cur){
				break;
			}
		}
		cycle = true;
		return;
	}
	if(status[cur] != UNVISITED) return;
	status[cur] = VISITED;
	for(auto v : adj[cur]){
		if(v == cur) continue;
		parent[v] = cur;
		dfs(v,cur);
	}
	status[cur] = EXPLORED;
}

int main(){
	ll n,m,a,b;
	cin>>n>>m;
	adj.resize(n+1);
	memset(status,0,sizeof status);

	for(int i = 0; i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	for(int i = 1; i<=n; i++){
		if(!cycle && status[i] == UNVISITED){
			dfs(i,-1);
		}
	}
	if(!cycle){
		cout<<"IMPOSSIBLE\n";
	}
	else{
		reverse(res.begin(),res.end());
		cout<<res.size()<<"\n";
		for(auto c : res) cout<<c<<" ";
	}
	
}
