#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,a,b;
	cin>>n;
	vector<pair<ll,ll>> timess;
	vector<pair<ll,ll>> times;
	for(int i= 0; i<n; i++){
		cin>>a>>b;
		timess.push_back({a,b});
		times.push_back({b,i});
	}
	sort(times.begin(),times.end());
	ll res = 0;
	ll lastTime = 0;
	for(int i = 0; i<n; i++){
		ll id = times[i].second;
		ll start = timess[id].first;
		if(start>=lastTime){
			res++;
			lastTime = times[i].first;
		}
	}
	cout<<res<<"\n";
}
