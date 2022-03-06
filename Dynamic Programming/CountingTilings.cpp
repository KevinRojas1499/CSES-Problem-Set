#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;
ll n,m;
bool match(ll s,ll w){
	//checks if w could go after s
	for(int i = 0; i<n; i++){
		ll curBit = (1<<i);
		if(curBit&s){
			if(curBit&w) return false;
		}
		else{
			if(!(curBit&w)){
				if((1<<(i+1))&w || (1<<(i+1))&s || i == n-1){
					return false;
				}
				else{
					i++;
				}
			}
		}
	}
	return true;
}
int main(){
	cin>>n>>m;
	ll dp[m][(1<<n)];
	memset(dp,0,sizeof dp);
	bool matching[(1<<n)][(1<<n)];
	for(int i = 0; i<(1<<n); i++){
		for(int j = 0; j<(1<<n); j++){
			matching[i][j] = match(i,j);
		}
	}
	for(int j = 0; j<(1<<n); j++) dp[0][j] = matching[0][j]?1:0;
	
	for(int i = 1; i<m; i++){
		for(int j = 0; j<(1<<n); j++){
			for(int k = 0; k<(1<<n); k++){
				if(matching[j][k]){
					dp[i][k]+=dp[i-1][j];
					dp[i][k]%=MOD;
				}
			}
		}
	}
	cout<<(dp[m-1][0]+MOD)%MOD<<"\n";
}
