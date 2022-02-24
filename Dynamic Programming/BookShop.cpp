#include <bits/stdc++.h>
#define ll long long 

using namespace std;



int main(){
	ll n, x;
	cin>>n>>x;
	vector<ll> h(n),s(n);
	for(int i = 0; i<n;i++){
		cin>>h[i];
	}
	for(int i = 0; i<n;i++){
		cin>>s[i];
	}
	vector<ll> dp(x+1);
	for(int i = 0; i< n; i++){
		for(int j = x; j>= h[i]; j--){
			dp[j] = max(dp[j], s[i]+dp[j-h[i]]);
		}
	}
	cout<<dp[x]<<'\n';
}



