#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	set<ll> alive;
	for(int i = 1; i<=n; i++){
		alive.insert(i);
	}

	auto it = alive.find(2);
	if(it == alive.end()) it = alive.begin();
	while( alive.size()>0){
		cout<<*it<<" ";
		ll cur = *it;
		alive.erase(it);
		if(alive.size() == 0) break;
		it = alive.upper_bound(cur);
		if(it == alive.end()) it = alive.begin();
		it++;
		if(it == alive.end()){
			it = alive.begin();
		
		}
	}
	cout<<"\n";
}
