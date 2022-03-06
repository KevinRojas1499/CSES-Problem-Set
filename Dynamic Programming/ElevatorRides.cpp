#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> w(n);
	for(int i = 0; i<n; i++) cin>>w[i];
	//Refer to the handbook for explanation of this problem
	pair<ll,ll> dp[(1<<n)+5]; //This will hold (#ofRidesToFinishSubsetS,WeightOflastSubsetOfS)
	
	dp[0] = {1,0};
	
	for(int s  = 1; s< (1<<n); s++){
		dp[s] = {n+1,0};//Initialize with infinity
		for(int p = 0; p<n; p++){
			if((1<<p)&s){
				//If p is In S
				if(dp[s^(1<<p)].second + w[p] <= x){
					dp[s] = min(dp[s],{dp[s^(1<<p)].first,dp[s^(1<<p)].second+w[p]});
				}
				else{
					dp[s] = min(dp[s],{dp[s^(1<<p)].first+1,w[p]});
				}
			}
		}
	}
	cout<<dp[(1<<n)-1].first<<"\n";
	
	
}
