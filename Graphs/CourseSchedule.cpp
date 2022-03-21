#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> adj;
vector<ll> order;

const ll UNVISITED = 0, VISITED = 1, EXPLORED = 2;

ll status[100005];
bool possible = true;

void dfs(ll cur) {
	if(!possible) return;
	if(status[cur] == VISITED){
		possible = false;
		return;
	}
	if( status[cur] == EXPLORED) return;
	status[cur] = VISITED;
	for(auto v : adj[cur]){
		dfs(v);
	}
	status[cur] = EXPLORED;
	order.push_back(cur);

}


int main() {
	ll n,m,a,b;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i = 0; i<m; i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	memset(status,0,sizeof status);

	for(int i = 1; i<=n; i++){
		if(status[i] == UNVISITED) dfs(i);
	}
	if(possible){
		reverse(order.begin(),order.end());
		for(auto o : order) cout<<o<<" ";
		cout<<"\n";
	}
	else{
		cout<<"IMPOSSIBLE\n";
	}
}
