#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n;
	cin>>n;
	vector<tuple<ll,ll,ll>> proj(n);
	set<ll> startingTimes;
	map<ll,ll> idxToTime, timeToIndex;
	for(int i = 0; i<n; i++){
		cin>>get<0>(proj[i])>>get<1>(proj[i]) >>get<2>(proj[i]);
		startingTimes.insert(get<0>(proj[i]));
	}	
	sort(proj.begin(),proj.end());
	for(int i = 0; i<n ;i++){
		ll start = get<0>(proj[i]);
		if(!timeToIndex[start])
			timeToIndex[start] = i;
	}	
	ll dp[n+5];
	memset(dp, 0, sizeof dp);
	for(int i = n-1; i>= 0; i--){
		ll end = get<1>(proj[i]), mon = get<2>(proj[i]);
		auto next = startingTimes.upper_bound(end);
		ll nextIdx = n;
		if(next != startingTimes.end()){
			 nextIdx = timeToIndex[*next];
		 }
		dp[i] = max(dp[i],dp[nextIdx]+mon);
		dp[i] = max(dp[i],dp[i+1]);
		
	}
	cout<<dp[0]<<"\n";	
	
}
