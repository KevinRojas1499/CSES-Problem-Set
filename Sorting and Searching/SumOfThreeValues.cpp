#include <bits/stdc++.h>
#define ll long long 
using namespace std;

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
	sort(a.begin(),a.end());
	bool found = false;
	for(int i = 0; i<n && !found; i++){
		for(int j = i+1; j<n; j++){
			ll targ = x-a[i].first-a[j].first;
			pair<ll,ll> find = {targ,0};
			auto it = lower_bound(a.begin()+j+1v,a.end(),find);
			if(it!=a.end()){
				if(a[i].first+a[j].first+(*it).first == x){
					found = true;
					cout<<a[i].second<<" "<<a[j].second<<" "<<(*it).second<<"\n";
					break;
				}
			}
		}
	}
	if(!found){
		cout<<"IMPOSSIBLE\n";
	}
		
}
