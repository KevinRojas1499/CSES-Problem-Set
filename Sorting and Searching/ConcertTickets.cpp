#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,m,a;
	cin>>n>>m;
	multiset<ll> h;
	for(int i = 0; i<n; i++){
		cin>>a;
		h.insert(-a);
	}
	for(int i = 0; i<m; i++){
		cin>>a;
		multiset<ll>::iterator it = h.lower_bound(-a); 
		if(it == h.end()){
			cout<<"-1\n";
		}
		else{
			cout<< -*it<<"\n";
			h.erase(it);
		}
	}
}
