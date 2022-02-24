#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll target;
ll MOD = 1e9+7;
ll dp[1000005];
ll mod(ll a){
	return (a%MOD+MOD)%MOD;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	memset(dp,0,sizeof dp);
	dp[0] = dp[1] = 1;
	cin>>target;
	for(int i = 2; i<=target; i++){
		for(int j = 1; j<=6; j++){
			if(i-j<0) continue;
			dp[i]+=dp[i-j];
			dp[i] = mod(dp[i]);
		}
	}
	cout<<dp[target];
	
}
