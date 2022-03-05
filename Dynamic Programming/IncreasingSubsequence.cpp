#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	ll n;
	cin>>n;
	vector<ll> x(n+1);
	for(int i = 0; i<n; i++) cin>>x[i];
	x[n] = 1e9+2;
	vector<ll> l;
	l.push_back(0);
	ll best = 0;
	ll inf = 1e9;
	for(int i = 0; i<=n; i++){
		auto it = lower_bound(l.begin(),l.end(),x[i]);
		if(it != l.begin()){
			it--;
			ll idx = it-l.begin();
			if( (ll) l.size()-1<=idx){
				l.push_back(inf);
			}
			l[idx+1] = min(l[idx+1], x[i]);
			best = max(best,idx+1);
		}
	}
	cout<<best-1<<"\n";
			
}
