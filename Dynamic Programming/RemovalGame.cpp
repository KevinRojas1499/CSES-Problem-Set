#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 5000;
vector<ll> x;
ll dp[mxN+5][mxN+5];

ll solve(ll a, ll b, ll cur){
	if(a == b) return dp[a][b] = (cur == 1? x[a] : 0);
	if(dp[a][b]) return dp[a][b];
	if(cur == 1){
		 return dp[a][b] = max(solve(a+1,b,2)+x[a],solve(a,b-1,2)+x[b]);
	}
	else if(cur == 2){
		 return dp[a][b] = min(solve(a+1,b,1),solve(a,b-1,1));
	}
	return 0;
}

int main(){
	ll n;
	cin>>n;
	x.resize(n);
	for(int i = 0; i<n; i++) cin>>x[i];
	memset(dp,0, sizeof dp);

	cout<<solve(0,n-1,1)<<endl;
}

