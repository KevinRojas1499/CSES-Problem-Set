#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll mod(ll x, ll n){
	return (x%n+n)%n;
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	vector<ll> a(n), sums(n+1);
	map<ll,ll> count;
	count[0]++;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		a[i] = mod(a[i],n);
		sums[i+1] = a[i]+sums[i];
		sums[i+1] = mod(sums[i+1],n);
		count[sums[i+1]]++;
	}
	ll res = 0;
	map<ll,ll> curCount;
	for(int i = 0; i<=n; i++){
		curCount[sums[i]]++;
		res+= count[sums[i]]-curCount[sums[i]];
	}
	cout<<res<<"\n";
}
