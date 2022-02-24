#include <bits/stdc++.h>
#define ll long long 
using namespace std;

 
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> k(n);
	vector<pair<ll,ll>> a(n);
	for(int i= 0; i<n;i++){
		cin>>k[i];
		a[i] = {k[i],i};
	}
	ll start = 0;
	ll best = 0;
	ll cur = 0;
	set<pair<ll,ll>> uniques;
	for(int i = 0; i<n; i++){
		auto it = uniques.lower_bound({a[i].first,0});

		if(it == uniques.end() || (*it).first != a[i].first){
			uniques.insert(a[i]);
			cur++;
		}
		else{
			ll end = (*it).second;
			for(auto j = start; j<n && j<=end; j++){
				uniques.erase(a[j]);
			}
			
			uniques.insert(a[i]);
			start = end+1;
			cur = uniques.size();
		}
		best = max(cur,best);
	}
	cout<<best<<"\n";
				
}
