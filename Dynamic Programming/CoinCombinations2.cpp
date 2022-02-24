#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll dp[1000005];
const int MOD = 1e9+7;



int main(){
	int n,x;	cin>>n>>x;
	vector<int> c(n);
	for(int i = 0; i<n; i++){
		cin>>c[i];
	}
	dp[0] = 1;
	
	/* 
	 * By switching the order of the loops
	 * we make sure that dp[i] only stores combinations
	 * that have used the first J coins
	 */
	for(int j = 0; j<n; j++){
		for(int i = 1; i<= x; i++){
			if(i-c[j] >= 0){
				dp[i]+=dp[i-c[j]];
				dp[i]%=MOD;
			}
		}
	}
	cout<< (dp[x]%MOD+MOD)%MOD;
}
