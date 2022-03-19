#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,a,b,c;
ll inf = 1e16;

int main() {
	
	cin>>n>>m;
	vector<tuple<ll,ll,ll>> edges(m);
	for(int i = 0; i<m; i++){
		cin>>a>>b>>c;
		edges[i] = {a,b,c};
	}
	ll dist[n+1], parent[n+1];
	dist[1] = 0, parent[1] = 0;
	
	for(int i = 2; i<=n ;i++) dist[i] = inf, parent[i] = -1;
	ll x = -1;
	for(int i = 1; i<=n; i++){
		x = -1;
		for(auto [u,v,d]: edges){
			if(dist[v] > dist[u]+d){
				dist[v] = dist[u]+d;
				parent[v] = u;
				x = v;
			}
		}
	}
	if ( x != -1){
		ll cur = x, y;
		for(int i = 0; i<n; i++){
			cur = parent[cur];
		}
		y = cur;
		cout<<"YES\n";
		vector<ll> res;
		do {
			res.push_back(cur);
			cur = parent[cur];
		} while( cur != y);
		for(int i = res.size()-1; i>=0; i--){
			cout<<res[i]<<" ";
		}
		cout<<res[res.size()-1]<<"\n";
	}
	else{
		cout<<"NO\n";
	}
}
