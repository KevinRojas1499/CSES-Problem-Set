#include <bits/stdc++.h>
#define ll long long 
using namespace std;

  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<pair<ll,ll>> p(n);
	for(int i= 0; i<n; i++){
		cin>>p[i].first;
		p[i].second = i;
	}
	sort(p.begin(),p.end());
	
	ll res = 1;
	for(int i = 1; i<n; i++){
		if(p[i].second<=p[i-1].second) res++;
	}
	cout<<res<<"\n";
			
}
