#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll dp[1000005];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	memset(dp,0,sizeof dp);
	ll n,x;
	cin>>n>>x;
	vector<ll> coins(n);
	for(int i = 0; i<n; i++){
		cin>>coins[i];
	}
	dp[0] = 0;
	for(int i = 1; i<= x; i++){
		dp[i] = 1e9;
		for(auto c: coins){
			if(i-c <0) continue;
			dp[i] =min(dp[i],1+dp[i-c]);
			
		}
	}
	cout<<(dp[x] == 1e9? -1 : dp[x]);
}
