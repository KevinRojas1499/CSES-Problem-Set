#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	ll n,m,k,a,b,c;
	ll inf = 1e16;
	cin>>n>>m>>k;
	vector<vector<pair<ll,ll>>> adj(n+1);
	for(int i = 0; i<m; i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	
	vector<priority_queue<ll>> dist(n+1);
	multiset<pair<ll,ll>> pq;
	vector<ll> count(n+1);
	for(int i = 2; i<=n ;i++){
		pq.insert({inf,i});
		dist[i].push(inf);
	}
	dist[1].push(0);
	pq.insert({0,1});
	while(pq.size()){
		auto [d,u] = *pq.begin();
		pq.erase(pq.begin());
		if(d > dist[u].top()) continue; // Very important to avoid inserting more unnecessary distances
		for(auto& [v,cost] : adj[u]){
			ll maxD = dist[v].top();
			if(dist[v].size() < k){
				dist[v].push(d+cost);
				pq.insert({d+cost,v});
			}
			else if(d+cost< maxD){
				dist[v].pop();
				dist[v].push(d+cost);
				pq.insert({d+cost,v});
			}
		}
	}
	vector<ll> res;
	while(dist[n].size()){
		res.push_back(dist[n].top());
		dist[n].pop();
	}
	for(int i = res.size()-1; i>=0; i--){
		cout<<res[i]<<" ";
	}
	cout<<"\n";
	
}
