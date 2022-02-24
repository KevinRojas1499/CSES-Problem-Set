#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<ll> b;
vector< pair< ll, pair<ll,ll> > > indexes;

bool find(ll x, ll i, ll j){
	auto it = lower_bound(b.begin(),b.end(),x);
	
	for(; it<b.end() && *it == x; it++){
		ll id = it-b.begin();
		ll idx1 = indexes[id].second.first;
		ll idx2 = indexes[id].second.second;
		if(idx1 == i || idx1 == j  || idx2 == i || idx2 == j){
			 continue;
		 }else{
			 cout<<i<<" "<<j<<" "<<idx1<<" "<<idx2<<"\n";
			 return true;
		 }
	 }
	 return false;
	
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n,x;
	cin>>n>>x;
	vector<pair<ll,ll>> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i].first;
		a[i].second = i+1;
	}
	
	bool found = false;
	for(int i = 0; i<n && !found; i++){
		for(int j = i+1; j<n; j++){
			ll sum = a[i].first+a[j].first;
			b.push_back(sum);
			indexes.push_back({sum,{a[i].second,a[j].second}});
		}
	}
	sort(b.begin(),b.end());
	sort(indexes.begin(),indexes.end());
	
	for(unsigned int i = 0; i<b.size(); i++){
		ll idx1 = indexes[i].second.first;
		ll idx2 = indexes[i].second.second;
		if(find(x-b[i], idx1, idx2)){
			found = true;
			break;
		}
	}
		
	if(!found){
		cout<<"IMPOSSIBLE\n";
	}
		
}
