#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll MOD = 1e9+7;

bool good(ll a, ll b){
	if(b == 0) return true;
	return abs(a-b)<=1;
}

int main(){
	ll n, m;
	cin>>n>>m;
	vector<ll> x(n+3);
	
	ll dp[n+5][m+5];
	for(int i = 1; i<=n; i++) cin>> x[i];
	
	memset(dp,0,sizeof dp);
	
	if(x[1] == 0){
		for(int i = 1; i<=m; i++) dp[1][i] = 1;
	}
	else{
		dp[1][x[1]] = 1;
	}

	
	for(int i = 1; i<=n; i++){
		if(x[i] == 0){
			for(int k = 1; k<=m; k++){
				dp[i][k] += dp[i-1][k];
				dp[i][k]%=MOD;
				if(k>0)	dp[i][k] += dp[i-1][k-1];
				dp[i][k]%=MOD;
				dp[i][k] += dp[i-1][k+1];
				dp[i][k]%=MOD;
			}
		}
		else{
			for(int k = x[i]-1; k<=x[i]+1; k++){
				dp[i][x[i]]+= dp[i-1][k];
			}
		}
	}
	

	ll res = dp[n][x[n]];
	if(x[n] == 0){
		res = 0;
		for(int i = 0; i<=m; i++){
			res+=dp[n][i];
		}
	}
	cout<<(res%MOD+MOD)%MOD<<"\n";
}



