#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	ll n,m,u,v;
	cin>>n>>m;
	vector<vector<ll>> adj(n+1);
	for(int  i = 0; i<m; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<ll> q;
	ll seen[n+1],depth[n+1], before[n+1];
	memset(depth,0,sizeof depth);
	memset(seen,0,sizeof seen);
	before[1] = 0, depth[0] = 0, seen[1] = 1;
	q.push(1);
	while(q.size()){
		ll t = q.front(); q.pop();
		for(auto neigh: adj[t]){
			if(!seen[neigh]){
				seen[neigh] = 1;
				depth[neigh] = depth[t]+1;
				before[neigh] = t;
				q.push(neigh);
			}
		}
	}
	
	if(depth[n]){
		cout<<depth[n]+1<<"\n";
		ll cur = n;
		vector<ll> res;
		while(cur != 0){
			res.push_back(cur);
			cur = before[cur];
		}
		reverse(res.begin(),res.end());
		for(auto a: res){
			cout<<a<<" ";
		}
		cout<<'\n';
	}
	else{
		cout<<"IMPOSSIBLE\n";
	}
}
