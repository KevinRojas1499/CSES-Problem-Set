#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;

ll mod(ll a, int m = MOD) {                            // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

ll modPow(ll b, int p, int m = MOD) {                  // assume 0 <= b < m
  if (p == 0) return 1;
  ll ans = modPow(b, p/2, m);                    // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

ll inv(ll a) {                                   // Fermat's little theorem
  return modPow(a, MOD-2, MOD);                      // modPow in Section 5.8
}                                                // that runs in O(log p)



int main(){
	ll n;
	cin>>n;
	ll maxx = n*(n+1)/2;
	if(maxx%2 != 0) cout<<"0\n";
	else{
		ll dp[maxx+5];
		memset(dp,0,sizeof dp);
		dp[0] = 1;
		for(int i = 1; i<=n; i++){
			for(int j = i*(i-1)/2; j>= 0; j--){
				if(i+j<maxx+1){
					dp[j+i]+= dp[j];
					dp[j+i]%=MOD;
				}
			 }
		 }
		 ll res = mod(dp[maxx/2]*inv(2));
		 
		 cout<<res<<"\n";
	 }
}
