#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,a,b;
	cin>>n;
	vector<pair<ll,ll>> times;
	for(int i= 0; i<n; i++){
		cin>>a>>b;
		times.push_back({a,0});
		times.push_back({b,1});
	}
	ll best = 0, cur  = 0;
	sort(times.begin(),times.end());
	for(int i = 0; i<2*n; i++){
		ll entrance = times[i].second;
		best = max(best,cur);
		if(!entrance){
			cur++;
		}
		else{
			cur--;
		}
		best = max(best,cur);
	}
	cout<<best<<"\n";
}
