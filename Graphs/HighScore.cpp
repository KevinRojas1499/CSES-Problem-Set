#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool seen[3000];

vector<vector<ll>> adjj;
void dfs(ll cur, vector<ll> &connected){
	if(seen[cur]) return;
	seen[cur] = 1;
	connected[cur] = 1;
	for(auto neigh: adjj[cur]){
		dfs(neigh, connected);
	}
}

int main() {
	ll n,m,a,b,x,inf = 1e16;;
	cin>>n>>m;
	vector<tuple<ll,ll,ll>> adj;
	vector<ll> dist(n+1, inf);
	vector<ll> connectedWithTheLastOne(n+1), connectedWithTheFirstOne(n+1);
	adjj.resize(n+1);
	memset(seen,0,sizeof seen);
	for(int i = 0; i<m; i++){
		cin>>a>>b>>x;
		adjj[a].push_back(b);
		adj.push_back({a,b,-x});
		if(b == n) connectedWithTheLastOne[a] = 1;
	}
	dist[1] = 0;
	dfs(1,connectedWithTheFirstOne);
	bool improved = false;
	for(int i = 1; i<n; i++){
		for(auto [v, u, c] : adj){
			if(!connectedWithTheFirstOne[v]) continue;
			if(connectedWithTheLastOne[u]) connectedWithTheLastOne[v] = 1;
			
			if( dist[u] > dist[v]+c){
				dist[u] = dist[v]+c;
				improved = true;
			}
		}
		if(!improved) break;
		improved = false;
	}
	
	bool hasNegativeCycleThatN = false;
	for(auto [v,u,c] : adj){
		if(dist[u] > dist[v]+c){
			if(!connectedWithTheFirstOne[u]) continue;
			if(connectedWithTheLastOne[u]) hasNegativeCycleThatN = true;
		}
	}
	if(hasNegativeCycleThatN) cout<<"-1\n";
	else{
		cout<<-dist[n]<<"\n";
	}

}
