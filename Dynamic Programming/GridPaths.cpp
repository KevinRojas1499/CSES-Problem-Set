#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll MOD = 1e9+7;
ll n;

bool isIn(ll i, ll j){
	return 0<=i && i<n && 0<=j && j<n;
}

int main(){
	cin>>n;
	
	char mat[n][n];
	ll dp[n][n];
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin>>mat[i][j];
			dp[i][j] = 0;
		}
	}
	
	if(mat[0][0] != '*'){
		dp[0][0] = 1;
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(mat[i][j] == '*') continue;
			if(isIn(i-1,j) && mat[i-1][j] != '*'){
				dp[i][j]+=dp[i-1][j];
			}
			if(isIn(i,j-1) && mat[i][j-1] != '*'){
				dp[i][j]+=dp[i][j-1];
			}
			dp[i][j]%=MOD;
		}
	}
	cout<<(dp[n-1][n-1]%MOD+MOD)%MOD<<"\n";

}
