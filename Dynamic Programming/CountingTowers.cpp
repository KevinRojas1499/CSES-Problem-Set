#include <bits/stdc++.h>
#define ll long long 
 
using namespace std;
 
const ll MOD = 1e9+7, mxN = 1e6;
 
int main(){
	ll t,n;
	ll f[mxN+5][2];
	f[1][0] = 1;
	f[1][1] = 1;
	for(int i  = 2; i<=mxN; i++){
		f[i][0] = ((2*f[i-1][0])%MOD+f[i-1][1])%MOD;
		f[i][1] = (f[i-1][0]+(4*f[i-1][1])%MOD)%MOD;
	}
	
	cin>>t;
	while(t--){
		cin>>n;
		ll res = (f[n][0]+f[n][1])%MOD;
		res= (res+MOD)%MOD;
		cout<<res<<"\n";
	}
}
