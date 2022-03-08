#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 1e5+5;
vector<vector<ll>> adj;
ll col[mxN],seen[mxN];
bool possible = true;

void dfs(ll cur, ll color){
	if(seen[cur] && col[cur] == color){
		return;
	}
	if(seen[cur] && col[cur] != color){
		possible = false;
		return;
	}
	seen[cur] = 1;
	col[cur]  = color;
	ll nextColor = (color == 1? 2: 1);		
	for(auto neigh: adj[cur]){
		dfs(neigh,nextColor);
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
	memset(col,0,sizeof col);
	for(int i = 1; i<=n; i++){
		if(!seen[i]) dfs(i,1);
	}
	if(possible){
		for(int i = 1; i<=n; i++){
			cout<<col[i]<<" ";
		}
		cout<<"\n";
	}
	else{
		cout<<"IMPOSSIBLE\n";
	}
}
