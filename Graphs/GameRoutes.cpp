#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> adj;
vector<ll> order;
const ll UNVISITED = 0, VISITED = 1, EXPLORED = 2;
const ll mxN = 100005, MOD = 1e9+7;
ll parent[mxN], num [mxN], status[mxN];
ll n,m,a,b;
bool possible = false;

void dfs(ll cur) {
	if(cur == n) possible = true;
	if( status[cur] == EXPLORED) return;
	status[cur] = VISITED;
	for(auto v : adj[cur]){
		dfs(v);
	}
	status[cur] = EXPLORED;
	order.push_back(cur);
}

void update(ll cur){
	for(auto v : adj[cur]){
		num[v]+= num[cur];
		num[v]%=MOD;
	}
}

int main() {
	cin>>n>>m;
	adj.resize(n+1);
	for(int i = 0; i<m; i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	memset(status,UNVISITED,sizeof status);
	memset(num, 0, sizeof num);
	dfs(1);
	num[1] = 1;
	if(possible){
		reverse(order.begin(),order.end());
		for(auto o : order) {
			update(o);
		}
		cout<<(num[n]+MOD)%MOD<<"\n";
	}
	else{
		cout<<"0\n";
	}
}
