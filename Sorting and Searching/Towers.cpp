#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> p(n);
	for(int i = 0; i<n; i++) cin>>p[i];
	
	ll res = 0;
	multiset<ll> towers;
	for(int i = 0; i<n; i++){
		auto it = towers.upper_bound(p[i]);
		if(it == towers.end()) res++;
		else towers.erase(it);
		towers.insert(p[i]);
	}
	cout<<res<<"\n";	
}
