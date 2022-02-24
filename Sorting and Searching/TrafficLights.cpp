#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,x,a;
	cin>>x>>n;
	set<ll> lights;
	lights.insert(0);
	lights.insert(x);
	multiset<ll> diff;
	diff.insert(x+1);
	for(int i = 0; i<n; i++){
		cin>>a;
		auto it = lights.lower_bound(a);
		ll end = *it;
		ll beg = *(--it);
		diff.erase(diff.lower_bound(end-beg));
		diff.insert(a-beg);
		diff.insert(end-a);
		auto itt = diff.end();
		lights.insert(a);
		itt--;
		cout<<*itt<<" ";
	}
	cout<<"\n";
	
	
	
}
