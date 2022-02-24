#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n,x;
	cin>>n>>x;
	vector<ll> a(n), sums(n+1);
	map<ll,ll> count;
	count[0]++;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		sums[i+1] = a[i]+sums[i];
		count[sums[i+1]]++;
	}
	ll res = 0;
	map<ll,ll> curCount;
	for(int i = 0; i<=n; i++){
		curCount[sums[i]]++;
		res+= count[x+sums[i]]-curCount[x+sums[i]];
	}
	cout<<res<<"\n";
}
