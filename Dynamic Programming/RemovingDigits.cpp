#include <bits/stdc++.h>
#define ll long long 
 
using namespace std;
 
ll dp[1000005];
const int MOD = 1e9+7;
 
 
 
int main(){
	ll n;
	cin>>n;
	
	for(int i = 1; i<=n; i++){
		string s = to_string(i);
		dp[i] = 1e9;
		for(unsigned int j = 0; j<s.size(); j++){
			ll cur = s[j]-'0';
			if(i - cur>=0){
				dp[i] = min(dp[i],1+dp[i-cur]);
			}
		}
	}
	cout<<dp[n];
 
}
