#include <bits/stdc++.h>
#define ll long long 
using namespace std;

 
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	vector<ll> p(n);
	vector<pair<ll,ll>> q;
	q.push_back({0,0});
	q.resize(n+1);
	for(int i= 0; i<n; i++){
		cin>>p[i];
		q[i] = {p[i],i+1};
	}
	sort(q.begin(),q.end());
	
	ll res = 1;
	for(int i = 1; i<=n; i++){
		if(q[i].second<=q[i-1].second) res++;
	}
	q.push_back({n+1,n+1});
	ll a,b,c,d;
	for(int i = 0; i<m; i++){
		cin>>a>>b;
		a--;b--;
		c = p[a];
		d = p[b];
		if(c>d) swap(c,d);
		ll originalCost = 1;
		ll e = q[c-1].second, f = q[c].second, g = q[c+1].second; 
		ll u = q[d-1].second, v = q[d].second, w = q[d+1].second;
	
		if(c+1 == d){
			//Intersection
			if(e>f) originalCost++;
			if(f>v) originalCost++;
			if(v>w) originalCost++;
		}
		else if(c+1 == d-1){
			if(e>f) originalCost++;
			if(f>g) originalCost++;
			if(u>v) originalCost++;
			if(v>w) originalCost++;			
		}	
		else{
			if(e>f) originalCost++;
			if(f>g) originalCost++;
			if(g>u) originalCost++;
			if(u>v) originalCost++;
			if(v>w) originalCost++;			
		}
		
		
		ll afterCost = 1;
		e = q[c-1].second, f = q[d].second, g = q[c+1].second; 
		u = q[d-1].second, v = q[c].second, w = q[d+1].second;
	
		if(c+1 == d){
			//Intersection
			if(e>f) afterCost++;
			if(f>v) afterCost++;
			if(v>w) afterCost++;
		}
		else if(c+1 == d-1){
			if(e>f) afterCost++;
			if(f>g) afterCost++;
			if(u>v) afterCost++;
			if(v>w) afterCost++;			
		}	
		else{
			if(e>f) afterCost++;
			if(f>g) afterCost++;
			if(g>u) afterCost++;
			if(u>v) afterCost++;
			if(v>w) afterCost++;			
		}
		swap(q[c].second , q[d].second);
		swap(p[a],p[b]);
		res+= (afterCost-originalCost);
		cout<<res<<"\n";
	}
			
}
