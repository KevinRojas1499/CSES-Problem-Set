#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,q,tt,a,b;
	cin>>n>>q;
	vector<ll> t(n+1);
	for(int i = 0; i<n; i++){
		cin>>tt;
		t[i+1] = tt;
	}
	ll dp[n+2][32]; // Sparse table
	
	for(int i = 0; i<31; i++){
		for(int j = 1; j<=n; j++){
			if(i == 0) {
				dp[j][i] = t[j];
			}
			else{
				ll before = dp[j][i-1];
				dp[j][i] = dp[before][i-1];
			}
		}
	}
	for(int i = 0; i<q; i++){
		cin>>a>>b;
		ll cur  = a;
		ll pow2 = log2(b);
		while(b){
			pow2 = log2(b);
			cur = dp[cur][pow2];
			b-= (1<<pow2);
		}
		cout<<cur<<"\n";
	}
		
	
}
