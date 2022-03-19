#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ll n,m,a,b,c;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	for(int i = 0; i<m; i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	ll dist[n+1][2], inf = 1e16;
	set<pair<ll,pair<ll,ll>>> pq;// dist, node, hasUsedTicket
	
	dist[1][0] = 0;
	dist[1][1] = 0;
	pq.insert({0,{1,0}});
	for(int i = 2; i<=n; i++){
		dist[i][0] = dist[i][1] = inf;
		pq.insert({inf,{i,0}});
		pq.insert({inf,{i,1}});
	}
	
	while(pq.size()){
		auto  top = *pq.begin();
		ll d = top.first, cur = top.second.first, hasUsedTicket = top.second.second;
		pq.erase(pq.begin());
		for(auto [neigh,cost]: adj[cur]){
			//Withouth using a ticket				
			if( dist[neigh][hasUsedTicket] > d + cost){
				auto it  = pq.find({dist[neigh][hasUsedTicket],{neigh,hasUsedTicket}});
				pq.erase(it);
				dist[neigh][hasUsedTicket] = d+cost;
				pq.insert({dist[neigh][hasUsedTicket],{neigh,hasUsedTicket}});
			}
			
			if(!hasUsedTicket){
				if( dist[neigh][1] > d + (cost/2)){
					auto it  = pq.find({dist[neigh][1],{neigh,1}});
					pq.erase(it);
					dist[neigh][1] = d+(cost/2);
					pq.insert({dist[neigh][1],{neigh,1}});
				}				
			}
		}
	}
	/*
	for(int j = 0; j<=1; j++){
		for(int i = 1; i<=n; i++){
			cout<<setw(3)<<dist[i][j];
		}
		cout<<"\n";
	}
	*/
	
	cout<<dist[n][1]<<"\n";
	
	

}
