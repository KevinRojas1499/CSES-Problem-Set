#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll MOD = 1e9+7, mxN = 1e6;

int main(){
	ll t,n;
	ll dp[mxN+5], accum[mxN+5];
	cin>>t;
	accum[0] = 0;
	dp[1] = 2;
	accum[1] = 2;
	for(int i = 2; i<mxN+2; i++){
		dp[i] = 2*accum[i-1];
		accum[i] = accum[i-1]+dp[i];
	}
	while(t--){
		cin>>n;
		cout<<accum[n]<<"\n";
	}
}



