#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	vector<pair<ll,ll>> times(n);
	
	for(int i = 0; i<n; i++){
		cin>>times[i].first>>times[i].second;
	}
	
	sort(times.begin(),times.end());
	
	ll t = 0,res = 0;
	for(int i = 0; i<n; i++){
		t+=times[i].first;
		res+= times[i].second-t;
	}
	cout<<res<<"\n";
}
