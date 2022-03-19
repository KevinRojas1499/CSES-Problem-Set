#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ll n,m,u,v,c;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	for(int i = 0; i<m; i++){
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
	}
	ll dist[n+1], inf = 1e16;
	set<pair<ll,ll> > q;
	
	for(int i = 2; i<=n; i++){
		dist[i] = inf;
		q.emplace(dist[i],i);
	}
	
	dist[1] = 0;
	q.insert({0,1});
	while(q.size()){
		auto [d, cur] = *q.begin(); 
		q.erase(q.begin());
		for(auto [neigh,cost] : adj[cur]){
			if(dist[neigh] > d+cost){
				auto it = q.find({dist[neigh],neigh});
				if( it != q.end()) q.erase(it);
				dist[neigh] =  d + cost;
				q.insert({dist[neigh],neigh});
			}
		}
	}
	for(int i = 1; i<=n ;i++){
		cout<<dist[i]<<" ";
	}
}
