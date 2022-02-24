#include <bits/stdc++.h>
#define ll long long 
using namespace std;

  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,x,b;
	cin>>n>>x;
	vector<pair<ll,ll>> a(n);
	for(int i= 0; i<n; i++){
		cin>>b;
		a[i] = {b,i+1};
	}
	sort(a.begin(),a.end());
	bool found = 0;
	for(int i = 0; i<n; i++){
		pair<ll,ll> search = {x-a[i].first,0};		
		int idx = (lower_bound(a.begin()+i+1,a.end(),search)-a.begin());
		if(idx<n && a[i].first+a[idx].first == x && i!=idx){
			cout<<a[i].second<<" "<<a[idx].second<<"\n";
			found = 1;
			break;
		}
		
	}
	if(!found) cout<<"IMPOSSIBLE\n";
	
}
