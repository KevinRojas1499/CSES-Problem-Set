#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> order, rep, sizeOfComp, posOfOrder, out, component, root;
vector<vector<ll>> adj, rev_adj;
vector<bool> seen;
map<pair<ll,ll>,ll> dist;

void dfs1(ll u){
	if(seen[u]) return;
	seen[u] = 1;
	for(auto v : adj[u]){
		dfs1(v);
	}
	order.push_back(u);
}

void dfs2(ll u){
	if(seen[u]) return;
	seen[u] = 1;
	component.push_back(u);
	for(auto v: rev_adj[u]){
		dfs2(v);
	}
}

ll distSameComponent(ll a, ll b){
	ll who = rep[a];
	ll distt = dist[{who,a}]- dist[{who,b}];
	if(distt< 0)
		distt = sizeOfComp[who]+distt;
	return distt;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,q,tt,a,b;
	cin>>n>>q;
	adj.resize(n+1);
	rev_adj.resize(n+1);
	out.resize(n+1);
	posOfOrder.resize(n+1);
	rep.resize(n+1);
	sizeOfComp.resize(n+1);
	root.resize(n+1);
	
	for(int i = 0; i<n; i++){
		cin>>tt;
		adj[i+1].push_back(tt);
		rev_adj[tt].push_back(i+1);
	}
	
	seen.assign(n+1,false);
	for(int i = 1; i<=n ;i++){
		if(!seen[i]) dfs1(i);
	}

	seen.assign(n+1,false);
	reverse(order.begin(),order.end());
	for(auto uu : order){
		cout<<uu<<" ";
	}
	cout<<endl;
	ll root = order[0];

	for(int i = 0; i<n; i++){
		ll u = order[i];
		posOfOrder[u] = i;
		if(!seen[u]) dfs2(u);
		for(int j = 0; j< (ll)component.size(); j++){
			ll v = component[j];
			rep[v] = u;
			sizeOfComp[v] = component.size();
			dist[{u,v}] = j;
		}
		component.clear();
	}
	
	for(int u = 1; u<=n; u++){
		for(auto v : adj[u]){
			if(rep[u] != rep[v]){
				out[rep[u]] = u;
			} 
		}
	}
	for(auto o : out){
		cout<<o<<" ";
	}
	cout<<endl;
	cout<<"COMPONENTS"<<endl;
	queue<ll> qq;
	ll distFromRoot[n+1];
	distFromRoot[root] = 0;
	seen.assign(n+1,false);
	seen[root] = 1;
	qq.push(order[0]);
	while(qq.size()){
		ll top = qq.front();
		qq.pop();
		for(auto v : adj[top]){
			if(seen[v]) continue;
			seen[v] = 1;
			distFromRoot[v] = distFromRoot[top]+1;
			qq.push(v);
		}
	}
	
	
	for(int i = 0; i<q; i++){
		cin>>a>>b;
		if(rep[a] == rep[b]){
			cout<<distSameComponent(a,b)<<'\n';
		}
		else if(posOfOrder[a]< posOfOrder[b]){
			ll toRep = distSameComponent(a,out[rep[a]]);
			ll fromReptoB = distFromRoot[b]-distFromRoot[rep[a]];
			cout<<toRep+fromReptoB<<"\n";
		}
		else{
			cout<<"-1\n";
		}
	}
}